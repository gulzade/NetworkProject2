#define MotorR1 11
#define MotorR2 12
#define MotorRE 13
#define MotorL1 4
#define MotorL2 5
#define MotorLE 3
int state; //Bluetooth cihazından gelecek sinyalin değişkeni
void setup() {
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT);
  // 9600 baud hızında bir seri port açalım
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Gelen veriyi 'state' değişkenine kaydet
  if (Serial.available() > 0) {
    state = Serial.read();

    if (state == 10) { //ileri git
      forward();
    }

    else if (state == 20) { //geri git
      back();
    }
    else if (state == 30) { //sola git
      turnLeft();
    }
    else if (state == 40) { //sağa git
      turnRight();
    }
    else {
      Stop();
    }
  }
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
