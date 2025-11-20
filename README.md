# Automated Medicine Dispenser

**IoT-enabled smart medicine dispenser prototype** that releases scheduled doses using a servo motor and confirms dispense via IR/weight sensing. Includes local alerts (buzzer/LED), battery fallback, and caregiver escalation for missed doses. Designed as a low-cost, scalable solution for home and small care-centers (target cost ~₹1,500).

---

## Table of Contents
- Features
- Demo & Slides
- Hardware Components
- Wiring & Connections
- Software & Sketch
- Folder Structure
- How to Run / Test
- License
- Contact

## Features
- Scheduled automatic dosing via a microcontroller (Arduino/ESP32).
- Servo-driven dose release with IR or weight sensor confirmation.
- Local fallback alerts (buzzer + LED) and battery backup for power outages.
- Caregiver escalation via notifications when a dose is missed.
- Low-cost, accessible design intended for home and clinic use.

## Demo & Slides
The project report / slides are in `docs/AutomatedMedicineDispensor.pptx`.

## Hardware Components (suggested)
- Microcontroller: Arduino Uno or ESP32
- Servo motor (standard 9g or similar) for dispensing
- IR sensor or load/weight sensor (e.g., HX711 + load cell) for confirmation
- Buzzer and LEDs for local alerts
- Real Time Clock (RTC) module (optional) for scheduling accuracy
- Battery backup (5V power bank)
- Jumper wires, protoboard / PCB, enclosure & mounting hardware

A sample Bill of Materials is included in `hardware/bill_of_materials.md`.

## Wiring & Connections
- Servo signal pin to PWM digital pin on microcontroller.
- IR sensor digital output to a GPIO input (or HX711 to analog input via amplifier).
- Buzzer to a digital output with appropriate transistor driver if needed.
- RTC (e.g., DS3231) connected via I2C (SDA / SCL).
- Power common ground for all components.

Refer to `docs/wiring_diagram.png` (add diagram in docs/ if available).

## Software & Sketch
A starter Arduino sketch is provided at `src/arduino/dispenser.ino`. It contains:
- scheduled dispense logic
- servo control
- basic sensor read and confirmation
- buzzer/LED alerts

Customize pin definitions and calibration constants in the sketch before uploading.

## Folder Structure
```
automated-medicine-dispenser/
├── README.md
├── LICENSE
├── .gitignore
├── docs/
│   ├── AutomatedMedicineDispensor.pptx
│   └── images/
├── src/
│   └── arduino/
│       └── dispenser.ino
└── hardware/
    └── bill_of_materials.md
```

## How to Run / Test (Quick)
1. Open `src/arduino/dispenser.ino` in Arduino IDE (or PlatformIO).  
2. Configure pins and any WiFi/RTC credentials in the top section.  
3. Upload sketch to the microcontroller.  
4. Place small test weights or IR targets and test the dispense routine.  
5. Monitor serial output for sensor confirmations and logs.

## Contributing
Contributions welcome. Open an issue or submit a pull request with improvements.

## License
This project is released under the MIT License — see `LICENSE`.

## Contact
Tilak Rathi — iamtilakrathi16@gmail.com  
GitHub: https://github.com/tilakrathi/AMD
