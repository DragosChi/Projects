/*******************************************************
This program was created by the CodeWizardAVR V3.48b 
Automatic Program Generator
� Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro

Project : 
Version : 
Date    : 20-May-2022
Author  : 
Company : 
Comments: 


Chip type               : ATmega164A
Program type            : Application
AVR Core Clock frequency: 20.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

// I/O Registers definitions
#include <mega164a.h>
#include <alcd.h>
#include <stdio.h>
#include <delay.h>  
#include <string.h> 
#include <stdlib.h>
#include "def.h"
#include "char.h"


/* function used to define user characters */
void define_char(byte flash *pc,byte char_code)
{      
byte i,a;
a=(char_code<<3) | 0x40;
for (i=0; i<8; i++) lcd_write_byte(a++,*pc++);
}


void move_rocket(){
    if(left == 1 & game[2][0] == 0){
        delay_ms(50);
        for(i = 0; i < 19; i++){  game[2][i] = game[2][i+1];  };// move left
            game[2][19] = 0; 
    };
    if(right == 1 & game[2][19] == 0){
        delay_ms(50);
        for(i = 19; i > 0; i--){  game[2][i] = game[2][i-1];  };// move right
            game[2][0] = 0;
    };
}


void move_monsters(){
    if(game[0][0] == 1) { sw = 1; } else { if(game[0][19] == 1) sw = 0; };
    if(sw == 0) {
            for(i = 0; i < 19; i++){  game[0][i] = game[0][i+1];  };// move left
            game[0][19] = 0; 
        }else{
            for(i = 19; i > 0; i--){  game[0][i] = game[0][i-1];  };// move right
            game[0][0] = 0;   
        };
};


void print_all(int type){
    lcd_gotoxy(0,1);////////////////////monsters
    for(i = 0; i < 20; i++){  
        if(game[0][i] == 0){
            lcd_putsf(" ");
        }else{
            if(type == 0){
                lcd_putchar(1);
            }else{
                lcd_putchar(2);  
            };
        }; 
    };
    
    lcd_gotoxy(0,2);//////////////////////bullet
    for(i = 0; i < 20; i++){  
        if(game[1][i] == 0){
            lcd_putsf(" ");
        }else{
            if(game[1][i] == 1){
                lcd_putchar(5);
            }else{ 
                if(game[1][i] == 2){
                    lcd_putchar(6);
                    }else{
                        lcd_putchar(7);
                    };
            };
             
          
        }; 
    };

    lcd_gotoxy(0,3);//////////////////////////////rocket
    for(i = 0; i < 20; i++){  
        if(game[2][i] == 1){
            lcd_putchar(3);
        }else{
            if(game[2][i] == 2){
                lcd_putchar(4);
            }else{
                lcd_putsf(" ");
            };   
        }; 
    };

    
};  

void print_int(int cop){

    int a;             
    a = (cop/1000) + 48;
    cop = cop % 1000;
    lcd_putchar(a);
             
    a = (cop/100) + 48;
    cop = cop % 100;
    lcd_putchar(a);
             
    a = (cop/10) + 48;
    cop = cop % 10;
    lcd_putchar(a); 
             
    a = cop + 48;
    lcd_putchar(a);

}

void main(void)  
{
// Declare your local variables here

// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=(1<<CLKPCE);
CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0A output: Disconnected
// OC0B output: Disconnected
TCCR0A=(0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0) | (0<<WGM01) | (0<<WGM00);
TCCR0B=(0<<WGM02) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0A=0x00;
OCR0B=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
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
TIMSK1=(0<<ICIE1) | (0<<OCIE1B) | (0<<OCIE1A) | (0<<TOIE1);

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    lcd_init(20);
    // 126 sageata
    // 255 casuta plina
    define_char(heart,0);
    define_char(monster1,1); 
    define_char(monster0,2);
    define_char(rocket0,3);
    define_char(fire1,4);
    define_char(fire2,5);
    define_char(fire3,6);
    define_char(fire4,7);

    lcd_gotoxy(3,1);
    lcd_putsf("Space Invaders");
    delay_ms(100);
      
    lcd_gotoxy(2,3);
    lcd_putsf("_______________");
    
    delay_ms(100);
    
    lcd_gotoxy(2,3);
    for(i = 0; i < 16; i++) {
        lcd_putchar(255);
        delay_ms(200);
    };  
    lcd_clear();  
    
 
    while (1){   //  menu
        lcd_clear();  
              
        lcd_gotoxy(7,0);
        lcd_putsf("MENU"); 
            
        lcd_gotoxy(1,1);
        lcd_putsf("New game");   
            
        lcd_gotoxy(1,2);
        lcd_putsf("High score"); 
            
        lcd_gotoxy(1,3);
        lcd_putsf("Credits"); 
        
        sel = 1;
        sw = 0;
           
        while(sw == 0){
         
            if(up == 1){  
               delay_ms(100);
                sel--;
            };
            
            if(down == 1){  
                delay_ms(100); 
                sel++;
            };
             

            if(sel > 3) sel = 1; 
            if(sel < 1) sel = 3;
            
            lcd_gotoxy(0,sel);
            lcd_putchar(126);
            
            delay_ms(50);
            
            lcd_gotoxy(0,1);
            lcd_putsf(" ");
            
            lcd_gotoxy(0,2);
            lcd_putsf(" ");
            
            lcd_gotoxy(0,3);
            lcd_putsf(" ");
            
            lcd_gotoxy(0,sel);
            lcd_putchar(126);
            
            if (select == 1){
                delay_ms(100); 
                sw = 1;   
            };   
 
        };
        
        sw = 0;
        lcd_clear();
        
        if(sel == 1){
            delay_ms(50);
            //select = 1;
           for(i=0 ; i < 3 ; i++){
                for(j=0 ; j < 20 ; j++){
                    game[i][j]=gameb[i][j];
                };
            };
           life = 3;
           score = 0;
           attack1 = 1;   
           attack2 = 1;  
           lcd_gotoxy(0,0);
           lcd_putsf("SCORE 0000");
           
           lcd_gotoxy(16,0);
           lcd_putchar(0);
           lcd_putchar(0);
           lcd_putchar(0);
           
           while(life > 0){
                
                
                if(select == 1){
                    delay_ms(20);
                    for(j = 0 ; j < 20 ; j++){if(game[2][j] == 1){break;}}
                    
                    game[2][j] = 2;
                    print_all(sw2);
                    delay_ms(166);
                    
                    game[2][j] = 1;
                    print_all(sw2);
                    delay_ms(166);
                    
                    move_rocket();
                    game[1][j] = 1;
                    print_all(sw2);
                    delay_ms(166);
                    
                    move_rocket();
                    game[1][j] = 2;
                    print_all(sw2);
                    delay_ms(166);
                                 
                    move_rocket();
                    game[1][j] = 3;
                    print_all(sw2);
                    delay_ms(166);
                   
                    move_rocket();
                    game[1][j] = 0;
                    print_all(sw2);
                    delay_ms(166);
                    
                    if(game[0][j] == 1) {

                        game[0][j] = 0; score = score + 100;
                        lcd_gotoxy(6,0);
                        print_int(score);
                        if(score == 1200){break;};
                    };
                    move_monsters();
                    if(sw2 == 1){ sw2 = 0; } else { sw2 = 1; };
                    
                    }else{
                        for(k = 0 ; k < 20 & attack1 != 0 ; k++){      
                            if(game[0][k] == 1) {attack1 = (rand()%(12-(score/100)));};
                        };  
                        
                        for(l = 0 ; l < 20 & attack2 != 0 ; l++){      
                            if(game[0][l] == 1) {attack2 = (rand()%(12-(score/100)));};
                        };
                        if(l == 20){l = 100;};
                        if(k == 20){k = 100;};
                        k--;
                        l--;
                        
                        move_rocket();
                        game[1][k] = 3; 
                        game[1][l] = 3;
                        print_all(sw2);
                        delay_ms(250);

                        move_rocket();
                        game[1][k] = 2;
                        game[1][l] = 2;
                        print_all(sw2);
                        delay_ms(250);
                        
                        move_rocket();
                        game[1][k] = 1;
                        game[1][l] = 1;
                        print_all(sw2);
                        delay_ms(250);
                        
                        move_rocket();
                        game[1][k] = 0;
                        game[1][l] = 0;
                        print_all(sw2);
                        delay_ms(250);
           
                        if(game[2][k] == 1) { //daca racheta este lovita
                            life--;
                            if(life == 2 ){ 
                                lcd_gotoxy(18,0); 
                                lcd_putsf(" ");
                            }else{if( life == 1){
                                lcd_gotoxy(17,0); 
                                lcd_putsf(" ");
                                }else{
                                    if(highscore < score){ highscore = score;};
                                    break;
                                };
                            };
                        };
                        
                        if(game[2][l] == 1) { //daca racheta este lovita
                            life--;
                            if(life == 2 ){ 
                                lcd_gotoxy(18,0); 
                                lcd_putsf(" ");
                            }else{if( life == 1){
                                lcd_gotoxy(17,0); 
                                lcd_putsf(" ");
                                }else{
                                    if(highscore < score){ highscore = score;};
                                    break;
                                };
                            };
                        };
                        
                         
                        attack1 = 1;
                        attack2 = 1;
                        move_monsters();
                        if(sw2){ sw2 = 0; } else { sw2 = 1;};  
                }; 
           };
           
           lcd_clear();
           if(score == 1200){
                   lcd_gotoxy(2,0);
                   lcd_putsf("G A M E  O V E R");
                   delay_ms(1000);
                   
                   lcd_gotoxy(6,1);
                   lcd_putsf("YOU WIN");
                   delay_ms(1000);
                   
                   lcd_gotoxy(5,3);
                   lcd_putsf("SCORE");        
                   lcd_gotoxy(11,3);
                   print_int(score);
                   
                   delay_ms(5000);
               }else{
                   lcd_gotoxy(2,0);
                   lcd_putsf("G A M E  O V E R");
                   delay_ms(1000);
                   
                   lcd_gotoxy(6,1);
                   lcd_putsf("YOU LOSE");
                   delay_ms(1000);
                   
                   lcd_gotoxy(5,3);
                   lcd_putsf("SCORE");         
                   lcd_gotoxy(11,3);
                   print_int(score);
                   
                   delay_ms(5000);
                   };
                  
        };
        
        if(sel == 2){
            delay_ms(30);
            
            lcd_gotoxy(2,1); 
            lcd_putsf("-> HIGH-SCORE <-");
            lcd_gotoxy(8,2);
            print_int(highscore);
            delay_ms(6000);
        };
               
        if(sel == 3){
            lcd_gotoxy(2,1);
            lcd_putsf("CHIRITOIU DRAGOS");
            delay_ms(6000);
        };
    }; 
        
};



