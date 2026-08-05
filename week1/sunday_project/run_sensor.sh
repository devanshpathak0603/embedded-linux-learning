#!/bin/bash

echo "Compiling sensor_sim..."
gcc sensor_sim.c -o sensor_sim

echo "Running in raw mode..."
./sensor_sim > sensor_log.txt

echo "Running in average mode..."
./sensor_sim a >> sensor_log.txt

chmod 644 sensor_log.txt

echo "----- Full log -----"
cat sensor_log.txt

echo "----- Ready lines only (grep) -----"
grep "ready" sensor_log.txt

echo "----- Just the readings (awk) -----"
grep "Raw readings" sensor_log.txt | awk '{for(i=3;i<=NF;i++) print $i}'

