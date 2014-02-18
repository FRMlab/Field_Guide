grow_op
=======

##### Description
Arduino-based, responsive installation for Toronto's Gladstone Hotel

##### Module
This is the code for one module in the Grow-op surface. Each module consists of a motor controlling an arm and a inrared sensor. The infrared sensor detects proximity (i.e someone reaching out to the surface) and sends instructions to the motor to retract the arm accordingly. Each module is local and not 'aware' of it's neighbors.
  
  
##### How it works:
```
  a     b     c     d     e
    
        |    
        |    
  |-----|-----\-----|-----|
  |            \    |     |
  |             \   |     |
```  
For module a-e. Module b's ir sensor and motor activity will not effect it's neighbors. In this case Module's c's ir sensor is also triggered by activity. This is what gives the surface's cascading effect, cheaply and effectively.  
  
---
  
START
```  
  ____|
      |
      |
      |
```
starting: pos = 180; dir = 4 (stay at bottom)    
  
  
MOVE UP
```
         /
        /
       /
  ----/     
```
moving: 0 > pos < 180; dir = 1 (go to top)
  
  
MOVE DOWN
```
  ----\
       \
        \
         \
```
if ir sensor is not active, dir = 3 (go to bottom) and then dir = 4 (stay at bottom)
  
MAX
```
      | 
      |      
      |
  ----|
```
end position, fully retracted: pos = 0
Once ir sensor is not active, the arm will move down and rest  
