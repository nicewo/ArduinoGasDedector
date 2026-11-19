# Arduino Gas Detector

<p align="center">
  <strong>Alarm prototype driven by gas level and temperature thresholds</strong><br>
  Arduino with MQ-135 analog gas sensing and a DHT11 temperature sensor, driving a buzzer and a relay.
</p>

<p align="center">
  <img alt="Platform" src="https://img.shields.io/badge/Platform-Arduino-00979D?logo=arduino&logoColor=white">
  <img alt="Sensor" src="https://img.shields.io/badge/Sensors-MQ--135%20%2B%20DHT11-orange">
  <img alt="Firmware" src="https://img.shields.io/badge/Firmware-C%2B%2B-blue?logo=cplusplus&logoColor=white">
</p>

🇹🇷 [Türkçe README](README.tr.md)

---

## Overview

This Arduino sketch reads an analog gas value from an MQ-135 sensor, measures temperature with a DHT11 at fixed intervals and turns on a buzzer and a relay when any threshold is exceeded. The digital output of the gas module is also part of the alarm condition. Diagnostic values are printed over serial.

## Hardware and pins

| Component | Arduino pin | Purpose |
|---|---:|---|
| DHT11 | D2 | Temperature |
| MQ-135 analog out | A0 | Analog gas level |
| Gas module digital out | D6 | Digital alarm input |
| Buzzer | D7 | Audible alarm |
| Relay | D8 | External alarm / output |
| Serial | 9600 baud | Diagnostics |

Check the pin mapping against your board and modules.

## How it works

- 🌡️ DHT11 temperature is read about every 2 s.
- 📈 MQ-135 analog value is read every loop.
- 🚨 The alarm turns on when the analog value exceeds 550, temperature exceeds 50 °C, or the digital gas input is active.
- 🔊 During an alarm the buzzer toggles about every 300 ms.
- 🔌 The relay output is HIGH while the alarm is active.
- 🖥️ Gas, digital input and temperature are printed to serial about every 500 ms.

## Setup

1. Open the Arduino IDE.
2. Install the DHT sensor library.
3. Open `GasDedector/GasDedector.ino`.
4. Select the board and port, then upload.
5. Open the Serial Monitor at 9600 baud to watch the readings.
6. Tune the thresholds for your sensor module under controlled test conditions.

## Safety notice

**This project is not a certified gas-leak or fire alarm.** MQ-135 readings depend on gas type, calibration, warm-up time and ambient conditions; the value 550 is not a universal ppm figure. Real safety applications need a certified detector, calibration, redundant sensing and a fail-safe design.

Check the electrical rating of whatever the relay switches, and never drive high-power loads directly from Arduino pins. Do not run tests in a real hazardous gas environment.

## Status

Prototype for learning and bench testing. Validate in a lab before any real-world use.
