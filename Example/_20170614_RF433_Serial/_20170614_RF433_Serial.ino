#include <VirtualWire.h>
#include <Bounce2.h>

#define RF433_TX 7
#define LED 11

#define BROADCAST_ID 255
#define SRC_ID 22
#define DST_ID 30

typedef struct
{
  int sID;
  int dID;
  int serial;
  boolean isOn;
  char message[20];
}RFPacket;

RFPacket *packet;

boolean isOn = false;
int serial = 0;

Bounce bouncer = Bounce();

void setup()
{
  packet = (RFPacket *)malloc(sizeof(RFPacket));
  packet->sID = SRC_ID;
  packet->dID = DST_ID;

  vw_setup(2700);
  vw_set_tx_pin(RF433_TX);

  Serial.begin(9600);
}

void loop()
{
  for( int i = 1; i<20; i++ ) packet->message[i] = NULL;
  
  if( Serial.available() )
  {
    byte a = Serial.readBytes(packet->message, 20);
    packet->serial = serial++;
    packet->isOn = isOn;
    vw_send((uint8_t *)packet, sizeof(RFPacket));
    vw_wait_tx();
    isOn = !isOn;
    printPacket(packet);
    sendMessage(packet);
  }
}

void sendMessage( int data )
{
  vw_send((uint8_t *)data, sizeof(RFPacket));
  vw_wait_tx();
}

void printPacket(RFPacket *packet)
{
  Serial.print("Source ID: ");
  Serial.println(packet->sID, DEC);
  Serial.print("Destination ID: "); 
  Serial.println(packet->dID, DEC); 
  Serial.print("Packet serial: "); 
  Serial.println(packet->serial, DEC); 
  Serial.print("Switch: "); 
  Serial.println(packet->isOn, DEC); 
  Serial.print("Message: "); 
  Serial.println(packet->message); 
  Serial.println();

}

