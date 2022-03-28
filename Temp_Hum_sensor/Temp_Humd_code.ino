//Chiritoiu Dragos
//Compatible with Arduino Mega2560

#include <SPI.h>
#include <SD.h>
#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// ENCODER
int encoderPinA = 8; // CLK pin
int encoderPinB = 9; // DT pin
int encoderBtn = 10; // SW pin
int encoderPinA_prev;
int encoderPinA_value;

// SENZOR
int pinDHT11 = 2; //out DHT11
SimpleDHT11 dht11(pinDHT11);

// SD
File myFile;
LiquidCrystal_I2C lcd(0x27,20,4);

//TIME
int count;
int hour = 0;
int minute = 0;
//////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin (9600);
  pinMode (encoderPinA, INPUT);
  pinMode (encoderPinB, INPUT);
  pinMode(encoderBtn, INPUT_PULLUP);
  encoderPinA_prev = digitalRead(encoderPinA);
  
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    lcd.init();
    lcd.backlight();          
    lcd.setCursor(0,0);
    lcd.print("SD ERROR");
    while (1);
  }
  Serial.println("initialization done.");    
  lcd.init();
  lcd.backlight();    
  lcd.setCursor(0,0);
  lcd.print("SD GOOD");
  myFile = SD.open("temp_hum", FILE_WRITE);
  myFile.print("START");
  myFile.print("\n");
  delay(2000);
}

bool check_push(){  
  if (digitalRead(encoderBtn) == LOW){
      return true;
    }else{
      return false;
    }
  }

void loop() {
  lcd.init();          
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("SET TIME");
  lcd.setCursor(2,1);
  lcd.print(":00");
  while(!check_push()){
  encoderPinA_value = digitalRead(encoderPinA);
  if (encoderPinA_value != encoderPinA_prev) {
    if(digitalRead(encoderPinB) != encoderPinA_value) {
        hour++;
      }else{
        hour--;
      }
  }
  encoderPinA_prev = encoderPinA_value;
  if (hour == 24){ 
      hour = 0;
    }else{
      if( hour == -1) hour = 23;
  }

  if(hour < 10){
    lcd.setCursor(0,1);
    lcd.print("0");
    lcd.setCursor(1,1);
    lcd.print(hour);
    continue;
  }
  lcd.setCursor(0,1);
  lcd.print(hour);
  }
  delay(400);

  
  while(!check_push()){
      encoderPinA_value = digitalRead(encoderPinA);
      if (encoderPinA_value != encoderPinA_prev) {
        if (digitalRead(encoderPinB) != encoderPinA_value) {
            minute++;
          }else {
            minute--;
          }
      } 
      encoderPinA_prev = encoderPinA_value;
      
      lcd.setCursor(2,1);
      lcd.print(":");
      if( minute == 60) minute = 0;
      if( minute == -1) minute = 59;
      if( minute < 10){
        lcd.setCursor(3,1);
        lcd.print("0");
        lcd.setCursor(4,1);
        lcd.print(minute);
        continue;
      }
      lcd.setCursor(3,1);
      lcd.print(minute);
  }
  delay(400);
  /////////////////////////////////////////////////////////////////////////////////////

  while(!check_push()){

    lcd.init();          
    lcd.setCursor(0,0);
    lcd.print("TIME ");
  
    if( hour < 10){
        lcd.setCursor(5,0);
        lcd.print("0");
        myFile.print("0");
        lcd.setCursor(6,0);
        lcd.print(hour);
        myFile.print(hour);
      }else{
        lcd.setCursor(5,0);
        lcd.print(hour);
        myFile.print(hour);
    }
  
    lcd.setCursor(7,0);
    lcd.print(":");
    myFile.print(":");
    
    if( minute < 10){
        lcd.setCursor(8,0);
        lcd.print("0");
        myFile.print("0");
        lcd.setCursor(9,0);
        lcd.print(minute);
        myFile.print(minute);
      }else{
        lcd.setCursor(8,0);
        lcd.print(minute);
        myFile.print(minute);
    }
    
    byte temperature = 0;
    byte humidity = 0;
    
    int err = SimpleDHTErrSuccess;
    if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
        Serial.print("Read DHT11 failed, err=");
        Serial.print(err);
      }else{
        Serial.print((int)temperature); Serial.print(" *C, "); 
        Serial.print((int)humidity); Serial.println(" H");
    }
  
    lcd.setCursor(0,1);
    lcd.print("TEMP ");
    lcd.print((int)temperature);
    lcd.print("C  HUM ");
    lcd.print((int)humidity);

    myFile.print("\t");
    myFile.print((int)temperature);
    myFile.print("\t");
    myFile.print((int)humidity);
    myFile.print("\n");
    
    delay(58980);//delay(60000);
    minute++;
    if(minute == 60){
      minute = minute - 60;
      hour++;
      if(hour == 24) hour = 0;
    }
  }
  
  myFile.close();
  lcd.init();          
  lcd.setCursor(5,0);
  lcd.print("DONE");
  lcd.setCursor(0,1);
  lcd.print(" SAFE TO REMOVE");
  
  delay(100000);
}
