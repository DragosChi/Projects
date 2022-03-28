/*
 * Chiritoiu Dragos
 * 
 * Components:
 *      - Arduino MEGA 2560
 *      - LCD 1602 blue + I2C Adadter (SDA and SCL  pins)
 *      - 2x push buttons (pin 2 and pin 3) + 2x 10k resistors 
 *      - relay module 5V (pin 4)
 */


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

const int buttonPin1 = 2;     // the number of the pushbutton pin 1
const int buttonPin2 = 3;    // the number of the pushbutton pin 2
const int relay = 4;    // the number of the pushbutton pin 2

int buttonState1 = 0;         
int buttonState2 = 0;
int lastbuttonState1 = 0;         
int lastbuttonState2 = 0; 

int check_1;
int check_2;  
int code=0;
int number=0;
int PIN=1234;    // choose PIN

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  
  code = 0;
  number = 0;
  lcd.init();
  lcd.backlight();
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  digitalWrite(relay,HIGH);
  
  while(1){
      check1();
      check2();
      if( check_1 == 0 && check_2 == 0){
        lcd.setCursor(3,0);
        lcd.print("  HELLO!");
        lcd.setCursor(0,1);
        lcd.print("Press any button");
      }else{
        delay(100);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Button 1->SELECT");
        lcd.setCursor(0,1);
        lcd.print("Button 2->OK");
        delay(2500);
        break;
      }
  }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("123456789 ->");
    lcd.setCursor(number,1);
    lcd.print("^");
  while(code < 1000){
      check1();
      check2();
      if(check_1 == 1){
        number++;
        if(number == 9){ 
            number = 0; 
          }
        lcd.setCursor(0,1);
        lcd.print("                   ");
        lcd.setCursor(number,1);
        lcd.print("^");
      }
      if(check_2 == 1){
        code=code*10+number+1;
        lcd.setCursor(12,0);
        lcd.print(code);
      }
  }
  delay(1000);
   if(code == PIN) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Correct PIN");
    lcd.setCursor(0,1);
    lcd.print(" ACCESS ALLOWED");
    digitalWrite(relay,LOW);
    delay(4000);
   }else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   Wrong PIN");
    lcd.setCursor(0,1);
    lcd.print(" ACCESS DENNIED ");
    delay(4000);
   }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////

void check1(){
  buttonState1 = digitalRead(buttonPin1);
  if(buttonState1 != lastbuttonState1){
    check_1 = 1;
  }else{
    check_1 = 0;
  }
  delay(70);
}

void check2(){
  buttonState2 = digitalRead(buttonPin2);
  if(buttonState2 != lastbuttonState2){
    check_2 = 1;
  }else{
    check_2 = 0;
  }
  delay(70);
}
