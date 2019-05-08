#include <SoftwareSerial.h>
#define MotorR1 4
#define MotorR2 5
#define MotorRE 3
#define MotorL1 11
#define MotorL2 12
#define MotorLE 13
int buzzerPin = 7;
#define echopin  A0 // echo pin
#define trigpin A1 // Trigger pin

  SoftwareSerial BT(9, 10);
  int state; //Variable of the signal from the Bluetooth device
  int timer = 0;
  int distance;
  long duration;
  int chk = 0;
  int set = 15;

  void setup() {
  pinMode (trigpin, OUTPUT); //ultrasonic sensor pin 
  pinMode (echopin, INPUT ); //ultrasonic sensor pin 
    
  pinMode(buzzerPin, OUTPUT); //Buzzer pin
    
  pinMode(MotorR1, OUTPUT);  //Motor pins  //right
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);
  pinMode(MotorL1, OUTPUT);  //Motor pins  //left
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT);
    
  //initial state =stop
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, LOW);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, LOW);
   
  Serial.begin(9600);
  BT.begin(9600); // Setting the baud rate of Software Serial Library
  delay(500);
 
}

void loop() {
  // put your main code here, to run repeatedly:

  //Save incoming data to 'state' variable
  if (BT.available() > 0) {
    state = Serial.read();
  }
     distance = data();
  
   if ((distance < set) && (chk == 1)) {// alarms and stops when the distance value falls below 15 and 
    chk = 2; Serial.print(distance);
    Stop(); alert();
  }
  
  if (distance > set) {
    chk = 0;
  }
     if (state == 10 && (chk == 0)) { //Go forward
       chk = 1;
       forward();
      }

      else if (state == 20) { //go back
        back();
      }
      else if (state == 30) { //turn left
        turnLeft();
       }
      else if (state == 40) { //turn right
        turnRight();
      }
      else {
        Stop();
      }
  
  timer = timer + 1;
  //Serial.println(timer);
  if (timer == 200)
  {
    if (distance > 200) {
      distance = 200;
    }
    BT.print(distance); //send distance to MIT App
  }

  if (timer > 400)
  {
    timer = 0;
  }
  delay(1);


}
void Stop() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, 150);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, 150);

}
void back() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  digitalWrite(MotorRE, 150);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  digitalWrite(MotorLE, 150);

}
void forward() {
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, 150);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, 150);

}
void turnRihgt() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  digitalWrite(MotorRE, 150);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, 150);

}
void turnLeft() {
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, 150);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  digitalWrite(MotorLE, 150);

}
long data() //distance calculation
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn (echopin, HIGH);
  return duration / 29 / 2;
}
void alert() { //alarm code

  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
 
 
  
}
