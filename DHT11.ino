#include <DHT.h>

#define DHTPIN 17
#define DHTTYPE DHT11
#define LED 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  dht.begin();

}

void loop() {
  leituraDHT();

}

void leituraDHT(){
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();
  
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" - ");
  Serial.print("Umidade: ");
  Serial.print("umid");
   
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED,LOW);
  delay(2000);
}
