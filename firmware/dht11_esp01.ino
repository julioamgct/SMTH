// Anexo 12: Código para leer temperatura y humedad con ESP-01 y DHT11
#include <ESP8266WiFi.h>
#include <DHT.h>
// Definir el pin del DHT11
#define DHTPIN 2  // GPIO2 (D4 en el ESP-01)
#define DHTTYPE DHT11
// Inicializar el sensor
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(115200);
Serial.println("Inicializando sensor DHT11...");
dht.begin();
}
void loop() {
// Leer los valores de temperatura y humedad
float h = dht.readHumidity();
float t = dht.readTemperature();
// Verificar si la lectura es valida
if (isnan(h) || isnan(t)) {
Serial.println("Error al leer del sensor DHT11!");
return;
}
// Mostrar los datos en el monitor serie
Serial.print("Humedad: ");
Serial.print(h);
Serial.print(" %");
Serial.print("Temperatura: ");
Serial.print(t);
Serial.println(" C");
// Esperar 10 segundos antes de la siguiente lectura
delay(10000);

}
