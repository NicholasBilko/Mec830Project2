#include <IRremote.h>

char command;
int receiver_pin = 2;   //Connect the output pin of IR receiver at pin 2
int vcc = 3;            //VCC for IR sensor                                           //EDIT////
int gnd = 4;            //GND for IR sensor                                           //EDIT

int statusled = 5;

IRrecv irrecv(receiver_pin);

decode_results results;


// connect motor controller pins to Arduino digital pins
// Right Motor
int enA = 8;
int in1 = 9;
int in2 = 10;

// Left Motor
int enB = 13;
int in3 = 12;
int in4 = 11;


void setup()

{
Serial.begin(9600);

irrecv.enableIRIn();

pinMode(statusled,OUTPUT);

digitalWrite(statusled,LOW);

// set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  
// Initializing vcc pin high
  digitalWrite(vcc, HIGH);
}

void loop() {

if (irrecv.decode(&results)) {

digitalWrite(statusled,LOW);

irrecv.resume();

if (results.value == 0xFF18E7){ // type button 2 forward robot control

 // this function will run the motors in both directions at a fixed speed
 Serial.println("Button 2");
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 130);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 130);



}else if(results.value == 0xFF10EF){ // type button 4 turn left robot control 

 // this function will run motor A in forward directions  motor B stop
  Serial.println("Button 4");
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 130);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 130);
  

}else if(results.value == 0xFF30CF){ // type button 1 rotate left robot control 

 // this function will run motor A in forward directions  motor B in backward directions
  Serial.println("Button Turn Right");
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 130);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 130);
  

}else if(results.value == 0xFF5AA5){ // type button 6 turn right robot control 

// this function will  stop motor A  run motor B in forward directions 
 Serial.println("Button Turn Left");
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 130);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 130);

}else if(results.value == 0xFF7A85){ // type button 3 rotate right robot control 

// this function will run motor A  in backward directions  motor B in forward directions 
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 130);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 130);

} else if(results.value == 0xFF4AB5){ // type button 8 backward robot control

// this function will run motor A and motor B in backward directions 
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 130);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 130);

}else if(results.value == 0xFF38C7){ // type button 5 stop robot control 

// this function will stop both motor A and motor B 
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 130);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 130);
}
}
}
