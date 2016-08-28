// Base ESP8266
#include <ESP8266WiFi.h>
WiFiClient WIFI_CLIENT;

// MQTT
#include <PubSubClient.h>
PubSubClient MQTT_CLIENT;


#define LIGHT_SENSOR A0
#define LED 15
#define BUTTON 4

// This function runs once on startup
void setup() {
  // Initialize the serial port
  Serial.begin(115200);

  // Configure light sensor pin as an input
  pinMode(LIGHT_SENSOR, INPUT);

  // Configure LED pin as an output
  pinMode(LED, OUTPUT);

  // Configure BUTTON pin as an input with a pullup
  pinMode(BUTTON, INPUT_PULLUP);

  // Attempt to connect to a specific access point
  WiFi.begin("<your wifi access point name>", "<your wifi access point password>");

  // Keep checking the connection status until it is connected
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
  }

  // Print the IP address of your module
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// This function handles received messages
void myMessageArrived(char* topic, byte* payload, unsigned int length) {
  // Convert the message payload from bytes to a string
  String message = "";
  for (unsigned int i=0; i< length; i++) {
    message = message + (char)payload[i];
  }
   
  // Print the message to the serial port
  Serial.println(message);

  // Check if message is "turn led on"
  if(message == "turn led on") {
    // Turn the LED on
    digitalWrite(LED, HIGH);
  }

  // Check if message is "turn led off"
  if(message == "turn led off") {
    // Turn the LED off
    digitalWrite(LED, LOW);
  }
}

// This function connects to the MQTT broker
void reconnect() {
  // Set our MQTT broker address and port
  MQTT_CLIENT.setServer("iot.eclipse.org", 1883);
  MQTT_CLIENT.setClient(WIFI_CLIENT);

  // Loop until we're reconnected
  while (!MQTT_CLIENT.connected()) {
    // Attempt to connect
    Serial.println("Attempt to connect to MQTT broker");
    MQTT_CLIENT.connect("<your_random_device_client_id>");

    // Wait some time to space out connection requests
    delay(3000);
  }

  Serial.println("MQTT connected");

  // Subscribe to the topic where our web page is publishing messages
  MQTT_CLIENT.subscribe("<your_random_topic_root>/iot_tutorial/from_webpage");

  // Set the message received callback
  MQTT_CLIENT.setCallback(myMessageArrived);
}

// This function runs over and over again in a continuous loop
void loop() {

  // Check if we're connected to the MQTT broker
  if (!MQTT_CLIENT.connected()) {
    // If we're not, attempt to reconnect
    reconnect();
  }

  // If the button is pressed
  if(digitalRead(BUTTON) == LOW) {

    // Wait for the button to be released
    while(digitalRead(BUTTON) == LOW) {
      delay(100);    
    }

    // Publish a button pushed message to a topic
    MQTT_CLIENT.publish("<your_random_topic_root>/iot_tutorial/from_esp8266", "button pushed");

  }

  // Check for incoming MQTT messages
  MQTT_CLIENT.loop();
}
