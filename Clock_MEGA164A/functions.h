//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int8_t ALARM_is_set = 0;
int32_t buzzer_is_on = 0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
functie de printat numere cu 2 cifre
  Primeste 3 valori,
        - numarul propriu zis
        - 1 sau 0 daca sa pun sau nu punct la inceput  de numar
        - numarul carcterului la care inceapa sa puna numarul respectiv
*/   

void print_digit(int8_t sel1, int8_t dot, int8_t digit_sel){

    int8_t sel = sel1;
    int8_t i;    
    
    for(i = 0; i < 2; i++){
    
        sel = sel % 10;    
        switch (sel){
               case 0: A = 1; B = 1; C = 1; D = 1; E = 1; F = 1; G = 0; pct = dot; break;  // digit 0
               case 1: A = 0; B = 1; C = 1; D = 0; E = 0; F = 0; G = 0; pct = dot; break;  // digit 1
               case 2: A = 1; B = 1; C = 0; D = 1; E = 1; F = 0; G = 1; pct = dot; break;  // digit 2
               case 3: A = 1; B = 1; C = 1; D = 1; E = 0; F = 0; G = 1; pct = dot; break;  // digit 3
               case 4: A = 0; B = 1; C = 1; D = 0; E = 0; F = 1; G = 1; pct = dot; break;  // digit 4
               case 5: A = 1; B = 0; C = 1; D = 1; E = 0; F = 1; G = 1; pct = dot; break;  // digit 5
               case 6: A = 1; B = 0; C = 1; D = 1; E = 1; F = 1; G = 1; pct = dot; break;  // digit 6
               case 7: A = 1; B = 1; C = 1; D = 0; E = 0; F = 0; G = 0; pct = dot; break;  // digit 7
               case 8: A = 1; B = 1; C = 1; D = 1; E = 1; F = 1; G = 1; pct = dot; break;  // digit 8
               case 9: A = 1; B = 1; C = 1; D = 1; E = 0; F = 1; G = 1; pct = dot; break;  // digit 9
               default: A = 0; B = 0; C = 0; D = 0; E = 0; F = 0;   G = 0; pct = 0;        // segments OFF
        }     
        
        seg1 = 1; seg2 = 1; seg3 = 1; seg4 = 1; seg5 = 1; seg6 = 1; seg7 = 1; seg8 = 1;
        
        if(digit_sel == 1){seg1 = 0;}
        if(digit_sel == 2){seg2 = 0;}
        if(digit_sel == 3){seg3 = 0;}
        if(digit_sel == 4){seg4 = 0;}
        if(digit_sel == 5){seg5 = 0;}
        if(digit_sel == 6){seg6 = 0;}
        if(digit_sel == 7){seg7 = 0;}
        if(digit_sel == 8){seg8 = 0;}   

        sel = sel1/10; 
        digit_sel--;   
        dot = 0;
        
        delay_ms(3);
    }
           
}

void wait_button_release(){
    while(select_button || ok_button){
        //do nothing
    }
}

/*
functie de printat litere
  Primeste 3 valori,
        - litera
        - 1 sau 0 daca sa pun sau nu punct la inceput  de numar
        - numarul carcterului la care sa puna litera
*/ 

void print_letter(char sel, int8_t dot, int8_t digit_sel){ 
       
        switch (sel){
               case 'A': A = 1; B = 1; C = 1; D = 0; E = 1; F = 1; G = 1; pct = dot; break; // letter A
               case 'C': A = 1; B = 0; C = 0; D = 1; E = 1; F = 1; G = 0; pct = dot; break; // letter C
               case 'E': A = 1; B = 0; C = 0; D = 1; E = 1; F = 1; G = 1; pct = dot; break; // letter E        
               case 'H': A = 0; B = 1; C = 1; D = 0; E = 1; F = 1; G = 1; pct = dot; break; // letter H  
               case 'S': A = 1; B = 0; C = 1; D = 1; E = 0; F = 1; G = 1; pct = dot; break; // letter S
               default: A = 0; B = 0; C = 0; D = 0; E = 0; F = 0; G = 0; pct = 0;        // segments OFF
        }     
        
        seg1 = 1; seg2 = 1; seg3 = 1; seg4 = 1; seg5 = 1; seg6 = 1; seg7 = 1; seg8 = 1;
        
        if(digit_sel == 1){seg1 = 0;}
        if(digit_sel == 2){seg2 = 0;}
        if(digit_sel == 3){seg3 = 0;}
        if(digit_sel == 4){seg4 = 0;}
        if(digit_sel == 5){seg5 = 0;}
        if(digit_sel == 6){seg6 = 0;}
        if(digit_sel == 7){seg7 = 0;}
        if(digit_sel == 8){seg8 = 0;}   
        
        delay_ms(3);
           
}
/*
functie de verificat daca s a ajuns la sfarsitul lunii.
    Primeste 3 valori
    - ziua curenta
    - luna curenta
    - anul curent
    Returneaza 1 sau 0 daca s-a ajuns la sfarsit de luna sau nu
*/ 

int8_t month_check( int8_t day_number, int8_t month_number, int8_t year_number){
    switch (month_number){
        case 1: if(day_number == 31) return 1; break; 
        case 2: if(((day_number == 28) && (year_number % 4 != 0)) || ((day_number == 29) && (year_number % 4 == 0))) return 1; break;
        case 3: if(day_number == 31) return 1; break;
        case 4: if(day_number == 30) return 1; break;
        case 5: if(day_number == 31) return 1; break;
        case 6: if(day_number == 30) return 1; break;
        case 7: if(day_number == 31) return 1; break;
        case 8: if(day_number == 31) return 1; break;
        case 9: if(day_number == 30) return 1; break;
        case 10: if(day_number == 31) return 1; break;  
        case 11: if(day_number == 30) return 1; break; 
        case 12: if(day_number == 31) return 1; break;    
        default: return 0;  
        return 0;
     }
}

/*
    Timer de 10 milisecunde !! ( TIME.milisecond si STOPWATCH.milisecond sunt x10 milisecunde )
        - Incrementeaza TIME,STOPWATCH si CALENDAR.
        - Verifica daca alarma este egal cu TIME si suna 5 secunda in caz afirmativ.
*/ 

interrupt [TIM1_COMPA] void timer1_compa_isr(void){

    TIME.milisecond++;
    STOPWATCH.milisecond++;  
    
    if(TIME.milisecond == 100){  
        TIME.second++;
        TIME.milisecond = 0;
         
        STOPWATCH.second++;
        STOPWATCH.milisecond = 0;
        
        if(TIME.second == 60){
            TIME.minute++;
            TIME.second = 0;
            
            STOPWATCH.minute++;
            STOPWATCH.second = 0;
            
            if(TIME.minute == 60){
                TIME.hour++;
                TIME.minute = 0;
                 
                STOPWATCH.hour++;
                STOPWATCH.minute = 0;
                
                if(TIME.hour == 24){
                    CALENDAR.day++;
                    
                    TIME.hour = 0;
                    STOPWATCH.hour = 0;
                    ALARM.hour = 0; 
                    
                    if(month_check(CALENDAR.day, CALENDAR.month, CALENDAR.year)){
                        CALENDAR.month++;
                        CALENDAR.day = 1;
                        
                        if(CALENDAR.month == 13){
                            CALENDAR.year++;   
                            CALENDAR.month = 1;
                        }
                    }
                }
            }
        }
       
    }
    
    if(ALARM_is_set == 1 && TIME.hour == ALARM.hour && TIME.minute == ALARM.minute){
        if(buzzer_is_on < 500){
            buzzer = 1;
            buzzer_is_on++;
            }else{
            buzzer = 0;
            buzzer_is_on = 0; 
            ALARM_is_set = 2;
            ALARM.hour = 0;
            ALARM.minute = 0;
            }
    }
        
}


