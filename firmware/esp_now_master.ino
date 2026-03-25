// Anexo 14: Código del Maestro ESP-NOW

#include <ESP8266WiFi.h>
#include <espnow.h>
#include <DHT.h>
// Direccion MAC del esclavo (Reemplazala con la direccion de tu ESP-01 esclavo)
uint8_t macEsclavo[] = {0x24, 0x6F, 0x28, 0xXX, 0xXX, 0xXX};
// Definir el pin y tipo del sensor DHT11
#define DHTPIN 2  // GPIO2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
// Estructura para enviar datos
typedef struct struct_message {
float temperatura;
float humedad;
} struct_message;
struct_message datosEnviar;
// Callback de envio
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
Serial.print("Estado de envio: ");
Serial.println(sendStatus == 0 ? "Exito" : "Fallo");
}
void setup() {
Serial.begin(115200);
WiFi.mode(WIFI_STA);
dht.begin();
if (esp_now_init() != 0) {
Serial.println("Error al inicializar ESP-NOW");
return;
}
esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
esp_now_register_send_cb(OnDataSent);
esp_now_add_peer(macEsclavo, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
Serial.println("Maestro ESP-NOW listo...");
}
void loop() {
datosEnviar.humedad = dht.readHumidity();
datosEnviar.temperatura = dht.readTemperature();
if (isnan(datosEnviar.humedad) || isnan(datosEnviar.temperatura)) {
Serial.println("Error al leer del DHT11")
return;
}
Serial.print("Enviando -> ");
Serial.print("Temperatura: ");
Serial.print(datosEnviar.temperatura);
Serial.print("C, Humedad: ");
Serial.print(datosEnviar.humedad);
Serial.println("%");
esp_now_send(macEsclavo, (uint8_t *)&datosEnviar, sizeof(datosEnviar));
delay(10000);  // Enviar cada 10 segundos
}
