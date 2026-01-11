# IoT Alarm System – Stage 4

**Course:** COMP-10184  
**Author:** Yash Khanduja  
**Student ID:** 000826385  

---

## Overview

This project implements a motion-based alarm system using a PIR sensor, a push button, and the built-in LED on an Arduino-compatible board.  
The system detects motion, starts a countdown, and activates an alarm if it is not disarmed in time.

---

## Hardware Used

- Arduino-compatible board  
- PIR Motion Sensor  
- Push Button  
- Built-in LED  

---

## Pin Configuration

| Component | Pin |
|---------|-----|
| PIR Sensor | D5 |
| Button | D6 |
| LED | LED_BUILTIN |

> Button uses `INPUT_PULLUP` (active LOW)

---

## Alarm States

- **Enabled** – System armed and waiting for motion  
- **Countdown** – Motion detected, LED blinks  
- **Active** – Alarm triggered, LED stays ON  
- **Disabled** – Not used in this stage  

---

## Working Logic

1. PIR sensor calibrates on startup  
2. Motion detection starts countdown  
3. LED blinks during countdown  
4. Button press resets the system  
5. No button press activates the alarm  

---

## LED Behavior

- OFF → Idle  
- Blinking → Countdown  
- ON → Alarm active  

---

## Serial Output

- Motion detection time  
- Button press time  
- System status messages  

---

## Declaration

I, **Yash Khanduja (000826385)**, hereby declare that this is my own work.

