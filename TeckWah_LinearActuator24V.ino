/*
 * Author: Benjamin Low
 * Last updated: 16 Dec 2015
 * Description: Controls up to two linear actuators using L298N heat sink module.
 * Pin 1 and 2 for each motor cannot be high at the same time. Reverse both logic states
 * to change the direction of movement. Put both pins LOW to stop the motor. 
 */

 //all four are pwm pins
int motor1_pin1 = 5; 
int motor1_pin2 = 6; 
int motor2_pin1 = 10;
int motor2_pin2 = 11;

void setup() {
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  
  Serial.begin(9600);
  
  analogWrite(motor1_pin1, 0);
  analogWrite(motor1_pin2, 0);
  analogWrite(motor2_pin1, 0);
  analogWrite(motor2_pin2, 0);
}

void loop() {

  unsigned char incomingbyte = 0;

  if (Serial.available() > 0) {
        
    incomingbyte = Serial.read();

    if (incomingbyte == '0') {
      
      analogWrite(motor1_pin1, 0);//stop
      analogWrite(motor1_pin2, 0);
      analogWrite(motor2_pin1, 0);//stop
      analogWrite(motor2_pin2, 0);
      Serial.println("stopping");
      
    } else if (incomingbyte == '1') {
      
      analogWrite(motor1_pin1, 255); //max speed extend
      analogWrite(motor1_pin2, 0); 
      analogWrite(motor2_pin1, 255); //max speed extend
      analogWrite(motor2_pin2, 0);
      Serial.println("extending");
      
    } else if (incomingbyte == '2') {
      
      analogWrite(motor1_pin1, 0); //max speed retract
      analogWrite(motor1_pin2, 255); 
      analogWrite(motor2_pin1, 0); //max speed retract
      analogWrite(motor2_pin2, 255);
      Serial.println("retracting");
    }
  }
  
  delay(10);
}




