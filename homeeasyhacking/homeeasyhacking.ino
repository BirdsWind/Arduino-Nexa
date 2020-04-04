/*
 * Example program using the HomeEasy class.
 */
#include "HomeEasy.h"
#ifndef PAYLOAD
#include "payload.h"
#endif
#include "secrets.h"
//struct Payload payload;
#define INPUT 1 //0 for demo, 1 for serial
char recievedChar="";
unsigned int recievedValue=99;

HomeEasy homeEasy;


/**
 * Set up the serial interface and the HomeEasy class.
 */
void setup()
{
	// Define payload e.g. in setup
	//payload.sender = -1; // read value with receiver.ino
	//payload.recipient = -1; // read value with receiver.ino
  //payload.command = true; // need to define in code, sets device on or off
	//payload.group = false; // read value with receiver.ino
	Serial.begin(9600);
	
	homeEasy = HomeEasy();
	
	homeEasy.registerSimpleProtocolHandler(printSimpleResult);
	homeEasy.registerAdvancedProtocolHandler(printAdvancedResult);
	
	homeEasy.init();
}


/**
 * No processing is required in the loop for receiving.
 */
void loop()
{
  switch(INPUT){
    case 0:
      demo();
      break;
    case 1:
      serial();
    default:
      break;
  }
  
}

/** Function handles for different inputs **/
void demo(){
  payload.command = true;
  delay(3000);
  homeEasy.sendAdvancedProtocolMessage(payload.sender, payload.recipient, payload.command, payload.group);
  delay(3000);
  payload.command = false;
  homeEasy.sendAdvancedProtocolMessage(payload.sender, payload.recipient, payload.command, payload.group);
}

void serial(){
  /*Reads char from serial
   * 1 = starting the device
   * 0 = stopping the device
   */
  if (Serial.available()){
    recievedChar = Serial.read();
    recievedValue = atoi(recievedChar);
    Serial.println(recievedValue);
    //Reasons yet unknown the char 1 is converted to 1111 by atoi
    if(recievedValue == 1111){
      Serial.println("Starting device");
      payload.command = true;
    }
    else if (recievedValue == 0) {
      Serial.println("Stopping device");
      payload.command = false;
    }
    homeEasy.sendAdvancedProtocolMessage(payload.sender, payload.recipient, payload.command, payload.group);
  }
}


/**
 * Print the details of the advanced protocol message.
 */
void printAdvancedResult(unsigned long sender, unsigned int recipient, bool on, bool group)
{
	Serial.println("advanced protocol message");
	
	Serial.print("sender ");
	Serial.println(sender);
	
	Serial.print("recipient ");
	Serial.println(recipient);
	
	Serial.print("on ");
	Serial.println(on);
	
	Serial.print("group ");
	Serial.println(group);
	
	Serial.println();
}


/**
 * Print the details of the simple protocol message.
 */
void printSimpleResult(unsigned int sender, unsigned int recipient, bool on)
{
	Serial.println("simple protocol message");
	
	Serial.print("sender ");
	Serial.println(sender);
	
	Serial.print("recipient ");
	Serial.println(recipient);
	
	Serial.print("on ");
	Serial.println(on);
	
	Serial.println();
}
