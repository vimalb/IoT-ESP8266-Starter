---
layout: page
title: Lesson 10
---

# Lesson 10 - IoT LED

Now that we've made our web page do something when an action is triggered on our ESP8266 module, let's flip it around and make our ESP8266 module do something when an action is triggered on our web page.

Specifically let's add two buttons to our web page, one which publishes a "turn led on" message and one which publishes a "turn led off" message. Then let's have our Arduino receive these messages and turn its LED on and off appropriately.

Whether you are using the LED built into the [Gizwits Witty](../Witty/info.html) or using the [breadboard setup](../Breadboard/setup.md), the LED is wired the same way and you can turn it on by ```digitalWrite(LED, HIGH)``` and off by ```digitalWrite(LED, LOW)```.

### Add LED on and off buttons to the web page

First let's add the buttons themselves to the HTML. Immediately after the current ```<button>``` tag in ```index.html```, add the following:

```
      <button onClick="turnOnLED()">Turn LED on</button>
      <button onClick="turnOffLED()">Turn LED off</button>
```

Now let's add the corresponding functions to the javascript. Add the following code to the end of ```app.js```:

```
// This function handles "Turn LED on" button clicks
function turnOnLED() {
  // create a new MQTT message with a specific payload
  var mqttMessage = new Paho.MQTT.Message("turn led on");

  // Set the topic it should be published to
  mqttMessage.destinationName = "<your_random_topic_root>/iot_tutorial/from_webpage";

  // Publish the message
  MQTT_CLIENT.send(mqttMessage);
}

// This function handles "Turn LED on" button clicks
function turnOffLED() {
  // create a new MQTT message with a specific payload
  var mqttMessage = new Paho.MQTT.Message("turn led off");

  // Set the topic it should be published to
  mqttMessage.destinationName = "<your_random_topic_root>/iot_tutorial/from_webpage";

  // Publish the message
  MQTT_CLIENT.send(mqttMessage);
}
```

Note: You should remember to replace ```<your_random_topic_root>``` with the exact same value that you used in elsewhere in your Arduino code and web page. 


### Check for "turn led on" and "turn led off" messages and set LED appropriately

Let's add some logic inside the ```myMessageArrived``` function in your ESP8266 Arduino code to check if the message is either "turn led on" or "turn led off" and set the LED appropriately.

To do this, insert the following lines of code at the very end of the ```myMessageArrived``` function:

```
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
```


## Test your sketch and web page

Before we proceed, make sure your Arduino code looks like [this](MyIoTWidget.ino) except with the right values for the following substituted in:

* ```<your wifi access point name>```
* ```<your wifi access point password>```
* ```<your_random_device_client_id>```
* ```<your_random_topic_root>```

Also make sure your index.html looks like [this](index.html) and your app.js looks like [this](app.js) except with the right values for the following substituted in:

* ```<your_random_topic_root>```


Close any open copies of your web page that you may have, and then double-click on ```index.html``` to open it up in a new browser window or tab.

Then download your sketch and open up the serial monitor - you should see log messages once you have connected successfully to the MQTT broker.

Now hit the ```Turn LED on``` and ```Turn LED off``` buttons on your web page, and within a couple seconds you should see the LED connected to your ESP8266 module change appropriately.


