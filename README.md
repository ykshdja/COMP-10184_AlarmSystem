IoT Alarm System – Stage 4

Course: COMP-10184
Author: Yash Khanduja
Student ID: 000826385

Overview

This project implements a motion-based alarm system using a PIR sensor, push button, and built-in LED on an Arduino-compatible board.
The system detects motion, starts a countdown, and activates an alarm if not disarmed in time.

Hardware Used

Arduino-compatible board

PIR Motion Sensor

Push Button

Built-in LED

Pin Mapping
Component	Pin
PIR Sensor	D5
Button	D6
LED	LED_BUILTIN

(Button uses INPUT_PULLUP, active LOW)

Alarm States

Enabled – System armed, waiting for motion

Countdown – Motion detected, LED blinks

Active – Alarm triggered, LED stays ON

Disabled – Not used in this stage

Working Logic

System calibrates PIR sensor at startup

Motion detection triggers countdown

LED blinks during countdown

Button press resets alarm

No button press → alarm activates

LED Behavior

OFF – Idle

Blinking – Countdown

ON – Alarm active

Output

Motion and button events logged via Serial Monitor

Timestamps displayed in seconds

Declaration

I, Yash Khanduja (000826385), declare that this is my own work.
