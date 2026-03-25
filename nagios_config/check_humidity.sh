# Anexo:23 Archivo Check-humedad de script Bash para monitorear humedad
#!/bin/bash

if [ -z "$1" ]; then
  echo "CRITICAL: No sensor number provided."
  exit 2
fi

SENSOR_NUM=$1
ULTIMOS_DATOS=$(tail -n 16 /var/www/your_domain/sensores.txt)
DATOS=$(echo "$ULTIMOS_DATOS" | grep "^${SENSOR_NUM},")

if [ -z "$DATOS" ]; then
  echo "UNKNOWN: Could not retrieve humidity for sensor $SENSOR_NUM."
  exit 3
fi

HUMEDAD=$(echo $DATOS | cut -d',' -f3 | awk '{print int($1)}')

if [ "$HUMEDAD" -gt 80 ]; then
  echo "CRITICAL: Sensor $SENSOR_NUM - Humidity ${HUMEDAD}% | humedad=${HUMEDAD};"
  exit 2
elif [ "$HUMEDAD" -ge 60 ] && [ "$HUMEDAD" -le 80 ]; then
  echo "WARNING: Sensor $SENSOR_NUM - Humidity ${HUMEDAD}% | humedad=${HUMEDAD};"
  exit 1
elif [ "$HUMEDAD" -lt 60 ]; then
  echo "OK: Sensor $SENSOR_NUM - Humidity ${HUMEDAD}% | humedad=${HUMEDAD};"
  exit 0
else
  echo "UNKNOWN: Invalid humidity for sensor $SENSOR_NUM."
  exit 3
fi
