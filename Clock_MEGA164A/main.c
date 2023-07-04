
#include <mega164a.h>
#include <delay.h>  
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>

#include "head.h"
#include "functions.h"


void main(void)
{

int8_t laststate_stopwatch_milisecond = 0;
int8_t laststate_stopwatch_second = 0;
int8_t laststate_stopwatch_minute = 0;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=(1<<CLKPCE);
CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=Out Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (1<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=0 Bit5=P Bit4=P Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (1<<PORTD5) | (1<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0A output: Disconnected
// OC0B output: Disconnected
TCCR0A=(0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0) | (0<<WGM01) | (0<<WGM00);
TCCR0B=(0<<WGM02) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0A=0x34;
OCR0B=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 312.500 kHz
// Mode: CTC top=OCR1A
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 10 ms
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: On
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x0C;
OCR1AL=0x34;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2A output: Disconnected
// OC2B output: Disconnected
ASSR=(0<<EXCLK) | (0<<AS2);
TCCR2A=(0<<COM2A1) | (0<<COM2A0) | (0<<COM2B1) | (0<<COM2B0) | (0<<WGM21) | (0<<WGM20);
TCCR2B=(0<<WGM22) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2A=0x00;
OCR2B=0x00;

// Timer/Counter 0 Interrupt(s) initialization
TIMSK0=(0<<OCIE0B) | (0<<OCIE0A) | (0<<TOIE0);

// Timer/Counter 1 Interrupt(s) initialization
TIMSK1=(0<<ICIE1) | (0<<OCIE1B) | (1<<OCIE1A) | (0<<TOIE1);

// Timer/Counter 2 Interrupt(s) initialization
TIMSK2=(0<<OCIE2B) | (0<<OCIE2A) | (0<<TOIE2);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
// Interrupt on any change on pins PCINT0-7: Off
// Interrupt on any change on pins PCINT8-15: Off
// Interrupt on any change on pins PCINT16-23: Off
// Interrupt on any change on pins PCINT24-31: Off
EICRA=(0<<ISC21) | (0<<ISC20) | (0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
EIMSK=(0<<INT2) | (0<<INT1) | (0<<INT0);
PCICR=(0<<PCIE3) | (0<<PCIE2) | (0<<PCIE1) | (0<<PCIE0);

// USART0 initialization
// USART0 disabled
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (0<<RXEN0) | (0<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);

// USART1 initialization
// USART1 disabled
UCSR1B=(0<<RXCIE1) | (0<<TXCIE1) | (0<<UDRIE1) | (0<<RXEN1) | (0<<TXEN1) | (0<<UCSZ12) | (0<<RXB81) | (0<<TXB81);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
ADCSRB=(0<<ACME);
// Digital input buffer on AIN0: On
// Digital input buffer on AIN1: On
DIDR1=(0<<AIN0D) | (0<<AIN1D);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Globally enable interrupts
#asm("sei")


DDRA = 0xff; //setare porturi A pe output
DDRC = 0xff; //setare porturi C pe output
DDRD = 0xff; //setare porturi D pe output

TIME_SET.milisecond = 0;
TIME_SET.second = 0;
TIME_SET.minute = 0;
TIME_SET.hour = 0;

CALENDAR_SET.year = 0;
CALENDAR_SET.month = 0;
CALENDAR_SET.day = 0;

buzzer = 0;

ALARM_is_set = 2;
ALARM.minute = 0;
ALARM.hour = 0;

    /////////////////////////////////////////////////////////////////////////////////////////////////////  SET CLOCK    
     
    /////////////////////////////////////////////  SET MINUTE
    while(ok_button == 0){
        if(select_button == 1){
            TIME_SET.minute++;
            if(TIME_SET.minute == 60){TIME_SET.minute = 0;}
            delay_ms(200);
        }
        print_digit(TIME_SET.minute,0,6);  
        print_digit(0,1,4); 
    }
    delay_ms(200); 
    wait_button_release();
     
    /////////////////////////////////////////////  SET HOUR         
    while(ok_button == 0){
        if(select_button == 1){
            TIME_SET.hour++;
            if(TIME_SET.hour == 24){TIME_SET.hour = 0;}
            delay_ms(200);
        }                               
        print_digit(TIME_SET.minute,0,6);  
        print_digit(TIME_SET.hour,1,4);  
    }
    delay_ms(200);  
    wait_button_release();

    
    /////////////////////////////////////////////////////////////////////////////////////////////////////  SET DAY / MONTH / YEAR   
    
    /////////////////////////////////////////////  SET YEAR  
    while(ok_button == 0){
        if(select_button == 1){
            CALENDAR_SET.year++;
            if(CALENDAR_SET.year == 2099){CALENDAR_SET.year = 2000;}
            delay_ms(200);
        }                               
        print_digit((CALENDAR_SET.year % 100),0,8);  
        print_digit(20,0,6);  
        print_digit(CALENDAR_SET.month,1,4); 
        print_digit(CALENDAR_SET.day,1,2);
    }
    delay_ms(200);
    wait_button_release();
 
    
    /////////////////////////////////////////////  SET MONTH  
    while(ok_button == 0){
        if(select_button == 1){
            CALENDAR_SET.month++;
            if(CALENDAR_SET.month == 13){CALENDAR_SET.month = 1;}
            delay_ms(200);
        }    
        print_digit((CALENDAR_SET.year % 100),0,8);  
        print_digit(20,0,6);                            
        print_digit(CALENDAR_SET.month,1,4);  
        print_digit(CALENDAR_SET.day,1,2); 
    }
    delay_ms(200);
    wait_button_release();
    
    /////////////////////////////////////////////  SET DAY  
    while(ok_button == 0){
        if(select_button == 1){
            if(month_check(CALENDAR_SET.day,CALENDAR_SET.month,CALENDAR_SET.year) == 1){
                CALENDAR_SET.day = 1;
            }else{
                CALENDAR_SET.day++;
            }    
            delay_ms(200);
        }
        print_digit((CALENDAR_SET.year % 100),0,8);  
        print_digit(20,0,6);                            
        print_digit(CALENDAR_SET.month,1,4);  
        print_digit(CALENDAR_SET.day,1,2);                                
    }
    delay_ms(200);
    wait_button_release(); 
    /////////////////////////////////////////////////////////////////
    TIME.milisecond = 0;
    TIME.second = TIME_SET.second;
    TIME.minute = TIME_SET.minute;
    TIME.hour = TIME_SET.hour; 
    
    CALENDAR.year = CALENDAR_SET.year;
    CALENDAR.month = CALENDAR_SET.month;
    CALENDAR.day = CALENDAR_SET.day;


    while (1){

    ////////////////////////////////////////////////////////////////////////////////////////////////////  CLOCK
        while(1){
            print_digit(TIME.second,0,6);
            print_digit(TIME.minute,1,4);
            print_digit(TIME.hour,1,2);  
            print_letter('H',0,8);
            if(ok_button == 1){
                delay_ms(100);
                break;
            }
        }
        wait_button_release();
        
    /////////////////////////////////////////////////////////////////////////////////////////////////////  CALENDAR
        while(1){ 
           int8_t year1 = CALENDAR.year % 100; 
           print_digit(year1,1,8);  
           print_digit(20,0,6);
           print_digit(CALENDAR.month,1,4);
           print_digit(CALENDAR.day,1,2);
           if(ok_button == 1){
                delay_ms(100);
                break;
            }
        }
        wait_button_release();  
      
       
    /////////////////////////////////////////////////////////////////////////////////////////////////////  STOPWATCH
        while(1){ 

            print_digit(0,1,6);
            print_digit(0,1,4);
            print_digit(0,1,2); 
            print_letter('S',0,8);
            
            if(select_button == 1){
                delay_ms(100);
                wait_button_release();
                STOPWATCH.milisecond = 0;
                STOPWATCH.second = 0;
                STOPWATCH.minute = 0;
                
                while(1){
                    laststate_stopwatch_milisecond = STOPWATCH.milisecond;
                    laststate_stopwatch_second = STOPWATCH.second;
                    laststate_stopwatch_minute = STOPWATCH.minute;
                             
                    print_digit(laststate_stopwatch_milisecond,1,6);
                    print_digit(laststate_stopwatch_second,1,4);
                    print_digit(laststate_stopwatch_minute,1,2); 
                    print_letter('S',0,8);
                        
                    if(select_button == 1){
                        delay_ms(100);                     
                        while(1){
                            print_digit(laststate_stopwatch_milisecond,1,6);
                            print_digit(laststate_stopwatch_second,1,4);
                            print_digit(laststate_stopwatch_minute,1,2); 
                            print_letter('S',0,8);  
                            if(select_button == 1){
                                delay_ms(100);
                                wait_button_release();
                                break;
                            }   
                        }
                        wait_button_release();
                        break;
                    }
                
                }

            }
            
            if(ok_button == 1){
                delay_ms(100);
                break;
            }
            
        }
        wait_button_release();
        
    /////////////////////////////////////////////////////////////////////////////////////////////////////////  ALARM    
        while(1){
            switch (ALARM_is_set)
               {                                     
               case 0: ////////////////////////////////////////////Alarma nu este setata, dar urmeaza sa fie
                    while(ok_button == 0){
                        if(select_button == 1){
                            ALARM.minute++;
                            if(ALARM.minute == 60){ALARM.minute = 0;}
                            delay_ms(100);
                        }
                        print_digit(ALARM.minute,0,6);  
                        print_digit(0,1,4);
                        print_letter('A',0,8);  
                    }
                    delay_ms(100);
                    wait_button_release();
                       
                            
                    while(ok_button == 0){
                        if(select_button == 1){
                            ALARM.hour++;
                            if(ALARM.hour == 24){ALARM.hour = 0;}
                            delay_ms(100);
                        }
                        print_digit(ALARM.hour,1,4);
                        print_digit(ALARM.minute,0,6);
                        print_letter('A',0,8);    
                    }
                    delay_ms(100);
                    wait_button_release();
                    ALARM_is_set = 1;
               break; 
               
               case 1: /////////////////////////////////////////////Alarma este setata, se asteapta declansarea ei
                    print_digit(ALARM.hour,1,4);
                    print_digit(ALARM.minute,0,6);
                    print_letter('A',0,8); 
                    print_letter('S',0,1); 
               break;  
               
               case 2: /////////////////////////////////////////////Alarma nu este setata, si nu se vrea setarea ei
                    print_digit(ALARM.hour,1,4);
                    print_digit(ALARM.minute,0,6);
                    print_letter('A',0,8);
                    if(select_button == 1){
                        delay_ms(100);
                        wait_button_release();
                        ALARM_is_set = 0;
                        continue;
                    } 
               break;
               }    
                                                    
                                                                                  
            if(ok_button == 1){
                delay_ms(100);
                wait_button_release();
                break;
            }
                                             
        } 
        wait_button_release();
        
    ///////////////////////////////////////////////////////////////////////////////////////////////////////  END WHILE   
    }
}
