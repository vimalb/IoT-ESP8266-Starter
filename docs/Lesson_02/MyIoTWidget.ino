// Base ESP8266
#include <ESP8266WiFi.h>

#define LIGHT_SENSOR A0
#define LED 15
#define BUTTON 4

void setup() {
  // Initialize the serial port
  Serial.begin(115200);

  // Configure light sensor pin as an input
  pinMode(LIGHT_SENSOR, INPUT);

  // Configure LED pin as an output
  pinMode(LED, OUTPUT);

  // Configure BUTTON pin as an input with a pullup
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED, HIGH);

  // Wait for 1000 milliseconds
  delay(1000);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED, LOW);

  // Wait another 1000 milliseconds
  delay(1000);

  // Send a message over the serial port
  Serial.println("Finished loop");
}
