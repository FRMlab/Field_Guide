#define CONTROL0 5 //MUX control pins
#define CONTROL1 4
#define CONTROL2 3
#define CONTROL3 2

#include <Servo.h> 
 
Servo myservo;  // 4 servo ojbects
Servo myservo2;  
Servo myservo3;  
Servo myservo4;  

float pos = 0; // servo position
float inc = 5; // increment  
boolean go_down;


void setup() 
{ 
  
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

  myservo.attach(14); //servo on pin 8 in M0
  myservo2.attach(15); //servo on pin 8 in M1
//  myservo3.attach(16);  //servo on pin 8 in M2 - doesn't work
    }
    
    myservo3.attach(12); //servo on pin 12 on normal arduino
    myservo4.attach(10); //servo on pin 12 on normal arduino
    
    
  Serial.begin(9600);
  
} 
 
 
void loop() 
{ 
  
   if(pos >= 180 || pos <= 0){
    if(pos >= 180){
      go_down = false;
    }else{
      go_down = true;
    }
  } 
  if(go_down == true){
    Serial.println(go_down);
    pos += inc;
  }else{
    Serial.println(go_down);
    pos -= inc;
  }
  Serial.println(pos);
  myservo.write(pos);
  myservo2.write(pos);
  myservo3.write(pos);
  myservo4.write(pos);
  
  delay(100);
}

