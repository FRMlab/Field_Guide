/******************************************************************************
 * F_RMlab @ Waterloo School of Architecture
 * Code for irSensor and servo motor module
 * Grow-Op
 ******************************************************************************/

/*
  Code for grow-op
  Style standards are loosely based on PEP 8 
  PEP 8 - Style Guide for Python Code
  http://www.python.org/dev/peps/pep-0008/
  - define values
  - setup
  - infrared value -> set_direction -> motor_inc
  - infrared values takes ir value sends to set_direction
  - set_direction determines direction based on  
  
*/




/******************************************************************************
  Set initial Variables
  Hardware variables
  1. Define MUX control pins on board.
  2. Define servo motor on this pin.
  Define variables for code.
  1. Global variables
 ******************************************************************************/

#define S3 5 
#define S2 4
#define S1 3
#define S0 2

//#define irLedPin PIND // IR Led on this pin *OLD*
//#define irSensorPin 8 // IR sensor on this pin *OLD*
#include <Servo.h> 

Servo servo_1; 
Servo servo_2;
Servo servo_3;
Servo servo_4;

// defined initialization
boolean DEBUG = true;
float DIST = 60; 
float DIST_VAL = (9462 + (dist * 16.92)) / DIST; 
float INC = 5;
int IR_SENSOR_PIN = A3;

int dir;
int led = 13;
int pos = 180;

/******************************************************************************
 * Main Code
   1. setup: set MUX board
   2. loop: take ir input and calls set_dir method  
 ******************************************************************************/
  
void setup()
{
  Serial.begin(9600); // inits serial output 
  Serial.println("Program Starting");
  //pinMode(led, OUTPUT);
  servo_1.attach(12);
  servo_4.attach(6);
  
  pinMode(S3, OUTPUT); // set MUX to output
  pinMode(S2, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S0, OUTPUT);

  pinMode(14, OUTPUT); // set MUX M1 (14), M2 (15), M3 (16) to output
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);

  digitalWrite(14, LOW); // set MUX M1 (14), M2 (15), M3 (16) to low
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
  int ir = analogRead(IR_SENSOR_PIN); // takes infrared value from infrared sensorpin
  if(DEBUG==true)
    Serial.println("IR: " + ir);
  set_direction(ir); // sends value to set_direction method
  if(DEBUG== true){
    Serial.println("POS: " + pos);
    Serial.println("DIR: " + dir);
  }
}



  


