#include <mega164a.h>
#include <stdint.h>

#define SW_VERSION        13   /* i.e. major.minor software version nbr. */

#define TRUE    1
#define true    1
#define FALSE    0 
#define false   0

#define wdogtrig()      #asm("wdr") // call often if Watchdog timer enabled

//Segmentele unei cifre
#define A PORTA.0
#define B PORTA.1
#define C PORTA.2
#define D PORTA.3
#define E PORTA.4
#define F PORTA.5
#define G PORTA.6
#define pct PORTA.7

//Cele 8 cifre 
#define seg1 PORTC.0
#define seg2 PORTC.1
#define seg3 PORTC.2
#define seg4 PORTC.3
#define seg5 PORTC.4
#define seg6 PORTC.5
#define seg7 PORTC.6
#define seg8 PORTC.7  

#define buzzer PORTD.7

#define select_button PINB.1
#define ok_button PINB.0  


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// structura time

struct time{

    int8_t milisecond;
    int8_t second;
    int8_t minute;
    int8_t hour;
}TIME, ALARM, STOPWATCH, TIME_SET;


// structura calendar

struct calendar{
    int8_t day;
    int8_t month;
    int16_t year;  
    
}CALENDAR, CALENDAR_SET;


