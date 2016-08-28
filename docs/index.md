---
layout: page
title: Welcome to the IoT Tutorial for ESP8266
---

### **Goal**

Make a webpage that controls an LED, reads a light sensor, and reacts to a button press

### **Required Background**

None - we will link you to all necessary info

### **Technologies**

  * Arduino
  * MQTT
  * HTML / Javascript

### **Setup**

#### [SETUP GUIDE](Breadboard/setup.html)

For this tutorial, you will need the following:

  * Computer running Windows or OSX
  * ESP8266 module such as:
    * [Gizwits Witty](Witty/info.html)
    * [NodeMCU](NodeMCU/info.html)
  * Other hardware
    * An LED and a 330-ohm resistor (built into [Gizwits Witty](Witty/info.html))
    * A photoresistor and a 10K-ohm resistor (built into [Gizwits Witty](Witty/info.html))
    * A button (built into [Gizwits Witty](Witty/info.html))


### **Lessons**

* [**Lesson 1 - Arduino Setup**](Lesson_01/lesson.html)
  * Get your Arduino development environment set up
* [**Lesson 2 - ESP8266 Hello World**](Lesson_02/lesson.html)
  * Upload an Arduino sketch to your ESP8266 to blink an LED
* [**Lesson 3 - ESP8266 WiFi Setup**](Lesson_03/lesson.html)
  * Connect your ESP8266 to WiFi and ping it
* [**Lesson 4 - ESP8266 MQTT Publish**](Lesson_04/lesson.html)
  * Make your ESP8266 publish a message to an MQTT server
* [**Lesson 5 - HTML/Javascript Hello World**](Lesson_05/lesson.html)
  * Make a simple webpage
* [**Lesson 6 - Javascript MQTT Subscribe**](Lesson_06/lesson.html)
  * Make your webpage subscribe to messages from an MQTT server
* [**Lesson 7 - Javascript MQTT Publish**](Lesson_07/lesson.html)
  * Make your webpage publish messages to an MQTT server
* [**Lesson 8 - ESP8266 MQTT Subscribe**](Lesson_08/lesson.html)
  * Make your ESP8266 subscribe to messages from an MQTT server
* [**Lesson 9 - IoT Button**](Lesson_09/lesson.html)
  * Make your ESP8266 publish a "button pushed" message each time a physical button is pressed
  * Make your webpage display the "button pushed" message whenever it is received
* [**Lesson 10 - IoT LED**](Lesson_10/lesson.html)
  * Make your webpage publish a "control LED message" each time a HTML button is pressed 
  * Make your ESP8266 control its LED each time it receives a "control LED message"
* [**Lesson 11 - IoT Sensor**](Lesson_11/lesson.html)
  * Make your ESP8266 publish a "light sensor reading message" every 5 seconds with the value of the light sensor
  * Make your webpage update with the latest value of the light sensor each time it receives a "light sensor reading message"





