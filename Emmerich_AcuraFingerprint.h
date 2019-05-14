/*************************************************** 
  This is a library for our optical Acura Fingerprint sensor
****************************************************/

#include "Arduino.h"

class Emmerich_AcuraFingerprint {
	
 public:
	Emmerich_AcuraFingerprint(HardwareSerial *ss);

	void begin(uint16_t baudrate);
	uint8_t deleteFinger(uint8_t id);
	uint8_t registerMasterStart(uint8_t id);
	uint8_t registerMasterEnd(uint8_t id);
	uint8_t registerFingerStart(uint8_t id);
	uint8_t registerFingerEnd(uint8_t id);
	uint8_t masterFingerVerify(void);
	uint8_t disableAuto(void);
	uint8_t enableAuto(void);
	uint8_t getCount(void);
	uint8_t getLastUserId(void);
	uint8_t ackPacket(void);
  
 private: 
  HardwareSerial *mySerial;
};

