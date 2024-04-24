#include <ThingerESP32.h>

// Insira as credenciais do dispositivo configurado na plataforma
#define USERNAME "VInyEditor"
#define DEVICE_ID "ESP32_DEVKIT"
#define DEVICE_CREDENTIAL "Mudar.520"

// Insira as credenciais da sua rede WiFi
#define SSID "Viny"
#define SSID_PASSWORD "phoenix78"
ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);



void setup() {  
  Serial.begin(115200);   
  dht.begin();
}

void loop() {
  thing.add_wifi(SSID, SSID_PASSWORD); 
  temp = dht.readTemperature();
  umid = dht.readHumidity();
  delay(2000);
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" - ");
  Serial.print("Umidade: ");
  Serial.println(umid);

  thing.handle();

  delay(1000);
}

void leituraDHT(){
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();
  
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" - ");
  Serial.print("Umidade: ");
  Serial.print("umid");

}
