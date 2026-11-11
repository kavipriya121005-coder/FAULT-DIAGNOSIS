# Pin-to-Pin Connection Table

All wires are as built in Tinkercad. In the Tinkercad editor every wire is the default green. The colours below are the colours recommended for the real build.

| # | Component | Component pin | Destination | Destination pin | Wire colour (recommended) | Voltage | Purpose |
|---|---|---|---|---|---|---|---|
| 1 | HC-SR04 | VCC | Arduino Uno | 5V (via servo + rail, same net) | Red | 5 V | Sensor power |
| 2 | HC-SR04 | TRIG | Arduino Uno | D11 | Yellow | 5 V logic | Trigger pulse output |
| 3 | HC-SR04 | ECHO | Arduino Uno | D12 | Orange | 5 V logic | Echo pulse input |
| 4 | HC-SR04 | GND | Arduino Uno | GND (via servo − rail, same net) | Black | 0 V | Ground |
| 5 | Push button | Terminal 1a | Arduino Uno | D13 | Blue | 5 V logic (internal pull-up) | Button input; LOW = pressed |
| 6 | Push button | Terminal 2a | Arduino Uno | GND | Black | 0 V | Button ground |
| 7 | Arduino Uno | D6 | Resistor R2 (220 Ω) | Terminal 1 | White | 5 V logic | Red LED drive |
| 8 | Resistor R2 (220 Ω) | Terminal 2 | Red LED D1 | Anode | White | — | Current limiting |
| 9 | Red LED D1 | Cathode | Arduino Uno | GND | Black | 0 V | LED return |
| 10 | Arduino Uno | A4 | Resistor R3 (220 Ω) | Terminal 2 | Green | 5 V logic | Green LED drive |
| 11 | Resistor R3 (220 Ω) | Terminal 1 | Green LED D2 | Anode | Green | — | Current limiting |
| 12 | Green LED D2 | Cathode | Arduino Uno | GND (via R4 GND node) | Black | 0 V | LED return |
| 13 | Servo | Signal | Arduino Uno | D10 | Orange | 5 V PWM | Servo position command |
| 14 | Servo | Power | Arduino Uno | 5V | Red | 5 V | Servo power |
| 15 | Servo | Ground | Arduino Uno | GND | Brown/Black | 0 V | Servo ground |
| 16 | Potentiometer | Wiper | Arduino Uno | A0 | Purple | 0–5 V analog | Manual analog input |
| 17 | Potentiometer | Terminal 2 | Arduino Uno | 5V | Red | 5 V | Pot high side |
| 18 | Potentiometer | Terminal 1 | Arduino Uno | GND | Black | 0 V | Pot low side |
| 19 | Photoresistor (LDR) | Terminal 1 | Arduino Uno | 5V | Red | 5 V | LDR divider top |
| 20 | Photoresistor (LDR) | Terminal 2 | Arduino Uno | A1 | Grey | 0–5 V analog | Light level input |
| 21 | Resistor R4 (10 kΩ) | Terminal 1 | Arduino Uno | A1 | Grey | 0–5 V analog | LDR divider bottom |
| 22 | Resistor R4 (10 kΩ) | Terminal 2 | Arduino Uno | GND | Black | 0 V | Divider ground |
| 23 | Vibration sensor | DO | Arduino Uno | A3 | — | 5 V logic | NOT SUPPORTED BY TINKERCAD (pin left free) |
| 24 | IR obstacle sensor | OUT | Arduino Uno | D4 | — | 5 V logic | NOT SUPPORTED BY TINKERCAD (pin left free) |
| 25 | DHT11 | DATA | Arduino Uno | D7 | — | 5 V logic | NOT SUPPORTED BY TINKERCAD (pin left free) |
| 26 | TCS3200 | OUT / S0 / S1 / S2 / S3 | Arduino Uno | D2 / D5 / D3 / D8 / D9 | — | 5 V logic | NOT SUPPORTED BY TINKERCAD (pins left free) |

## Net list exported by Tinkercad (from `Tinkercad_Files/circuit.brd`)

```
U1_GND -> S1:3, U1:GND@0, U1:GND@1, U1:GND@2, D1:2, DIST1:4, SERVO1:1, RPOT1:1, R4:2, D2:2
U1_5V  -> DIST1:1, SERVO1:2, U1:5V, RPOT1:3, R1:1
U1_A0  -> RPOT1:2, U1:A0
U1_A1  -> R1:2, U1:A1, R4:1
U1_A4  -> U1:A4, R3:2
U1_D6  -> U1:D6, R2:1
U1_D10 -> SERVO1:3, U1:D10
U1_D11 -> DIST1:2, U1:D11
U1_D12 -> DIST1:3, U1:D12
U1_D13 -> S1:1, U1:D13
D1_A   -> R2:2, D1:1
D2_A   -> R3:1, D2:1
```
