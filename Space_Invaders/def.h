#define DEF_H

#define SW_VERSION       

#ifndef NULL
#define NULL  0
#endif

#define TRUE    1
#define FALSE    0 
#define DUMMY    0

#define wdogtrig()            #asm("wdr") // call often if Watchdog timer enabled
#define CR                0x0D
#define LF                0x0A  


//#define LED1 PORTD.6        // PORTx is used for output
#define up PINB.3          
#define down PINB.2          
#define right PINB.1
#define left PINB.4 
#define select PINB.0

int i = 0;
int j = 0;
int k = 0;
int l = 0;

typedef unsigned char byte;
int sel = 1;
int highscore = 0;
//int cop;
int score = 0;
int life = 3;
int attack1 = 1;
int attack2 = 1;
int game[3][20] =    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};  
                      
int gameb[3][20] =    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};
int sw = 0;
int sw2 = 0;

