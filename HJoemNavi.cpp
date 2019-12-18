//******************************************************************************
// HJoemNavi
// Version 1.0 December, 2019
// Copyright 2019 Aleksandr Deviatkin
//
// Thanks to Ken Shirriff for the ideas and IRRemote library
// This file forked from Ken Shirriff's IRRemote library 
//******************************************************************************

// Defining IR_GLOBAL here allows us to declare the instantiation of global variables
#define HJ_GLOBAL
#	include "HJoemNavi.h"
#undef HJ_GLOBAL

#ifdef HAS_AVR_INTERRUPT_H
#include <avr/interrupt.h>
#endif


//+=============================================================================
// The match functions were (apparently) originally MACROs to improve code speed
//   (although this would have bloated the code) hence the names being CAPS
// A later release implemented debug output and so they needed to be converted
//   to functions.
// I tried to implement a dual-compile mode (DEBUG/non-DEBUG) but for some
//   reason, no matter what I did I could not get them to function as macros again.
// I have found a *lot* of bugs in the Arduino compiler over the last few weeks,
//   and I am currently assuming that one of these bugs is my problem.
// I may revisit this code at a later date and look at the assembler produced
//   in a hope of finding out what is going on, but for now they will remain as
//   functions even in non-DEBUG mode
//
int  MATCH (int measured,  int desired)
{
 	DBG_PRINT(F("Testing: "));
 	DBG_PRINT(TICKS_LOW(desired), DEC);
 	DBG_PRINT(F(" <= "));
 	DBG_PRINT(measured, DEC);
 	DBG_PRINT(F(" <= "));
 	DBG_PRINT(TICKS_HIGH(desired), DEC);

  bool passed = ((measured >= TICKS_LOW(desired)) && (measured <= TICKS_HIGH(desired)));
  if (passed)
    DBG_PRINTLN(F("?; passed"));
  else
    DBG_PRINTLN(F("?; FAILED")); 
 	return passed;
}

//+========================================================
// Due to sensor lag, when received, Marks tend to be 100us too long
//
int  MATCH_MARK (int measured_ticks,  int desired_us)
{
	DBG_PRINT(F("Testing mark (actual vs desired): "));
	DBG_PRINT(measured_ticks * USECPERTICK, DEC);
	DBG_PRINT(F("us vs "));
	DBG_PRINT(desired_us, DEC);
	DBG_PRINT("us"); 
	DBG_PRINT(": ");
	DBG_PRINT(TICKS_LOW(desired_us + MARK_EXCESS) * USECPERTICK, DEC);
	DBG_PRINT(F(" <= "));
	DBG_PRINT(measured_ticks * USECPERTICK, DEC);
	DBG_PRINT(F(" <= "));
	DBG_PRINT(TICKS_HIGH(desired_us + MARK_EXCESS) * USECPERTICK, DEC);

  bool passed = ((measured_ticks >= TICKS_LOW (desired_us + MARK_EXCESS))
                && (measured_ticks <= TICKS_HIGH(desired_us + MARK_EXCESS)));
  if (passed)
    DBG_PRINTLN(F("?; passed"));
  else
    DBG_PRINTLN(F("?; FAILED")); 
 	return passed;
}

//+========================================================
// Due to sensor lag, when received, Spaces tend to be 100us too short
//
int  MATCH_SPACE (int measured_ticks,  int desired_us)
{
	DBG_PRINT(F("Testing space (actual vs desired): "));
	DBG_PRINT(measured_ticks * USECPERTICK, DEC);
	DBG_PRINT(F("us vs "));
	DBG_PRINT(desired_us, DEC);
	DBG_PRINT("us"); 
	DBG_PRINT(": ");
	DBG_PRINT(TICKS_LOW(desired_us - MARK_EXCESS) * USECPERTICK, DEC);
	DBG_PRINT(F(" <= "));
	DBG_PRINT(measured_ticks * USECPERTICK, DEC);
	DBG_PRINT(F(" <= "));
	DBG_PRINT(TICKS_HIGH(desired_us - MARK_EXCESS) * USECPERTICK, DEC);

  bool passed = ((measured_ticks >= TICKS_LOW (desired_us - MARK_EXCESS))
                && (measured_ticks <= TICKS_HIGH(desired_us - MARK_EXCESS)));
  if (passed)
    DBG_PRINTLN(F("?; passed"));
  else
    DBG_PRINTLN(F("?; FAILED")); 
 	return passed;
}

//+=============================================================================
// Interrupt Service Routine - Fires every 50uS
// TIMER2 interrupt code to collect raw data.
// Widths of alternating SPACE, MARK are recorded in rawbuf.
// Recorded in ticks of 50uS [microseconds, 0.000050 seconds]
// 'rawlen' counts the number of entries recorded so far.
// First entry is the SPACE between transmissions.
// As soon as a the first [SPACE] entry gets long:
//   Ready is set; State switches to IDLE; Timing of SPACE continues.
// As soon as first MARK arrives:
//   Gap width is recorded; Ready is cleared; New logging starts
//
ISR (TIMER_INTR_NAME)
{
	TIMER_RESET;

	// Read if IR Receiver -> SPACE [xmt LED off] or a MARK [xmt LED on]
	// digitalRead() is very slow. Optimisation is possible, but makes the code unportable
	uint8_t  hjdata = (uint8_t)digitalRead(hjparams.recvpin);

	hjparams.timer++;  // One more 50uS tick
	if (hjparams.rawlen >= RAWBUF)  hjparams.rcvstate = STATE_OVERFLOW ;  // Buffer overflow

	switch(hjparams.rcvstate) {
		//......................................................................
		case STATE_IDLE: // In the middle of a gap
			if (hjdata == MARK) {
				if (hjparams.timer < GAP_TICKS)  {  // Not big enough to be a gap.
					hjparams.timer = 0;

				} else {
					// Gap just ended; Record duration; Start recording transmission
					hjparams.overflow                  = false;
					hjparams.rawlen                    = 0;
					hjparams.rawbuf[hjparams.rawlen++] = hjparams.timer;
					hjparams.timer                     = 0;
					hjparams.rcvstate                  = STATE_MARK;
				}
			}
			break;
		//......................................................................
		case STATE_MARK:  // Timing Mark
			if (hjdata == SPACE) {   // Mark ended; Record time
				hjparams.rawbuf[hjparams.rawlen++] = hjparams.timer;
				hjparams.timer                     = 0;
				hjparams.rcvstate                  = STATE_SPACE;
			}
			break;
		//......................................................................
		case STATE_SPACE:  // Timing Space
			if (hjdata == MARK) {  // Space just ended; Record time
				hjparams.rawbuf[hjparams.rawlen++] = hjparams.timer;
				hjparams.timer                     = 0;
				hjparams.rcvstate                  = STATE_MARK;

			} else if (hjparams.timer > GAP_TICKS) {  // Space
					// A long Space, indicates gap between codes
					// Flag the current code as ready for processing
					// Switch to STOP
					// Don't reset timer; keep counting Space width
					hjparams.rcvstate = STATE_STOP;
			}
			break;
		//......................................................................
		case STATE_STOP:  // Waiting; Measuring Gap
		 	if (hjdata == MARK)  hjparams.timer = 0 ;  // Reset gap timer
		 	break;
		//......................................................................
		case STATE_OVERFLOW:  // Flag up a read overflow; Stop the State Machine
			hjparams.overflow = true;
			hjparams.rcvstate = STATE_STOP;
		 	break;
	}

#ifdef BLINKLED
	// If requested, flash LED while receiving IR data
	if (hjparams.blinkflag) {
		if (hjdata == MARK)
			if (hjparams.blinkpin) digitalWrite(hjparams.blinkpin, HIGH); // Turn user defined pin LED on
				else BLINKLED_ON() ;   // if no user defined LED pin, turn default LED pin for the hardware on
		else if (hjparams.blinkpin) digitalWrite(hjparams.blinkpin, LOW); // Turn user defined pin LED on
				else BLINKLED_OFF() ;   // if no user defined LED pin, turn default LED pin for the hardware on
	}
#endif // BLINKLED
}
