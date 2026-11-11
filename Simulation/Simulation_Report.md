# Simulation Report (Tinkercad)

> These results come from the Tinkercad Circuits simulator only. No physical hardware was tested as part of this work.

**Sketch:** `Arduino_Code/circuit.ino`. This is the conversation's final sketch with the DHT11 lines disabled, because Tinkercad has no DHT library.
**Compile result:** compiled and started with no errors (simulator clock running, Serial Monitor active).

| # | Test | Action in simulator | Observed result | Status |
|---|---|---|---|---|
| 1 | Start-up | Start Simulation | Serial Monitor printed `Live Sensor Monitor Started`, then a block of readings every ~0.5 s | PASS |
| 2 | Ultrasonic, no obstacle | Target left at its default distance | `Distance cm: 109–111`, `Obstacle: NO`, `Red LED: OFF` | PASS |
| 3 | Ultrasonic, obstacle | Target dragged to 8.5 cm | `Distance cm: 8.63`, `Obstacle: YES`, `Red LED: ON`, red LED lit on the canvas | PASS |
| 4 | Potentiometer → servo | Knob rotated | `Potentiometer: 696`, `Servo command: 122` (696 × 180 / 1023 = 122), servo horn moved | PASS |
| 5 | LDR reading | Default light level | `Light level: 54`, so the A1 divider gives a valid analog value | PASS |
| 6 | DHT11 | — | Prints `Not available (DHT11 not in Tinkercad)` as designed | NOT SUPPORTED |
| 7 | TCS3200 | — | Prints 0 for R/G/B because there is no sensor on the pins | NOT SUPPORTED |
| 8 | Push button → red LED | Button press | Wiring verified in the netlist (D13 ↔ button ↔ GND), and the code path is the same OR condition proven in test 3. A press-and-hold could not be scripted reliably through the automation tool, so press it by hand in the live link to see it. | WIRING VERIFIED / MANUAL CHECK |
| 9 | Vibration → green LED | — | No vibration sensor exists in Tinkercad, so A3 is left unconnected. Tinkercad reads the open A3 pin as LOW, so the simulation shows `Vibration state: 0` and the **green LED stays ON**. This is a simulator artefact of the missing sensor, not the real behaviour. | NOT SUPPORTED |

## Sample Serial Monitor output (obstacle test)

```
----------------------
Potentiometer: 0
Light level: 54
Temperature C: Not available (DHT11 not in Tinkercad)
Humidity %: Not available (DHT11 not in Tinkercad)
Distance cm: 8.63
Button: RELEASED
Vibration state: 0
Vibration count: 1
IR raw state: 0
Servo command: 0
TCS3200 Red: 0
TCS3200 Green: 0
TCS3200 Blue: 0
Obstacle: YES
Red LED: ON
Green LED: ON
```

Screenshots: `Screenshots/Simulation_Result.png` shows the red LED on with the obstacle at 8.5 cm and the servo rotated.
