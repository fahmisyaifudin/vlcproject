#include <Servo.h>
Servo servoku;
const int pin1 = 3;

int pin = 2; 
volatile unsigned int pulse; 
char ch;
 
void setup() 
{ 
  Serial.begin(9600); 
  pinMode(pin, INPUT);
  pinMode(8, OUTPUT);
  servoku.attach(3);
  servoku.write(0);
  digitalWrite(8, LOW);
  pinMode(pin1, OUTPUT);//D2
  attachInterrupt(0, count_pulse, RISING); 
} 
 
void loop() 
{
  Serial.println("KEY = ");
  delay(500);
  if(pulse != 0)
  {    
    interrupts(); 
    delay(300); 
    //noInterrupts(); 
     
    Serial.print("Pulses per second: "); 
    Serial.println(pulse);
    if(pulse==10){
      Serial.println('A');
      servoku.write(90);
      
    }
    else if(pulse==11){
      Serial.println('B');
      servoku.write(0);
    }
    else if(pulse==12){
      Serial.println('C');
      digitalWrite(8, HIGH);
    } 
    else if(pulse==13){
      Serial.println('D');
      digitalWrite(8, LOW);
    }
      
    else if(pulse==14)
      Serial.println('*');
    else if(pulse==15)
      Serial.println('0');
    else if(pulse==16)
      Serial.println('#');
    else if(pulse==17)
      Serial.println('#');
    else 
      Serial.println(pulse);
    
    pulse=0;
  }
} 
 
void count_pulse() 
{ 
  pulse++; 
} 
