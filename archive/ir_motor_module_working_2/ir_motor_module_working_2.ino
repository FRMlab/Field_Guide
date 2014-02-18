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
int led = 12;

// defined constants:
int halfPeriod = 13; //one period at 38.5khZ is aproximately 26 microseconds
int cycles = 38; //26 microseconds * 38 is more or less 1 millisecond  

// defined initialization:
float pos = 180; // servo position
float init_inc = 5;
float inc = init_inc; // increment  
int dir;

int irSensorPin = A3;

//******************************************************************************/
  
void setup()
{
  Serial.begin(9600);  
  Serial.println("Program Starting");
  //pinMode(led, OUTPUT);
  servo_1.attach(10);
  
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
  servo_4.attach(16);
}

void loop(){
  int ir = analogRead(irSensorPin);
  Serial.println(ir);//"IR: " + ir);
  set_direction(ir);
  
  //Serial.println(pos);//"POS: " + pos);
  //Serial.println(dir);//"DIR: " + dir);
  
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

  


