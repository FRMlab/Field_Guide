Field Guide
=======

##### Description
Arduino-based, responsive installation for Toronto's Gladstone Hotel

<br>
<p align="center">
  <img src="https://googledrive.com/host/0B1aL4rZ85UMSbkRUNnVKN2RuWjg/"> 
</p>
<br>

##### License


The Field Guide code is made available under the GNU General Public License. For details see the LICENSE file.
    <br>
    <br>
    Copyright (C) 2013-2014  F_RMlab

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.


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
