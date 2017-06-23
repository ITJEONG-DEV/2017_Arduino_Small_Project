#include <VirtualWire.h>
#define RF433_RX  7
#define LED    10
#define BROADCAST_ID  255
#define MY_ID   22x 

typedef struct 
{ 
  int sID;  // source ID 
  int dID;  // destination ID 
  int serial;  // packet serial 
  boolean isOn; 
  char message[20]; 
} RFPacket;

byte message[VW_MAX_MESSAGE_LEN]; 
byte messageLength = VW_MAX_MESSAGE_LEN; 

void setup() 
{ 
  pinMode(LED, OUTPUT); 
  Serial.begin(9600);

  vw_setup(2000); 
  vw_set_rx_pin(RF433_RX);     //수신 핀 설정 
  vw_rx_start();               //수신 시작
}

void loop() 
{ 
  if (vw_get_message(message, &messageLength)) 
  {       //메세지 읽어옴 
    if(messageLength < sizeof(RFPacket)) 
    { 
      Serial.println("Wrong packet received."); 
      return; 
    }
  RFPacket *packet = (RFPacket *)message;    
  
  if(packet->dID == MY_ID || packet->dID == BROADCAST_ID) printPacket(packet);
  
  if(packet->isOn) digitalWrite(LED, HIGH);   //LED ON 
  else digitalWrite(LED, LOW);    //LED OFF
  }  
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
