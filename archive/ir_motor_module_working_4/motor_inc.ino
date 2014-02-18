
// motor_inc: None -> None
// Effects: The function increments the servo motor position by iteration based on
// direction of arm

int motor_inc(int pos_)
{  
  if(dir == 3){ // go to bottom
    pos_ += inc;
  }else if (dir == 1){ // go to top
    pos_ -= inc;
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
