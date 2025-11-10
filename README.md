# Thermostat Brewery Controller

## Overview
This Arduino-based project controls the temperature inside a fermentation chamber for homebrewed beer.  
It keeps the wort at the ideal temperature for the selected yeast strain by turning a freezer on and off through a Wi-Fi–controlled smart outlet.  

The system continuously measures the temperature, logs data to ThingSpeak, and automatically resumes operation after a power outage thanks to EEPROM backup storage.

---

## Hardware
- **Arduino Uno**
- **ESP-01 Wi-Fi module**
- **Piezo buzzer** (status and alarm sounds)
- **Two DS18B20 temperature sensors** (wort and ambient temperature)
- **RTC module** (real-time clock)
- **433 MHz transmitter**
- **Wi-Fi smart outlet** (controls the freezer power)

---

## How It Works
## How It Works
1. The user opens the **Serial Monitor** and selects a yeast strain from the on-screen menu.  
2. Each yeast type has a predefined optimal fermentation temperature.  
3. The Arduino monitors the temperatures from both DS18B20 sensors.  
4. When the temperature rises above or falls below the setpoint, the smart outlet is toggled via the 433 MHz transmitter.  
5. All data is sent to **ThingSpeak** for remote monitoring.  
6. The latest settings and temperatures are saved in **EEPROM**, so the controller automatically resumes after a power failure.

### Special Temperature Handling
- **Lager fermentation (preferred temperature < 15°C):**  
  After fermentation peaks, the system gradually ramps up the temperature by about 1–2°C per day over a week to eliminate diacetyl and fully complete fermentation. After reaching the target ramp temperature, a **cold crash** lowers the temperature to 2°C to clarify the beer.  

- **Ale fermentation (preferred temperature ≥ 15°C):**  
  Ramp-up is shorter and fermentation completes more quickly, followed by cold crash.  

This ensures optimal flavor, clarity, and yeast health for both lager and ale styles. 

---

## Features
✅ Automatic temperature control for fermentation  
✅ Menu-based yeast selection  
✅ EEPROM backup for reliability  
✅ Real-time clock for time tracking  
✅ Online logging to ThingSpeak  
✅ Audible alerts via buzzer  

---

## Getting Started
1. Upload the sketch to your **Arduino Uno**.  
2. Connect the hardware modules according to the pinout in the code comments.  
3. Open the **Serial Monitor** (9600 baud) and choose your yeast strain.  
4. Watch your fermentation temperature stay perfectly steady! 🍺  

---

## License
This project is open-source and free to use for homebrewing enthusiasts.  
Created by **Klas M.**, 2025.
