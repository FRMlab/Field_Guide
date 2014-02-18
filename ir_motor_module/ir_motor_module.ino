/*-------------------------------------------------------------------- 
  * F_RMlab @ Waterloo School of Architecture
  * Code for irSensor and servo motor module
  * Grow-Op
  ----
  Code for grow-op
  Style standards are loosely based on PEP 8 
  PEP 8 - Style Guide for Python Code
  http://www.python.org/dev/peps/pep-0008/
  
  Aim here is for legibility over Style consistency
  ---
  
  This is the code for one module in the Grow-op surface. Each module consists of a
  motor controlling an arm and a inrared sensor. The infrared sensor detects proximity
  (i.e someone reaching out to the surface) and sends instructions to the motor to 
  retract the arm accordingly. Each module is local and not 'aware' of it's neighbors.
  
  a     b     c     d     e
  
        |    
        |    
  |-----|-----\-----|-----|
  |            \    |     |
  |             \   |     |
  
  For module a-e. Module b's ir sensor and motor activity will not effect it's neighbors.
  In this case Module's c's ir sensor is also triggered by activity. This is what gives
  the surface's cascading effect, cheaply and effectively.  
  
  ---
  
  Basic code structure is:  
    * inputs (sets MUX control pins, ir sensor, and motor arm pos) -> 
    *   main loop (receives values and sends to set_direction) -> 
    *     set_direction (determines direction of arm based on position and ir activity)-> 
    *       motor_inc (converts dir and pos into instructions for motor arm incrementation)
  
 
  START
  ____|
      |
      |
      |
  starting: pos = 180; dir = 4 (stay at bottom)    
  
  
  MOVE UP
         /
        /
       /
  ----/     
  moving: 0 > pos < 180; dir = 1 (go to top)
  
  
  MOVE DOWN
  ----\
       \
        \
         \
  if ir sensor is not active, dir = 3 (go to bottom) 
  and then dir = 4 (stay at bottom)
  
  MAX
      | 
      |      
      |
  ----|
  end position, fully retracted: pos = 0
  Once ir sensor is not active, the arm will move down
  and rest  

--------------------------------------------------------------------*/

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
  
void setup(){
  /*-------------------------------------------------------------------- 
   setup: none -> none 
   Effects: set MUX board, and define global variables and constants
 --------------------------------------------------------------------*/
  /* setup: none -> none */
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
  /*-------------------------------------------------------------------- 
   loop: recieves infrared sensor value (ir) from board and 
   calls set_dir method with ir as argument  
 --------------------------------------------------------------------*/
  /* loop: none -> none */
  int ir = analogRead(IR_SENSOR_PIN); // takes infrared value from infrared sensorpin
  if(DEBUG==true)
    Serial.println("IR: " + ir);
  set_direction(ir); // sends ir value to set_direction method
  if(DEBUG== true){
    Serial.println("POS: " + pos);
    Serial.println("DIR: " + dir);
  }
}



  


