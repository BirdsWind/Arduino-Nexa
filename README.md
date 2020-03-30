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


### 1. Setup nexa

Setup your nexa remote switch with your desired electronic, e.g. lamp based on instructions that you received when bought nexa device. Pair it it with the remote where you read the sender id

### 2. Read sender ID

In order to use the following script you will first need to get sender ID from remote controller.

#### Setup Arduino and 433 MHz receiver

Connect RF receiver data cable to Arduino D2 port.

Connect RF receiver VCC to 5V pin and GND to Arduino GND.

![Arduino RF receiver diagram](https://github.com/Atihinen/Arduino-Nexa/raw/master/media/receiver_diagram.png)

#### Read the ID with Arduino

Deploy rf_receiver.ino to Arduino from receiver/rf_receiver.ino

Open serial monitor to correct port and press the desired button from remote to read sender id.


### 3. Start using your arduino as remote

#### Setup Arduino and 433MHz transmitter

Connect RF transmitter data cable to Arduino D13 port.

Connect RF transmitter VCC to 5V pin and GND to Arduino GND.

![Arduino RF transmitter diagram](https://github.com/Atihinen/Arduino-Nexa/raw/master/media/transmitter_diagram.png)

#### Setup the code

TBD