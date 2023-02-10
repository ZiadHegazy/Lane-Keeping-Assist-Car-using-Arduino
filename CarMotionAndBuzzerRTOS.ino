#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
TaskHandle_t xTaskCarHandle = NULL;

int enA= 13;
#define IN1 12
#define IN2 11
int enB= 10;
#define IN3 9
#define IN4 8
int x=0;
#define IRINPUT 7
#define IRINPUT2 6

#define buzzerOut 5
#define buzzerOn 4
// IRSensor when read black gives high
// WHITE BOTH SENSORS LIGHT UP 
// MENWAR LAMBTEN Y3NY LOW  2
// laz2a soda in1,2
// pin 7 ma7ro2
void setup() {
  Serial.begin(9600);
  pinMode(enA , OUTPUT);
  pinMode(IRINPUT,INPUT);
  pinMode(IRINPUT2,INPUT);
  pinMode(enB , OUTPUT);
  pinMode(IN1 , OUTPUT);
  pinMode(IN2 , OUTPUT);
  pinMode(IN3 , OUTPUT);
  pinMode(IN4 , OUTPUT);
  pinMode(buzzerOut,OUTPUT);
  pinMode(buzzerOn,OUTPUT);
  xTaskCreate(carMotion,"Car Motion",500,NULL,1,&xTaskCarHandle);
  vTaskStartScheduler();
    
}


void carMotion(){
  while(1){
      int IRsensorLeft=digitalRead(IRINPUT2);
  int IRsensorRight=digitalRead(IRINPUT);
  
  if(IRsensorLeft==LOW && IRsensorRight==HIGH){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN4,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
            digitalWrite(buzzerOn,HIGH);

    analogWrite(buzzerOut,100);
  analogWrite(enA, 255);
  analogWrite(enB,0);

  }
  else if (IRsensorRight==LOW &&  IRsensorLeft==HIGH){
     
    digitalWrite(IN1,LOW);
    digitalWrite(IN4,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
        digitalWrite(buzzerOn,HIGH);

    analogWrite(buzzerOut,100);
  analogWrite(enA, 0);
  analogWrite(enB,255);
  }
    

  else if(IRsensorRight==HIGH && IRsensorLeft==HIGH){
    digitalWrite(IN1,LOW);
    digitalWrite(IN4,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(buzzerOn,LOW);
    noTone(buzzerOut);
    analogWrite(buzzerOut,1000000);
  analogWrite(enA, 0);
  analogWrite(enB,0);
  }
  else if (IRsensorRight==LOW && IRsensorLeft==LOW){
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,HIGH);
      digitalWrite(buzzerOn,LOW);

    noTone(buzzerOut);
     analogWrite(buzzerOut,100000);

  analogWrite(enA, 160);
  analogWrite(enB,160);
  }
  delay(200);
  }
}
// the loop function runs over and over again forever
void loop() {
  
   //vTaskStartScheduler();

}
// 7,13 pins ma7ro2




