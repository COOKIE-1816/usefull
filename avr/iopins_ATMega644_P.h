#ifndef _IO_PINS_H_
#define _IO_PINS_H_

#include <avr/io.h>

#ifndef __AVR_ATmega644P__
#ifndef __AVR_ATmega644__
	#pragma warning "This header is only for use with ATMega 644. Pinout information may be inaccurate."
#endif
#endif

#define IO_PIN_COUNT_TOTAL		32	// Total pins count
#define IO_PIN_COUNT_DIGITAL	24	// Digital pins count
#define IO_PIN_COUNT_ANALOG		8	// Analog pins count

#define __PORT	0
#define __DDR	1
#define __PIN	2

/*	'pin' type
	============
	Specifies an Input/Output pin.
	
	array:
		0:	PORT
		1:	DDR
		2:	PIN						*/
typedef volatile uint8_t* pin[3];

#define PIN00	{ &PORTB,	&DDRB,	&PB0 }
#define PIN01	{ &PORTB,	&DDRB,	&PB1 }
#define PIN02	{ &PORTB,	&DDRB,	&PB2 }
#define PIN03	{ &PORTB,	&DDRB,	&PB3 }
#define PIN04	{ &PORTB,	&DDRB,	&PB4 }
#define PIN05	{ &PORTB,	&DDRB,	&PB5 }
#define PIN06	{ &PORTB,	&DDRB,	&PB5 }
#define PIN07	{ &PORTB,	&DDRB,	&PB6 }

#define PIN08	{ &PORTD,	&DDRD,	&PD0 }
#define PIN09	{ &PORTD,	&DDRD,	&PD1 }
#define PIN10	{ &PORTD,	&DDRD,	&PD2 }
#define PIN11	{ &PORTD,	&DDRD,	&PD3 }
#define PIN12	{ &PORTD,	&DDRD,	&PD4 }
#define PIN13	{ &PORTD,	&DDRD,	&PD5 }
#define PIN14	{ &PORTD,	&DDRD,	&PD6 }
#define PIN15	{ &PORTD,	&DDRD,	&PD7 }

#define PIN16	{ &PORTC,	&DDRC,	&PC0 }
#define PIN17	{ &PORTC,	&DDRC,	&PC1 }
#define PIN18	{ &PORTC,	&DDRC,	&PC2 }
#define PIN19	{ &PORTC,	&DDRC,	&PC3 }
#define PIN20	{ &PORTC,	&DDRC,	&PC4 }
#define PIN21	{ &PORTC,	&DDRC,	&PC5 }
#define PIN22	{ &PORTC,	&DDRC,	&PC6 }
#define PIN23	{ &PORTC,	&DDRC,	&PC7 }

#define PIN24	{ &PORTA,	&DDRA,	&PA0 }
#define PIN25	{ &PORTA,	&DDRA,	&PA1 }
#define PIN26	{ &PORTA,	&DDRA,	&PA2 }
#define PIN27	{ &PORTA,	&DDRA,	&PA3 }
#define PIN28	{ &PORTA,	&DDRA,	&PA4 }
#define PIN29	{ &PORTA,	&DDRA,	&PA5 }
#define PIN30	{ &PORTA,	&DDRA,	&PA6 }
#define PIN31	{ &PORTA,	&DDRA,	&PA7 }

#define ANALOG0	PIN24
#define ANALOG1	PIN25
#define ANALOG2	PIN26
#define ANALOG3	PIN27
#define ANALOG4	PIN28
#define ANALOG5	PIN29
#define ANALOG6	PIN30
#define ANALOG7	PIN31
 
#define GET_PIN(PIN)			( PIN[__PIN ] )
#define GET_DDR(PIN)			( PIN[__DDR ] )
#define GET_PORT(PIN)			( PIN[__PORT] )

#ifndef _BITS_H_
#define _BITS_H_
	#define SET_BIT(   PORT, BIT)	( *PORT |=	 (1 << BIT)	)
	#define UNSET_BIT( PORT, BIT)	( *PORT &=	~(1 << BIT)	)
	#define TOGGLE_BIT(PORT, BIT)	( *PORT ^=   (1 << BIT) )
	#define GET_BIT(   PORT, BIT)	( (*PORT >> BIT) & 0x01	)
#endif

#define DIGITAL_WRITE_LOW(PIN)	( UNSET_BIT( GET_PORT(PIN), GET_PIN(PIN)) )
#define DIGITAL_WRITE_HIGH(PIN)	( SET_BIT(	 GET_PORT(PIN), GET_PIN(PIN)) )

#define DIGITAL_READ(PIN)		( GET_BIT (	 GET_PORT(PIN),	GET_PIN(PIN)) )
#define DIGITAL_WRITE(PIN, VAL)	( VAL ?									\
								( DIGITAL_WRITE_HIGH(GET_PIN(PIN) )) :	\
								( DIGITAL_WRITE_LOW( GET_PIN(PIN) ))
#define DIGITAL_SWITCH(PIN)		( TOGGLE_BIT(GET_PORT(PIN), GET_PIN(PIN)) )

#define LOW		0
#define HIGH	1

#define DIGITAL_SET_MODE_OUTPUT(PIN)	( UNSET_BIT(GET_DDR(PIN), PIN) )
#define DIGITAL_SET_MODE_INPUT( PIN)	( SET_BIT(	GET_DDR(PIN), PIN) )
#define DIGITAL_SET_MODE(PIN, MODE)		( MODE ?							\
										( DIGITAL_SET_MODE_OUTPUT(PIN)) :	\
										( DIGITAL_SET_MODE_INPUT( PIN)) )

#define IO_MODE_OUT	1
#define IO_MODE_IN	0

#endif
