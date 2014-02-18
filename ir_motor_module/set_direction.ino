 /*
  data definition
  dir is int where:
    1 = arm goes to top; (- pos)
    2 = stay at top;
    3 = arm goes down; (+ pos)
    4 = stay at bottom
*/

void set_direction(int ir){
  
  /*-------------------------------------------------------------------- 
    set_direction: infrared value -> none 
    Effects: compares sensor "active-ness" to current motor position
    and sets direction (dir) defined above, then sends pos as argument
    to motor_inc
    ---
    Note: pos and dir are global variables, so making them args doesn't 
    really make a difference. Not very nice coding but we're still 
    learning.    
  --------------------------------------------------------------------*/
  
  if(ir > DIST_VAL){ //if sensor is active
    digitalWrite(led,HIGH);//trigger led 13
    if(pos > 0){ //go to 0 = top
      dir = 1;
      pos = motor_inc(pos);
    }else{
      dir = 2;//stay at top = 0
      pos = motor_inc(pos);
    }
  }else{
    digitalWrite(led,LOW);//trigger led 13
    if(pos < 180){ // go to 180 = bottom
      dir = 3;
      pos = motor_inc(pos);
    }else{
      dir = 4;//stay at bottom = 180
      pos = motor_inc(pos);
    }
  }
  //ir = analogRead(irSensorPin);
} 
