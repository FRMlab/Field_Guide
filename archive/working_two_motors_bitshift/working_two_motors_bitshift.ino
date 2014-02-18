/******************************************************************************
 * F_RMlab @ Waterloo School of Architecture
 * Code for irSensor and servo motor module
 * Grow-Op
 ******************************************************************************/

#define CONTROL0 5 //MUX control pins
#define CONTROL1 4
#define CONTROL2 3
#define CONTROL3 2

#define irLedPin PIND // IR Led on this pin
#define irSensorPin 6 // IR sensor on this pin
#include <Servo.h> // servo motor on this pin

Servo servo_1; 
Servo servo_2;
int led = 12;

int mux0array[16];


// defined constants:
int halfPeriod = 13; //one period at 38.5khZ is aproximately 26 microseconds
int cycles = 38; //26 microseconds * 38 is more or less 1 millisecond  

// defined initialization:
float pos = 180; // servo position
float init_inc = 5;
float inc = init_inc; // increment  
int dir;

//******************************************************************************/
  
void setup()
{
  Serial.begin(9600);  
  Serial.println("Program Starting");
  pinMode(led, OUTPUT);
  
  pinMode(CONTROL0, OUTPUT); //set MUX to output
pinMode(CONTROL1, OUTPUT);
pinMode(CONTROL2, OUTPUT);
pinMode(CONTROL3, OUTPUT);

digitalWrite(CONTROL0, LOW); //set MUX pins to low
digitalWrite(CONTROL1, LOW);
digitalWrite(CONTROL2, LOW);
digitalWrite(CONTROL3, LOW);

pinMode(14, OUTPUT); //set MUX M1 (14), M2 (15), M3 (16) to output
pinMode(15, OUTPUT);
pinMode(16, OUTPUT);  

digitalWrite(14, LOW); //set MUX M1 (14), M2 (15), M3 (16) to low
digitalWrite(15, LOW);
digitalWrite(16, LOW);     

 for (int i=0; i<16; i++)
    {
         digitalWrite(CONTROL0, i & 8 );

  servo_2.attach(14);
  servo_1.attach(15);    
  

}
    
    
//  servo_2.attach(11);
//  servo_1.attach(10);
  
}

void loop(){
   for (int i=0; i<16; i++)
    {
      
digitalWrite(16, HIGH); //set MUX M1 (14), M2 (15), M3 (16) to low
      
    digitalWrite(CONTROL0, (i&15)>>3); 
    digitalWrite(CONTROL1, (i&7)>>2);  
    digitalWrite(CONTROL2, (i&3)>>1);  
    digitalWrite(CONTROL3, (i&1));    
    
  
      mux0array[i] = !digitalRead(16);
    }
      
 
      
  irRead(irSensorPin, irLedPin); //display the results  
  int ir = digitalRead(irSensorPin); 
  set_direction(ir);
  
  Serial.println(ir);//"IR: " + ir);
  Serial.println(pos);//"POS: " + pos);
  Serial.println(dir);//"DIR: " + dir);
  
  
  //delay(100);
}

// irRead: int int -> None
// Consumes int representing pin of infrared sensor pin (irSP) and
// infrared led pin (irLP) and produces None
// Effects: The function bangs a 38.5khZ waveform to an IR led connected to the
// triggerPin for 1 millisecond, and then reads the IR sensor pin to see if the reflected
// IR has been detected
// the irSP returns a zero if something is detected by the sensor, and a 1 otherwise

void irRead(int irSP, int irLP)
{  
  for (int i=0; i <= cycles; i++)
  { 
    //digital irled signal sent
    digitalWrite(irLP, HIGH);  
    delayMicroseconds(halfPeriod);
    digitalWrite(irLP, LOW); 
    delayMicroseconds(halfPeriod - 1);     // - 1 to make up for digitaWrite overhead    
  }
}

// motor_inc: None -> None
// Effects: The function increments the servo motor position by iteration based on
// direction of arm

int motor_inc(int irSP, int irLP)
{  
  if(dir == 3){ // go to bottom
    pos += (inc*inc);
  }else if (dir == 1){ // go to top
    pos -= (inc*inc);
  }else{ // stay
     // do nothing
  }
  servo_2.write(pos);
  servo_1.write(pos);
  //delay(100);
  irRead(irSP, irLP);
  //delay(100);
  return digitalRead(irSP);
}
// set_direction
// code sets dir variable to 1 - 4 then 
// motor_inc changes pos based on dir
// and returns ir variable
void set_direction(int sensor_active){
  if(sensor_active != 0){ //if sensor is active
    digitalWrite(led,HIGH);//trigger led 13
    while(pos > 0){ //go to 0 = top
      dir = 1;
      sensor_active = motor_inc(irSensorPin, irLedPin);
      //delay(100);
    }
    dir = 2;//stay at top = 0
    sensor_active = motor_inc(irSensorPin, irLedPin);
    inc = init_inc;   
  }else{
    digitalWrite(led,LOW);//trigger led 13
    if(pos < 180){ // go to 180 = bottom
      dir = 3;
      sensor_active = motor_inc(irSensorPin, irLedPin);
      //delay(100);
    }
    dir = 4;//stay at bottom = 180
    sensor_active = motor_inc(irSensorPin, irLedPin);
    inc = init_inc;
  }
} 
  
  /*
  data definition:
  dir is int where:
  1 = arm goes to top; (- pos)
  2 = stay at top;
  3 = arm goes down; (+ pos)
  4 = stay at bottom
  */

  


