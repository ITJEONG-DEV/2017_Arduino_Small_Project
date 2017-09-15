#include <ESP8266WiFi.h>
#include <DHT.h>
#define DHTPIN 0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "MCU_2G";
const char* password = "newdimigo";
const char* host = "iot.dimigo.org";

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.print("\r\nConnecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED )
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

unsigned long beforeTime = 0;

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  unsigned long nowTime = millis();
  if(nowTime - beforeTime < 10000) return;
  beforeTime = nowTime;
  digitalWrite(LED_BUILTIN, LOW);
  Serial.print("connecting to ");
  Serial.println(host);
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort))
  {
    Serial.println("connection failed");
    return;
  }
  
  int section= 10;
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  String url = "/0000/DHT_push.php?";
  url += "section=";
  url += section;
  url += "&temp=";
  url += temp;
  url += "&humi=";
  url += humi;
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to theserver
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0)
  {
    if (millis() - timeout > 5000)
    {
      Serial.println(">>> ClientTimeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while(client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
}
