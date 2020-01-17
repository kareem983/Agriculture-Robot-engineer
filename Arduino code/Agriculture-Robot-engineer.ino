#include <LiquidCrystal.h>
#include <Servo.h>
const int rs = 6, en = 7, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo servo;
  //car motors pins
   byte p1=2;
   byte p2=3;
   byte p3=4;
   byte p4=5;
   char D;
   byte relay = 8;
   int x =0;
   int moisture =100;
  
void setup() {
  // put your setup code here, to run once:
  //declare car motors
  pinMode (p1,OUTPUT);
  pinMode (p2,OUTPUT);
  pinMode (p3,OUTPUT);
  pinMode (p4,OUTPUT);
  pinMode (relay , OUTPUT);
  Serial.begin(9600); //declare the serial monitor
  servo.attach(9); //declare servo motor
  // declare lcd and display in beginning soil moiture
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture :) ");
  delay (1000);
}

void loop() {
  
  lcd.clear();
  lcd.setCursor(0,0);
  moisture = analogRead(A0);
  moisture = map(moisture,0,1023,1,100);
  lcd.print(moisture);
  if (moisture > 65 && moisture < 98)
  {
     digitalWrite(relay,HIGH);
  }
  else 
  {
    digitalWrite(relay,LOW);
  }
  
  if (Serial.available())
  {
    D = Serial.read();
    Serial.println(D);
    if (D == 'F')
    {
      //forward
      digitalWrite(p1,HIGH);
      digitalWrite(p2,LOW);
      digitalWrite(p3,HIGH);
      digitalWrite(p4,LOW);
    }
   else if (D == 'B')
    {
      //backword
      digitalWrite(p1,LOW);
      digitalWrite(p2,HIGH);
      digitalWrite(p3,LOW);
      digitalWrite(p4,HIGH);
    }
   else if (D=='L')
    {
      //left front
      digitalWrite(p1,HIGH);
      digitalWrite(p2,LOW);
      digitalWrite(p3,LOW);
      digitalWrite(p4,LOW);
    }
   else if (D=='R')
    {
      //right front
     digitalWrite(p1,LOW);
     digitalWrite(p2,LOW);
     digitalWrite(p3,HIGH);
     digitalWrite(p4,LOW);
    }
     else if (D=='H')
    {
      //right back
      digitalWrite(p1,LOW);
      digitalWrite(p2,HIGH);
      digitalWrite(p3,LOW);
      digitalWrite(p4,LOW);
    }
   else if (D=='J')
    {
      //left back
     digitalWrite(p1,LOW);
     digitalWrite(p2,LOW);
     digitalWrite(p3,LOW);
     digitalWrite(p4,HIGH);
    }
     else if (D== 'i')   //servo in
    {
     x = 130;
     servo.write(x);
    }
    else if (D=='o') //servo  out
    {
      x = 40 ;
      servo.write(x);
    }
      
   else //stop
   {
     digitalWrite(p1,LOW);
     digitalWrite(p2,LOW);
     digitalWrite(p3,LOW);
     digitalWrite(p4,LOW);
     digitalWrite(relay,LOW);
   }
  }

}
