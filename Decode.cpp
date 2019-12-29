#include "HJoemNavi.h"

//+=============================================================================
// Decodes the received IR message
// Returns 0 if no data ready, 1 if data ready.
// Results of decoding are stored in results
//
int  HJrecv::decode (decode_results *results)
{
	results->rawbuf   = hjparams.rawbuf;
	results->rawlen   = hjparams.rawlen;
	results->bits = 0;
	results->value = 0;

	results->overflow = hjparams.overflow;

	if (hjparams.rcvstate != STATE_STOP)  return false ;

	for (int i = 1;  i < results->rawlen;  i++) {
		int lvalue =  (results->rawbuf[i] / SYMBOL_LEN);	// number jf bits
		while(lvalue) {
			results->value <<= 1;							// only 32 bits
			if (i & 1) {	// MARK
				results->value += 1;
			}
			lvalue--;
			results->bits++;
		}
	}
	if (results->bits > 32 && results->value > 0)  return true ;

	// Throw away and start over
	resume();
	return false;
}

//+=============================================================================
HJrecv::HJrecv (int recvpin)
{
	hjparams.recvpin = recvpin;
	hjparams.blinkflag = 0;
}

HJrecv::HJrecv (int recvpin, int blinkpin)
{
	hjparams.recvpin = recvpin;
	hjparams.blinkpin = blinkpin;
	pinMode(blinkpin, OUTPUT);
	hjparams.blinkflag = 0;
}



//+=============================================================================
// initialization
//
#ifdef USE_DEFAULT_ENABLE_IR_IN
void  HJrecv::enableHJIn ( )
{
// Interrupt Service Routine - Fires every 50uS
	cli();
	// Setup pulse clock timer interrupt
	// Prescale /8 (16M/8 = 0.5 microseconds per tick)
	// Therefore, the timer interval can range from 0.5 to 128 microseconds
	// Depending on the reset value (255 to 0)
	TIMER_CONFIG_NORMAL();

	// Timer2 Overflow Interrupt Enable
	TIMER_ENABLE_INTR;

	TIMER_RESET;

	sei();  // enable interrupts

	// Initialize state machine variables
	hjparams.rcvstate = STATE_IDLE;
	hjparams.rawlen = 0;

	// Set pin modes
	pinMode(hjparams.recvpin, INPUT);
}
#endif // USE_DEFAULT_ENABLE_IR_IN

//+=============================================================================
// Enable/disable blinking of pin 13 on IR processing
//
void  HJrecv::blink13 (int blinkflag)
{
#ifdef BLINKLED
	hjparams.blinkflag = blinkflag;
	if (blinkflag)  pinMode(BLINKLED, OUTPUT) ;
#endif
}


//+=============================================================================
// Return if receiving new IR signals
//
bool  HJrecv::isIdle ( )
{
 return (hjparams.rcvstate == STATE_IDLE || hjparams.rcvstate == STATE_STOP) ? true : false;
}
//+=============================================================================
// Restart the ISR state machine
//
void  HJrecv::resume ( )
{
	hjparams.rcvstate = STATE_IDLE;
	hjparams.rawlen = 0;
}
/*
//+=============================================================================
// hashdecode - decode an arbitrary IR code.
// Instead of decoding using a standard encoding scheme
// (e.g. Sony, NEC, RC5), the code is hashed to a 32-bit value.
//
// The algorithm: look at the sequence of MARK signals, and see if each one
// is shorter (0), the same length (1), or longer (2) than the previous.
// Do the same with the SPACE signals.  Hash the resulting sequence of 0's,
// 1's, and 2's to a 32-bit value.  This will give a unique value for each
// different code (probably), for most code systems.
//
// http://arcfn.com/2010/01/using-arbitrary-remotes-with-arduino.html
//
// Compare two tick values, returning 0 if newval is shorter,
// 1 if newval is equal, and 2 if newval is longer
// Use a tolerance of 20%
//
int  HJrecv::compare (unsigned int oldval,  unsigned int newval)
{
	if      (newval < oldval * .8)  return 0 ;
	else if (oldval < newval * .8)  return 2 ;
	else                            return 1 ;
}

//+=============================================================================
// Use FNV hash algorithm: http://isthe.com/chongo/tech/comp/fnv/#FNV-param
// Converts the raw code values into a 32-bit hash code.
// Hopefully this code is unique for each button.
// This isn't a "real" decoding, just an arbitrary value.
//
#define FNV_PRIME_32 16777619
#define FNV_BASIS_32 2166136261

long  HJrecv::decodeHash (decode_results *results)
{
	long  hash = FNV_BASIS_32;

	// Require at least 6 samples to prevent triggering on noise
	if (results->rawlen < 6)  return false ;

	for (int i = 1;  (i + 2) < results->rawlen;  i++) {
		int value =  compare(results->rawbuf[i], results->rawbuf[i+2]);
		// Add value into the hash
		hash = (hash * FNV_PRIME_32) ^ value;
	}

	results->value       = hash;
	results->bits        = 32;
	results->decode_type = UNKNOWN;

	return true;
}
*/
