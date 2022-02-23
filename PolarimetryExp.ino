#include <Servo.h>

int pos = 0;

int c = 0;

Servo servo_9;

String readString;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);

  servo_9.attach(9, 500, 2500);
  Serial.begin(9600);
  Serial.println("what is your integer? ");
}

void loop() {
  digitalWrite(13,HIGH);
  for (int i =0; i<10; i++){
    Serial.println(analogRead(A0)); // prints sensor reading once motor has turned the angle
  }

  servo_9.write(0);
  int c = Serial.parseInt();
  Serial.println(c);
  
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 0; pos <= c; pos += 1) {
    // tell servo to go to position 
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  delay(5000);
  for (pos = c; pos >= 0; pos -= 1) {
    // tell servo to go to position 
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }

}
