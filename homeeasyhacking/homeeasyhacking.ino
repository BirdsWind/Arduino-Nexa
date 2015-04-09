/*
 * Example program using the HomeEasy class.
 */

#include "HomeEasy.h"

HomeEasy homeEasy;


/**
 * Set up the serial interface and the HomeEasy class.
 */
void setup()
{
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
  delay(3000);
	unsigned long sender = 2051610;
	unsigned int recipient = 0;
	bool command = true;
	bool group = false;
  homeEasy.sendAdvancedProtocolMessage(sender, recipient, command, group);
  delay(3000);
  command = false;
  homeEasy.sendAdvancedProtocolMessage(sender, recipient, command, group);
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
