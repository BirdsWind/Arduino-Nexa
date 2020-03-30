# Arduino-Nexa

## Overview

Use Arduino, 433Mhz transmitter,receiver and Nexa remote switch to turn on and off real electric device

## HW requirements

- Arduino Nano board
+ Jumper wires
+ [433Mhz Transimitter](http://www.kjell.com/sortiment/el/elektronik/fjarrstyrning/433-mhz-sandarmodul-p88901)  
+ [433Mhz receiver](http://www.kjell.com/sortiment/el/elektronik/fjarrstyrning/433-mhz-mottagarmodul-p88900)
- Standard solderless breadboard
- [Nexa remote switch](http://www.nexa.se/EYCR2300.htm)

## SW requirements

- [Arduino IDE](https://www.arduino.cc/en/main/software)

## Preparations

### 1 Read sender ID

In order to use the following script you will first need to get sender ID from remote controller.

#### Setup Arduino and 433 Mhz and receiver



### Step 2: Set up Arduino with 433Mhz transimitter and receiver



![alt text](https://raw.githubusercontent.com/TokyoBirdy/Arduino-Nexa/master/arduino%20set%20up.JPG)


[This link](http://www.kjell.com/sortiment/el/elektronik/fjarrstyrning/433-mhz-sandarmodul-p88901#ProductDetailedInformation) has a pretty explanation about datasheet about transmitter, and [this one](http://www.kjell.com/sortiment/el/elektronik/fjarrstyrning/433-mhz-mottagarmodul-p88900#ProductDetailedInformation) for receiver. After you read through the datasheets, you should be able to understand how to connect the pins to the arduino. 




### Step 3: Use Nexa with Lamp

![alt text](https://raw.githubusercontent.com/TokyoBirdy/Arduino-Nexa/master/nexa%20set%20up%20.JPG)



### Step 4: Receiver test 

Run rf_receiver.ino on Arduino, you should be able to see output. Mine looks like this

	sender 15556058
	no group
	on
	recipient 13

	sender 15556058
	no group
	off
	recipient 13


### Step 5: Final step! Hack

Change the data in homehackingeasy.ino according to the result we got from the above. 

	unsigned long sender = 2051610;
	unsigned int recipient = 0;
	bool command = true;
	bool group = false;
	
Now run^^



### Youtube video  

[Arduino and nexa to turn on and off real lamp](https://youtu.be/ymzCeY9fIyU)