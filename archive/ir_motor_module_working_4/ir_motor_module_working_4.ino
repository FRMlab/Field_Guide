/******************************************************************************
 * F_RMlab @ Waterloo School of Architecture
 * Code for irSensor and servo motor module
 * Grow-Op
 ******************************************************************************/

#define S3 5 //MUX control pins
#define S2 4
#define S1 3
#define S0 2

//#define irLedPin PIND // IR Led on this pin
//#define irSensorPin 8 // IR sensor on this pin
#include <Servo.h> // servo motor on this pin

Servo servo_1; 
Servo servo_2;
Servo servo_3;
Servo servo_4;

// defined initialization:
float inc = 5;  
int dir;
int irSensorPin = A3;
int led = 13;
float dist = 60; // SET DISTANCE HERE!!
float dist_val = (9462 + (dist * 16.92)) / dist; 
int pos = 180;
//******************************************************************************/
  
void setup()
{
  Serial.begin(9600);  
  Serial.println("Program Starting");
  //pinMode(led, OUTPUT);
  servo_1.attach(12);
  servo_4.attach(6);
  
  pinMode(S3, OUTPUT); //set MUX to output
  pinMode(S2, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S0, OUTPUT);

  pinMode(14, OUTPUT); //set MUX M1 (14), M2 (15), M3 (16) to output
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);

  digitalWrite(14, LOW); //set MUX M1 (14), M2 (15), M3 (16) to low
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
  
  digitalWrite(S3, HIGH); 
  digitalWrite(S2, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(S0, LOW);
  
    
  servo_2.attach(14);
  servo_3.attach(15);
  
}

void loop(){
  int ir = analogRead(irSensorPin);
  Serial.println("IR: " + ir);
  Serial.println("DIST_VAL: " + dist_val);
  set_direction(ir);
  Serial.println("POS: " + pos);
  Serial.println("DIR: " + dir);
  
  //delay(25);
}

  /*
  data definition:
  dir is int where:
  1 = arm goes to top; (- pos)
  2 = stay at top;
  3 = arm goes down; (+ pos)
  4 = stay at bottom
  */

  


