int motor_inc(int pos_){
  /*-------------------------------------------------------------------- 
     motor_inc: integer -> None
     Effects: Increments the servo motor position by iteration based 
     on direction (dir) of arm.  
     
  --------------------------------------------------------------------*/
  if(dir == 3){ // go to bottom
    pos_ += INC;
  }else if (dir == 1){ // go to top
    pos_ -= INC;
  }else{ // stay
     // do nothing
  }

  servo_1.write(pos_);
  servo_2.write(pos_);
  servo_3.write(pos_);
  servo_4.write(pos_);
  delay(30);
  return pos_;
}
