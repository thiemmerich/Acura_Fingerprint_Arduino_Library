/*************************************************** 
  This is a library for our optical Acura Fingerprint sensor

 ****************************************************/

#include "Emmerich_AcuraFingerprint.h"
#include <util/delay.h>

Emmerich_AcuraFingerprint::Emmerich_AcuraFingerprint(HardwareSerial *hs) {
	mySerial = hs;
}

void Emmerich_AcuraFingerprint::begin(uint16_t baudrate) {
	mySerial->begin(baudrate);
}

/**************************************************
   Metodo para deletar usuario atraves do ID
*/
uint8_t Emmerich_AcuraFingerprint::deleteFinger(uint8_t id) {

  uint8_t verify = 1;
  uint8_t sum = 0x56 + id;

  mySerial->write((byte) 0x02); //1 byte
  mySerial->write((byte) 0x54); //1 byte
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) id); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) sum); //1 byte
  mySerial->write((byte) 0x00); //1 byte

  return verify = ackPacket();
}

/**************************************************
   Metodo que inicia o cadastro de usuario master
*/
uint8_t Emmerich_AcuraFingerprint::registerMasterStart(uint8_t id) {

  uint8_t verify = 1;
  uint8_t sum = 0x53 + id;

  mySerial->write((byte) 0x02); //1 byte
  mySerial->write((byte) 0x50); //1 byte
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) id); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x01); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) sum); //1 byte
  mySerial->write((byte) 0x00); //1 byte

  delay(5100);

  return verify = ackPacket();
}
/**************************************************
   Metodo que finaliza o cadastro de usuario master
*/
uint8_t Emmerich_AcuraFingerprint::registerMasterEnd(uint8_t id) {

  uint8_t verify = 1;
  uint8_t sum = 0x54 + id;

  mySerial->write((byte) 0x02); //1 byte
  mySerial->write((byte) 0x51); //1 byte
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) id); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x01); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) sum); //1 byte
  mySerial->write((byte) 0x00); //1 byte

  delay(5100);

  return verify = ackPacket();
}

/**************************************************
    Metodo que inicia o registro de usuario normal
*/
uint8_t Emmerich_AcuraFingerprint::registerFingerStart(uint8_t id) {

  uint8_t verify = 1;
  uint8_t sum = 0x52 + id;

  mySerial->write((byte) 0x02); //1 byte
  mySerial->write((byte) 0x50); //1 byte
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) id); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) sum); //1 byte
  mySerial->write((byte) 0x00); //1 byte

  delay(5100);

  return verify = ackPacket();
}

/**************************************************
   Metodo que finaliza o registro de usuario normal
*/
uint8_t Emmerich_AcuraFingerprint::registerFingerEnd(uint8_t id) {

  uint8_t verify = 1;
  uint8_t sum = 0x53 + id;

  mySerial->write((byte) 0x02); //1 byte
  mySerial->write((byte) 0x51); //1 byte
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) id); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) sum); //1 byte
  mySerial->write((byte) 0x00); //1 byte

  delay(5100);

  return verify = ackPacket();
}

/**************************************************
   Metodo para verificar se a digital é de um usuario Master
*/
uint8_t Emmerich_AcuraFingerprint::masterFingerVerify(void) {

  uint8_t verify = 1;

  mySerial->write((byte) 0x02); //Start command 1 byte
  mySerial->write((byte) 0x57); //Command 1 byte
  mySerial->write((byte) 0x00); //System Id 2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //First parameter 4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //Second parameter 4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //Length of the extra data 4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //Result command (Error code) 2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x59); //Checksum 1 byte
  mySerial->write((byte) 0x00); //Extra Checksum 1 byte

  return verify = ackPacket();

}

/**************************************************
   Metodo para desativar o 'Auto Sensing'
*/
uint8_t Emmerich_AcuraFingerprint::disableAuto(void) {

  uint8_t verify = 1;

  mySerial->write((byte) 0x02); //1 byte
  mySerial->write((byte) 0x1A); //1 byte
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x01); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x1D); //1 byte
  mySerial->write((byte) 0x00); //1 byte

  return verify = ackPacket();
}

/**************************************************
   Metodo para ativar o 'Auto Sensing'
*/
uint8_t Emmerich_AcuraFingerprint::enableAuto(void) {

  uint8_t verify = 1;

  mySerial->write((byte) 0x02); //1 byte
  mySerial->write((byte) 0x1A); //1 byte
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x01); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x1E); //1 byte
  mySerial->write((byte) 0x00); //1 byte

  return verify = ackPacket();
}

/**********************************************************
 * Metodo para mostrar a quantidade de usuarios cadastrados
 */
uint8_t Emmerich_AcuraFingerprint::getCount(void) {

  mySerial->write((byte) 0x02); //1 byte
  mySerial->write((byte) 0x46); //1 byte
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x48); //1 byte
  mySerial->write((byte) 0x00); //1 byte

  uint8_t packet[20];
  uint8_t contador = 0;
  delay(10);

  while (mySerial->available()) {
    packet[contador] = mySerial->read();
    contador++;
  }
  return packet[4];
}

/**************************************************
   Metodo para receber ultimo id utilizado
*/
uint8_t Emmerich_AcuraFingerprint::getLastUserId(void) {

  mySerial->write((byte) 0x02); //1 byte
  mySerial->write((byte) 0x7D); //1 byte
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //4 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x00); //2 bytes
  mySerial->write((byte) 0x00);
  mySerial->write((byte) 0x7F); //1 byte
  mySerial->write((byte) 0x00); //1 byte

  uint8_t packet[20];
  uint8_t len = 0;
  uint8_t contador = 0;
  uint8_t contador2 = 0;
  delay(10);

  while (mySerial->available()) {
    packet[contador] = mySerial->read();
    contador++;
    if (contador == 20) {
      break;
    }
  }
  len = (packet[4] * 4);
  uint8_t list[len];

  while (mySerial->available()) {
    list[contador2] = mySerial->read();
    contador2++;
  }
  if (packet[16] == 0) {
    return list[len - 4];
  }
  return -1;
}

/**************************************************
   Metodo que recebe os pacotes do dispositivo
*/
uint8_t Emmerich_AcuraFingerprint::ackPacket(void) {

  uint8_t packet[20];
  uint8_t contador = 0;
  while (mySerial->available()) {
    packet[contador] = mySerial->read();
    contador++;
  }
  return packet[16];
}