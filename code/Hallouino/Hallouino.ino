
/*******************************************
   Halloween Spoopy Skeleton Scares
     -Arduino Uno using custom RelayUno PCB
 ******************************************/
#include <Servo.h>

Servo zAxis;
Servo yTilt;

//Setup Peripherals
#define Relay1 2
#define Relay2 3
#define Relay3 4
#define Servo1 5
#define Servo2 6
#define PIR 7

int motion = 0;
int

unsigned long Time = 0;
unsigned long prevTime = 0;

void setup() {

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(PIR, INPUT);
  zAxis.attach(Servo1);
  yTilt.attach(Servo2);

}

void loop() {
  if ((millis() - prevTime) > 30000) {
    waitMotion();
  }
}

void waitMotion() {
  while () {
    motion = digitalRead(PIR);
    if (motion) {
      prevTime = millis(); //Reset time stamp upon triggering SPOOK
      SPOOK();             //Scare Action Function
      return;
    }
  }
}

void SPOOK() {
  //Servo Triggering
  yTilt.write(90);
  delay(1000);
  for(int i = 89; i > -1; i--){
    yTilt.write(i);
    delay(30);
  }
  
  /* 
  //Relay Triggering
  digitalWrite(Relay1 = 1);
  delay(25);
  digitalWrite(Relay1 = 0);
  */
}

