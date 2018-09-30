
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
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(PIR, INPUT);
  zAxis.attach(Servo1);
  yTilt.attach(Servo2);
  yTilt.write(0);
  Serial.println("Started!");
}

void loop() {
  if ((millis() - prevTime) > 10000) {
    Serial.println("Ready for Scare!");
    waitMotion();
  }
}

void waitMotion() {
  while (1) {
    motion = digitalRead(PIR);
    if (motion) {
      Serial.println("Motion Detected - Start Scare!");
      prevTime = millis(); //Reset time stamp upon triggering SPOOK
      digitalWrite(LED_BUILTIN, HIGH);
      SPOOK();             //Scare Action Function
      return;
    }
  }
}

void SPOOK() {
  //Servo Triggering
  yTilt.write(90);
  delay(1000);
  for(int i = 89; i > 3; i--){
    yTilt.write(i);
    delay(30);
  }
  
  
  /* 
  //Relay Triggering
  digitalWrite(Relay1 = 1);
  delay(25);
  digitalWrite(Relay1 = 0);
  */
   Serial.println("Scare Done!");
   digitalWrite(LED_BUILTIN, LOW);
}

