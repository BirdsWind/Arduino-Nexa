# Arduino-Nexa



## Overview

Use Arduino, 433Mhz transmitter,receiver and Nexa remote switch to turn on and off real lamp.

### Step 1: Material 

- Arduino uno board
+ Jumper wires
+ [433Mhz Transimitter](http://www.kjell.com/sortiment/el/elektronik/fjarrstyrning/433-mhz-sandarmodul-p88901)  
+ [433Mhz receiver](http://www.kjell.com/sortiment/el/elektronik/fjarrstyrning/433-mhz-mottagarmodul-p88900)
- Standard solderless breadboard
- [Nexa remote switch](http://www.nexa.se/EYCR2300.htm)
- Lamp

### Step 2: Set up Arduino with transimitter and receiver



![alt text](https://raw.githubusercontent.com/TokyoBirdy/Arduino-Nexa/master/IMG_8288.JPG)



To build the circuit, connect one end of the resistor to Arduino pin 13. Connect the long leg of the LED (the positive leg, called the anode) to the other end of the resistor. Connect the short leg of the LED (the negative leg, called the cathode) to the Arduino GND.



### Step 3: Communicate Arduino with shell script

Download [Arduino-serial utility](http://todbot.com/blog/2006/12/06/arduino-serial-c-code-to-talk-to-arduino/comment-page-2/) which enables o communicate directly with the arduino from the shell script. Place it in the root of your user directory, then open up a terminal and type:

```
make arduino-serial

```
Connect your arduino with the computer and then in the terminal type:

```
ls /dev/tty.*
```

to figure out which port your arduino is on. Mine is /dev/tty.usbmodem1411. And replace it with your own port. Then try to run this line of code in terminal and see if it works 

```
./arduino-serial -b 9600 -p /dev/tty.usbmodem1411 -s lightsOn

```


My output is:

```
opened port /dev/tty.usbmodem1411
send string:lightsOn
```

Now create a shell script file in the root directory. Name it lightson.sh. Put this line in it, again with your own port 

```
./arduino-serial -b 9600 -p /dev/tty.usbmodem1411 -s lightsOn

```


### Step 4: Use Automator to run shell script

Open Automator, and create a new **application**. Find the **Run a shell Script** action and drag/add it. 

In the shell script, write 

```
sh ~/lightson.sh

```

**~/lightson.sh** is the directory where you put your shell script, I put it in the root directory.



save it to **library/speech/Speakable Items** and name it "lights on".


### Step 5: Finally voice control

Go to **system preference**, then **Accessibility**, scroll down and find **Dictation**, Click **Dictation Commands** Click **+** button to add new commands. When I say **lights on** while using: **Any Application** Perform  open app and find lightson.app in the directory of **~/Library/Speech/Speakable\ Items/lights\ on.app** Finally click **Done**. now you have hooked up your voice with the shell script by running the lighton.app.
 
![alt text](https://raw.githubusercontent.com/TokyoBirdy/Voice-control-lights-on-and-off/master/Dictation.png)


### Step 5: Run arduino 

Open arduino app, and use the code in this repository called voice-control.ino, and run on the arduino you have build on step one.




### Step 5: Final step, voice control 

Go to **system preference** and search for speech. Set the short cut. In my case I press Left Command key twice. 

![alt text](https://raw.githubusercontent.com/TokyoBirdy/Voice-control-lights-on-and-off/master/Speech.png)


Now click Left Command key twice and say "lights on", "light off", Enjoy! 


### Youtube video  

[Voice control led turn on and off showcase](https://www.youtube.com/watch?v=GKyTyhMJvg4)