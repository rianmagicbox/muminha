#include <Servo.h>

Servo servo_base; 
Servo servo_pescosso;  //min:70 max: 130 

int joyx = 0;
int joyy = 1; // analog pin used to connect the potentiometer
int valx;
int valy; // variable to read the value from the analog pin

void setup() {
  pinMode(8, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  servo_base.attach(4);
  servo_pescosso.attach(5); // attaches the servo on pin 9 to the servo object
}

void loop() {
  int sensorVal = digitalRead(8);
  Serial.println(sensorVal);

  if (sensorVal == HIGH) {
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  } else {
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  
  valx = analogRead(joyx);            // reads the value of the potentiometer (value between 0 and 1023)
  valx = map(valx, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servo_base.write(valx); 
  valy = analogRead(joyy);            // reads the value of the potentiometer (value between 0 and 1023)
  valy = map(valy, 500, 1023, 30, 130);     // scale it to use it with the servo (value between 0 and 180)
  servo_pescosso.write(valy);// sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
