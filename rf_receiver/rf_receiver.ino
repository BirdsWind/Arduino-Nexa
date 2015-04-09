/*
 * AM-HRR3 receiver test
 *
 * Homeeasy protocol receiver for the new protocol.
 *
 * This protocol isn't documented so well, so here goes (this is largely from memory).
 *
 * The data is encoded on the wire (aerial) as a Manchester code.
 *
 * A latch of 275us high, 2675us low is sent before the data.
 * There is a gap of 10ms between each message.
 *
 * 0 = holding the line high for 275us then low for 275us.
 * 1 = holding the line high for 275us then low for 1225us.
 * 
 * The timings seem to vary quite noticably between devices.  HE300 devices have a
 * low for about 1300us for a 1 whereas HE303 devices seem to have a low of about
 * 1100us.  If this script does not detect your signals try relaxing the timing
 * conditions.
 * 
 * Each actual bit of data is encoded as two bits on the wire as:
 * Data 0 = Wire 01
 * Data 1 = Wire 10
 *
 * The actual message is 32 bits of data (64 wire bits):
 * bits 0-25: the group code - a 26bit number assigned to controllers.
 * bit 26: group flag
 * bit 27: on/off flag
 * bits 28-31: the device code - a 4bit number.
 *
 * The group flag just seems to be a separate set of addresses you can program devices
 * to and doesn't trigger the dim cycle when sending two ONs.
 *
 * There's extra support for setting devices to a specific dim-level that you get
 * with the HE100 ultimate remote control. I think this involves sending a Wire 11 at
 * the on/off flag position and then the message is longer with another 4 bits for dim
 * level.
 * Need to look into this.
 *
 * Barnaby Gray 12/2008
 * Peter Mead   09/2009
 */

int rxPin = 8;


void setup()
{	pinMode(rxPin, INPUT);
	Serial.begin(9600);
}


void loop()
{
	int i = 0;
	unsigned long t = 0;

	byte prevBit = 0;
	byte bit = 0;

	unsigned long sender = 0;
	bool group = false;
	bool on = false;
	unsigned int recipient = 0;

	// latch 1
	while((t < 9480 || t > 10350))
	{	t = pulseIn(rxPin, LOW, 1000000);
	}

	// latch 2
	while(t < 2550 || t > 2700)
	{	t = pulseIn(rxPin, LOW, 1000000);
	}

	// data
	while(i < 64)
	{
		t = pulseIn(rxPin, LOW, 1000000);

		if(t > 200 && t < 365)
		{	bit = 0;
		}
		else if(t > 1000 && t < 1360)
		{	bit = 1;
		}
		else
		{	i = 0;
			break;
		}

		if(i % 2 == 1)
		{
			if((prevBit ^ bit) == 0)
			{	// must be either 01 or 10, cannot be 00 or 11
				i = 0;
				break;
			}

			if(i < 53)
			{	// first 26 data bits
				sender <<= 1;
				sender |= prevBit;
			}	
			else if(i == 53)
			{	// 26th data bit
				group = prevBit;
			}
			else if(i == 55)
			{	// 27th data bit
				on = prevBit;
			}
			else
			{	// last 4 data bits
				recipient <<= 1;
				recipient |= prevBit;
			}
		}

		prevBit = bit;
		++i;
	}

	// interpret message
	if(i > 0)
	{	printResult(sender, group, on, recipient);
	}
}


void printResult(unsigned long sender, bool group, bool on, unsigned int recipient)
{
	Serial.print("sender ");
	Serial.println(sender);

	if(group)
	{	Serial.println("group command");
	}
	else
	{	Serial.println("no group");
	}

	if(on)
	{	Serial.println("on");
	}
	else
	{	Serial.println("off");
	}

	Serial.print("recipient ");
	Serial.println(recipient);

	Serial.println();
}
