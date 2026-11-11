// CNC Mini-Model - Live Sensor Monitor (Arduino Uno R3)
// Source: final sketch from the project's ChatGPT conversation.
//
// TINKERCAD BUILD NOTE
// Tinkercad has no DHT11 sensor and no DHT library, so the two DHT lines
// (#include <DHT.h>, DHT object, dht.begin(), dht.readTemperature/Humidity)
// are disabled below and temperature/humidity print "Not available".
// Every other line, pin and condition is unchanged from the original.
// To use on the real board with a DHT11, set USE_DHT11 to 1.

#define USE_DHT11 0

#if USE_DHT11
#include <DHT.h>
#endif
#include <Servo.h>

const int potPin = A0;
const int ldrPin = A1;
const int vibrationPin = A3;

const int irPin = 4;
const int redLED = 6;
const int greenLED = A4;
const int dhtPin = 7;
const int servoPin = 10;
const int trigPin = 11;
const int echoPin = 12;
const int buttonPin = 13;

const int S0 = 5;
const int S1 = 3;
const int S2 = 8;
const int S3 = 9;
const int colorOut = 2;

#if USE_DHT11
#define DHTTYPE DHT11
DHT dht(dhtPin, DHTTYPE);
#endif
Servo myServo;

unsigned long vibrationCount = 0;
int lastVibrationState = HIGH;
unsigned long lastPrint = 0;

float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) return -1;
  return duration * 0.0343 / 2.0;
}

unsigned long readColor(bool s2, bool s3) {
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  delay(30);

  unsigned long duration = pulseIn(colorOut, LOW, 100000);
  if (duration == 0) return 0;

  return 1000000UL / duration;
}

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(vibrationPin, INPUT_PULLUP);
  pinMode(irPin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(colorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

#if USE_DHT11
  dht.begin();
#endif
  myServo.attach(servoPin);

  Serial.println("Live Sensor Monitor Started");
}

void loop() {
  int potValue = analogRead(potPin);
  int lightValue = analogRead(ldrPin);

  int buttonState = digitalRead(buttonPin);
  int vibrationState = digitalRead(vibrationPin);

  if (lastVibrationState == HIGH && vibrationState == LOW) {
    vibrationCount++;
  }
  lastVibrationState = vibrationState;

  float distance = readDistance();

  // Change 10 to another distance if desired.
  bool obstacleDetected = (distance >= 0 && distance <= 10);

  bool buttonPressed = (buttonState == LOW);
  bool vibrationDetected = (vibrationState == LOW);

  // Red LED: button OR ultrasonic obstacle.
  digitalWrite(redLED, (buttonPressed || obstacleDetected) ? HIGH : LOW);

  // Green LED: vibration detected.
  digitalWrite(greenLED, vibrationDetected ? HIGH : LOW);

  int servoAngle = map(potValue, 0, 1023, 0, 180);
  myServo.write(servoAngle);

  if (millis() - lastPrint >= 500) {
    lastPrint = millis();

#if USE_DHT11
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
#endif

    unsigned long red = readColor(LOW, LOW);
    unsigned long blue = readColor(LOW, HIGH);
    unsigned long green = readColor(HIGH, HIGH);

    Serial.println("----------------------");
    Serial.print("Potentiometer: "); Serial.println(potValue);
    Serial.print("Light level: "); Serial.println(lightValue);

#if USE_DHT11
    Serial.print("Temperature C: ");
    if (isnan(temperature)) Serial.println("Error");
    else Serial.println(temperature);

    Serial.print("Humidity %: ");
    if (isnan(humidity)) Serial.println("Error");
    else Serial.println(humidity);
#else
    Serial.println("Temperature C: Not available (DHT11 not in Tinkercad)");
    Serial.println("Humidity %: Not available (DHT11 not in Tinkercad)");
#endif

    Serial.print("Distance cm: ");
    if (distance < 0) Serial.println("No echo");
    else Serial.println(distance);

    Serial.print("Button: ");
    Serial.println(buttonPressed ? "PRESSED" : "RELEASED");

    Serial.print("Vibration state: ");
    Serial.println(vibrationState);

    Serial.print("Vibration count: ");
    Serial.println(vibrationCount);

    Serial.print("IR raw state: ");
    Serial.println(digitalRead(irPin));

    Serial.print("Servo command: ");
    Serial.println(servoAngle);

    Serial.print("TCS3200 Red: "); Serial.println(red);
    Serial.print("TCS3200 Green: "); Serial.println(green);
    Serial.print("TCS3200 Blue: "); Serial.println(blue);

    Serial.print("Obstacle: ");
    Serial.println(obstacleDetected ? "YES" : "NO");

    Serial.print("Red LED: ");
    Serial.println((buttonPressed || obstacleDetected) ? "ON" : "OFF");

    Serial.print("Green LED: ");
    Serial.println(vibrationDetected ? "ON" : "OFF");
  }

  delay(50);
}
