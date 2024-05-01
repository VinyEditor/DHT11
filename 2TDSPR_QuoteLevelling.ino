#include <ThingerESP32.h>

// Insira as credenciais do dispositivo configurado na plataforma
#define USERNAME "VInyEditor"
#define DEVICE_ID "ESP32_DEVKIT"
#define DEVICE_CREDENTIAL "Mudar.520"

// Insira as credenciais da sua rede WiFi
#define SSID "Viny"
#define SSID_PASSWORD "phoenix78"
ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

//Insira as variaveis
#include <DHT.h>
#define DHTPIN 17
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float temp, umid;
String idn = "ESP32 - 2TDSPR - Grupo QuoteLevelling";
long randNumber;



void setup() {  
  Serial.begin(115200);
  dht.begin();     
}

void loop() {
  thing.add_wifi(SSID, SSID_PASSWORD); 
  temp = dht.readTemperature();
  umid = dht.readHumidity();
  randNumber = random(300);
  thing["Temperatura"] >> outputValue(temp);
  thing["Umidade"] >> outputValue(umid);
  thing["Identificador"] >> outputValue(idn);
  thing["Randomico"] >> outputValue(randNumber);

  thing.handle();

  delay(1000);
}
