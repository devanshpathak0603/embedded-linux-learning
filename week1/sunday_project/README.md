# Sunday Mini-Project — Simulated Sensor Status Logger

Combines Week 1 concepts (C: bitfields, malloc/free, function pointers; Linux: permissions, grep, awk) into one working example.

## What it does
- `sensor_sim.c` simulates a sensor status register using a bitfield struct (ready/error/mode), 
  dynamically allocates readings with malloc, and uses a function pointer to switch between 
  raw and averaged output modes based on a command-line argument.
- `run_sensor.sh` compiles the program, runs both modes, logs output to a file, sets file 
  permissions, and uses grep/awk to filter and extract specific data from the log.

## Usage
./run_sensor.sh

## Why this matters
This mirrors the real pattern I'll use on actual kiosk sensors later in this course: reading 
hardware status via bitfields, handling dynamic data safely, and selecting behavior (raw vs. 
processed output) through function pointers — the same mechanism the Linux kernel uses to call 
driver code via struct file_operations.
