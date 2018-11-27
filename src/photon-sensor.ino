#include "Si70xx.h"
#include "MPU9150.h"
#include "Si1132.h"

// TCPClient client;
// const byte SERVER[] = {10,42,72,159};
// const int PORT = 5000;

long time_reading = 0;

Si70xx tempAndHum;
Si1132 light;

void setup()
{
  Serial.begin(9600);
  tempAndHum.begin();
  light.begin();
}

void loop()
{
  float temp = tempAndHum.readTemperature();
  float hum = tempAndHum.readHumidity();
  float visible = light.readVisible();

  //Particle.publish("photonSensorData", sensorString, PRIVATE);
  time_reading = Time.now();
  sendMessage(temp, hum, visible);
  delay(1000);
}

void sendMessage(float temp, float hum, float visible)
{
  // if(client.connect(SERVER, PORT))
  // {
  //   if(client.connected())
  //   {
  //     String json = "{\"timestamp\": "+ String(time_reading) +", \"temperature\": " + String(temp, 2) + ",\n\"humidity\": " + String(hum, 2) + ",\n\"light\": " + String(visible, 2) + ",\n\"zone\": 1}";
  //     client.println("POST /smartroom/data/thl HTTP/1.1");
  //     client.println("Connection: keep-alive");
  //     client.println("Host: 10.42.72.159");
  //     client.println("Content-Type: application/json;charset=utf8");
  //     client.print("Content-Length: ");
  //     client.println(json.length());
  //     client.println();
  //     client.println(json);
  //     delay(100);
  //   }
  //   client.stop();
  // }
  // Serial.println("Cannot connect to server");
  Serial.println(String(temp, 2));
  Serial.println(String(hum, 2));
  Serial.println(String(visible, 2));
}