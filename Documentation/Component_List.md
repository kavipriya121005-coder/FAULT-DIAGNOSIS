# Component Inventory

Source of truth: the project's ChatGPT conversation ("Build Small CNC Prototype"), final sketch and pin list.

| # | Component (original) | Qty | Arduino pin(s) | Tinkercad part used | Tinkercad ref (BRD) | Status |
|---|---|---|---|---|---|---|
| 1 | Arduino Uno R3 | 1 | — | Arduino Uno R3 | U1 | Placed |
| 2 | HC-SR04 ultrasonic sensor | 1 | TRIG D11, ECHO D12 | Ultrasonic Distance Sensor (4-pin, HC-SR04) | DIST1 | Placed |
| 3 | Push button | 1 | D13 (INPUT_PULLUP) | Pushbutton | S1 | Placed |
| 4 | Red LED | 1 | D6 | LED (Red) | D1 | Placed |
| 5 | Green LED | 1 | A4 | LED (Green) | D2 | Placed |
| 6 | 220 Ω resistor (one per LED, from the chat) | 2 | series with LEDs | Resistor 220 Ω | R2, R3 | Placed |
| 7 | Potentiometer | 1 | A0 | Potentiometer (Tinkercad default 250 kΩ; value not stated in chat) | RPOT1 | Placed |
| 8 | Servo motor | 1 | D10 | Micro Servo (SG90) | SERVO1 | Placed |
| 9 | LDR module (AO output) | 1 | A1 | Photoresistor + 10 kΩ resistor (the module's internal voltage divider) | R1 + R4 | Placed |
| 10 | Vibration sensor module | 1 | A3 | — | — | **NOT SUPPORTED BY TINKERCAD** |
| 11 | IR obstacle sensor module | 1 | D4 | — | — | **NOT SUPPORTED BY TINKERCAD** |
| 12 | DHT11 temperature/humidity sensor | 1 | D7 | — | — | **NOT SUPPORTED BY TINKERCAD** |
| 13 | TCS3200 colour sensor | 1 | S0 D5, S1 D3, S2 D8, S3 D9, OUT D2 | — | — | **NOT SUPPORTED BY TINKERCAD** |
| 14 | Blue LED, fourth LED | 2 | "Leave disconnected for now" (per chat) | — | — | Intentionally not placed |

## Notes

- No component was swapped for a different sensor type. Unsupported modules are left out, and their Arduino pins are left free so the pin map stays identical to the real board.
- The LDR "module" in the chat has a single analog output (AO). A bare photoresistor in Tinkercad has two leads, so it is wired the way the module is built inside: 5 V → photoresistor → A1 → 10 kΩ → GND.
- Power: everything runs from the Uno's 5 V pin (USB-powered in Tinkercad). Every GND goes to the Uno's GND pins.
