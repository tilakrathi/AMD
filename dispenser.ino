// Starter sketch for Automated Medicine Dispenser
#include <Servo.h>

// Pin definitions - change as needed
const int servoPin = 9;
const int sensorPin = 2; // IR or digital sensor
const int buzzerPin = 3;
const int ledPin = 4;

Servo dispenser;

void setup() {
  Serial.begin(9600);
  dispenser.attach(servoPin);
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Placeholder routine: rotate servo to release dose, check sensor
  releaseDose();
  delay(60000); // wait 60 seconds (for testing)
}

void releaseDose() {
  Serial.println("Releasing dose...");
  dispenser.write(90); // adjust as needed
  delay(1000);
  dispenser.write(0);  // reset
  delay(500);
  int sensorVal = digitalRead(sensorPin);
  if (sensorVal == HIGH) {
    Serial.println("Dose confirmed by sensor.");
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  } else {
    Serial.println("No confirmation - alerting");
    alertCaregiver();
  }
}

void alertCaregiver() {
  // simple buzzer alert
  for (int i=0;i<3;i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }
}
