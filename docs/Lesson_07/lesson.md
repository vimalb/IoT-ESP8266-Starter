---
layout: page
title: Lesson 7
---

# Lesson 7 - Javascript MQTT Publish

Now that our web page is subscribing to MQTT topics and receiving messages from our ESP8266 module, let's make it also publish messages to a different topic whiich our ESP8266 module can subscribe to. This way we get two-way communication between our web page and our ESP8266 module. 

## Send a message on a button push

We already set up our web page to run the ```myButtonWasClicked()``` javascript function every time the ```Press me!``` button is pressed. Now let's change that function so that it publishes a message to an MQTT topic instead. 

To do this, replace the existing ```myButtonWasClicked()``` javascript function in ```app.js``` with the following:

```
// This is the function which handles button clicks
function myButtonWasClicked() {
  // create a new MQTT message with a specific payload
  var mqttMessage = new Paho.MQTT.Message("Hello from website");

  // Set the topic it should be published to
  mqttMessage.destinationName = "<your_random_topic_root>/iot_tutorial/from_webpage";

  // Publish the message
  MQTT_CLIENT.send(mqttMessage);
}
```

Note: Be sure to replace ```<your_random_topic_root>``` with the exact same value that you used in your Arduino code and elsewhere in your web page. In theory we could choose any new topic name, however to keep things simple we will reuse the same random root topic and just change the path.


## Test your webpage

Before we proceed, make sure your index.html looks like [this](index.html) and your app.js looks like [this](app.js) except with the right values for the following substituted in:

* ```<your_random_topic_root>```

Close any open copies of your web page that you may have, and then double-click on ```index.html``` to open it up in a new browser window or tab. 

Each time you hit the ```Press me!``` button, your web page should publish a message to the the MQTT broker on the topic ```<your_random_topic_root>/iot_tutorial/from_webpage```.


