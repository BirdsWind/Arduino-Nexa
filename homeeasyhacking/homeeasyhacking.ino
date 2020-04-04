/*
 * Example program using the HomeEasy class.
 */

#include "HomeEasy.h"
#include "payload.h"

struct Payload payload;

HomeEasy homeEasy;


/**
 * Set up the serial interface and the HomeEasy class.
 */
void setup()
{
	// Define payload e.g. in setup
	payload.sender = -1; // read value with receiver.ino
	payload.recipient = -1; // read value with receiver.ino
	payload.command = true; // need to define in code, sets device on or off
	payload.group = false; // read value with receiver.ino
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
  payload.command = true;
  delay(3000);
  homeEasy.sendAdvancedProtocolMessage(payload.sender, payload.recipient, payload.command, payload.group);
  delay(3000);
  payload.command = false;
  homeEasy.sendAdvancedProtocolMessage(payload.sender, payload.recipient, payload.command, payload.group);
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
