#include <VirtualWire.h>
#include <Bounce2.h>

#define B1 3
#define B2 4
#define B3 5
#define B4 6

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
  pinMode( B1, INPUT_PULLUP );
  digitalWrite( B1, HIGH );
  pinMode( B2, INPUT_PULLUP );
  digitalWrite( B2, HIGH );
  pinMode( B3, INPUT_PULLUP );
  digitalWrite( B3, HIGH );
  pinMode( B4, INPUT_PULLUP );
  digitalWrite( B4, HIGH );

  bouncer.attach( B1 );
  bouncer.interval(5);
  bouncer.attach( B2 );
  bouncer.interval(5);
  bouncer.attach( B3 );
  bouncer.interval(5);
  bouncer.attach( B4 );
  bouncer.interval(5);

  packet = (RFPacket *)malloc(sizeof(RFPacket));
  packet->sID = SRC_ID;
  packet->dID = DST_ID;

  vw_setup(2700);
  vw_set_tx_pin(RF433_TX);

  Serial.begin(9600);
}

void loop()
{
  if( bouncer.update() && bouncer.read() == LOW )
  {
    packet->serial = serial++;
    packet->isOn = isOn;
    strcpy(packet->message, "happy dimigo life");
    printPacket(packet);
    sendMessage(packet);
    isOn = !isOn;
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

