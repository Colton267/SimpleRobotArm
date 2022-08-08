#include <Servo.h>
Servo myServo;
Servo myServo2;

const int downSwitchPin = 2;
const int upSwitchPin = 3;
int increment = 0;
bool upBool = true;
bool downBool = true;

const int downSwitchPin2 = 4;
const int upSwitchPin2 = 5;
int increment2 = 0;
bool upBool2 = true;
bool downBool2 = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(9);
  myServo2.attach(10);
  myServo.write(0);
  myServo2.write(0);

  pinMode(downSwitchPin, INPUT);
  pinMode(upSwitchPin, INPUT);
  pinMode(downSwitchPin2, INPUT);
  pinMode(upSwitchPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  upSwitchDetection();
  downSwitchDetection();
  upSwitchDetection2();
  downSwitchDetection2();
}

void upSwitchDetection(){
  if(digitalRead(upSwitchPin) == HIGH){
    downBool = true;
    while(digitalRead(upSwitchPin) == HIGH && upBool == true){
      myServo.write(increment);
      increment++;
      //Serial.println(increment);
      if(increment >= 180) {
        upBool = false;
      }
      delay(5);
    }
  }
}

void downSwitchDetection(){
  if(digitalRead(downSwitchPin) == HIGH){
    upBool = true;
    while(digitalRead(downSwitchPin) == HIGH && downBool == true){
      myServo.write(increment);
      increment--;
      //Serial.println(increment);
      if(increment <= 0) {
        downBool = false;
      }
      delay(5);
    }
  }
}

void upSwitchDetection2(){
  if(digitalRead(upSwitchPin2) == HIGH){
    downBool2 = true;
    while(digitalRead(upSwitchPin2) == HIGH && upBool2 == true){
      myServo2.write(increment2);
      increment2++;
      Serial.println(increment2);
      if(increment2 >= 180) {
        upBool2 = false;
      }
      delay(5);
    }
  }
}

void downSwitchDetection2(){
  if(digitalRead(downSwitchPin2) == HIGH){
    upBool2 = true;
    while(digitalRead(downSwitchPin2) == HIGH && downBool2 == true){
      myServo2.write(increment2);
      increment2--;
      Serial.println(increment2);
      if(increment2 <= 0) {
        downBool2 = false;
      }
      delay(5);
    }
  }
}
