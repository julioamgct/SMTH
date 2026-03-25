// Anexo 13: Código del Esclavo ESP-NOW

#include <ESP8266WiFi.h>
#include <espnow.h>
// Estructura para recibir datos
typedef struct struct_message {
float temperatura;
float humedad;
} struct_message;
struct_message datosRecibidos;
// Funcion callback cuando se reciben datos
void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
memcpy(&datosRecibidos, incomingData, sizeof(datosRecibidos));
Serial.print("Datos recibidos -> ");
Serial.print("Temperatura: ");
Serial.print(datosRecibidos.temperatura);
Serial.print("C, Humedad: ");
Serial.print(datosRecibidos.humedad);
Serial.println("%");
}
void setup() {
Serial.begin(115200);
WiFi.mode(WIFI_STA);
if (esp_now_init() != 0) {
Serial.println("Error al inicializar ESP-NOW");
return;
}
esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
esp_now_register_recv_cb(OnDataRecv);
Serial.println("Esclavo ESP-NOW listo...");
}
void loop() {
delay(1000);

}
