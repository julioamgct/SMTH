# Anexo 22: Archivo Check-temperatura de script Bash para monitorear temperatura

#!/bin/bash

if [ -z "$1" ]; then
  echo "CRITICAL: No sensor number provided."
  exit 2
fi

SENSOR_NUM=$1
ULTIMOS_DATOS=$(tail -n 16 /var/www/your_domain/sensores.txt)
DATOS=$(echo "$ULTIMOS_DATOS" | grep "^${SENSOR_NUM},")

if [ -z "$DATOS" ]; then
  echo "UNKNOWN: Could not retrieve temperature for sensor $SENSOR_NUM."
  exit 3
fi

TEMPERATURA=$(echo $DATOS | cut -d',' -f2 | awk '{print int($1)}')

if [ "$TEMPERATURA" -gt 37 ]; then
  echo "CRITICAL: Sensor $SENSOR_NUM - Temperature ${TEMPERATURA} C | temperatura=${TEMPERATURA};"
  exit 2
elif [ "$TEMPERATURA" -ge 26 ] && [ "$TEMPERATURA" -le 36 ]; then
  echo "WARNING: Sensor $SENSOR_NUM - Temperature ${TEMPERATURA} C | temperatura=${TEMPERATURA};"
  exit 1
elif [ "$TEMPERATURA" -lt 25 ]; then
  echo "OK: Sensor $SENSOR_NUM - Temperature ${TEMPERATURA} C | temperatura=${TEMPERATURA};"
  exit 0
else
  echo "UNKNOWN: Invalid temperature for sensor $SENSOR_NUM."
  exit 3
fi
