---
layout: page
title: ESP8266 IoT Tutorial
---

# Welcome to the IoT Tutorial for ESP8266

* Goals
  * Make a webpage that controls an LED, reads a light sensor, and reacts to a button press
* Required Background 
  * None - this will link you to all necessary info
* Technologies Used
  * Arduinog
  * MQTT
  * HTML / CSS / Javascript

# Prerequisites

For this tutorial, you will need the following:
  * Computer running Windows or OSX
  * ESP8266 module
  * Other hardware
    * An LED and a 330-ohm resistor
    * A photoresistor and a 10K-ohm resistor
    * A button

Pretty much any ESP8266 module with a built-in USB-serial converter will do. It's possible to work with ESP8266 modules that aren't packaged with USB-serial converters, but if you're comfortable with that then you're probably not the target audience for this tutorial :)

Recommended ESP8266 Modules:

* [Gizwits Witty](Witty/info)
* [NodeMCU](NodeMCU/info)

If you're using any module other than the [Gizwits Witty](Witty/info), then you should follow the [breadboard setup guide](Breadboard/setup) to hook up all your parts the right way.


# Lessons

* [Lesson 1 - Arduino Software Setup](Lesson_01/lesson)
  * Get your Arduino development set up
* [Lesson 2 - ESP8266 Hello World](Lesson_02/lesson)
  * Upload an Arduino sketch to your ESP8266 to blink an LED
* [Lesson 3 - ESP8266 WiFi Setup](Lesson_03/lesson)
  * Connect your ESP8266 to WiFi and ping it
* [Lesson 4 - ESP8266 MQTT Publish](Lesson_04/lesson)
  * Make your ESP8266 publish a message to an MQTT server
* [Lesson 5 - HTML/CSS/Javascript Hello World](Lesson_05/lesson)
  * Make a simple webpage
* [Lesson 6 - Javascript MQTT Subscribe](Lesson_06/lesson)
  * Make your webpage subscribe to messages from an MQTT server
* [Lesson 7 - Javascript MQTT Publish](Lesson_07/lesson)
  * Make your webpage publish messages to an MQTT server
* [Lesson 8 - ESP8266 MQTT Subscribe](Lesson_08/lesson)
  * Make your ESP8266 subscribe to messages from an MQTT server
* [Lesson 9 - IoT Button](Lesson_09/lesson)
  * Make your ESP8266 publish a "button push message" each time a physical button is pressed
  * Make your webpage display an alert each time it receives a "button push message"
* [Lesson 10 - IoT LED](Lesson_10/lesson)
  * Make your webpage publish a "control LED message" each time a HTML button is pressed 
  * Make your ESP8266 control its LED each time it receives a "control LED message"
* [Lesson 11 - IoT Sensor](Lesson_11/lesson)
  * Make your ESP8266 publish a "light sensor reading message" every 5 seconds with the value of the light sensor
  * Make your webpage update with the latest value of the light sensor each time it receives a "light sensor reading message"





