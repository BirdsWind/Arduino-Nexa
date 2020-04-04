struct Payload {
    unsigned long sender; // Nexa remote sender ID, read with receiver.ino
	unsigned int recipient; // Nexa remote switch value, read with receiver.ino
	bool command; // true == nexa remote switch is on, false == nexa remote switch is off
	bool group; // is the nexa remote switch grouped or not, read with receiver.ino
}