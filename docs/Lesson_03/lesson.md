---
layout: page
title: Lesson 3
---

# Lesson 3 - ESP8266 WiFi Setup

## Connect to WiFi in setup()

We generally want to connect to WiFi as soon as our module starts up, so let's replace ```setup()``` with the following code:

```
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
```

Note: Don't forget to substitute ```<your wifi access point name>``` and ```<your wifi access point password>``` with your actual WiFi network name and password otherwise this won't work.

## Test your sketch

Before we proceed, make sure your code looks like [this](MyIoTWidget.ino) except with the right values for the following substituted in:

* ```<your wifi access point name>```
* ```<your wifi access point password>```


### Get your module IP address

If your ESP8266 is successfully connected to a wifi network, it should automatically be assigned an IP address by the router. 

This IP address is what the router (and other devices on your local network / wifi) can use to communicate with your module. 

* Download your sketch and open up the serial monitor - within 10-20 seconds, you should see a line with the IP address of your ESP8266 module. 
  * If your ESP8266 connects too fast and you don't have time to open the Serial Monitor and catch the IP address line, considering adding in a ```delay(5000);``` right before the IP address is printed

![Serial Output](serial_output.png "Serial Output")

Note: Pretty much every device which is connected to the internet or to a local network has an IP address, and they communicate with each other by sending "packets" of data which include the destination IP address, source IP address, and any content. 

### Ping your module

One of the simplest protocols in networking is ICMP Echo request and response, more commonly known as "ping". If you know a target device's IP address, you can "ping" it to check if it's online and working. 

* Open up a terminal
  * In Windows, search for "cmd.exe" or "Command Prompt" and run it
  * In OSX, search for "Terminal" and run it
* Verify that your ESP8266 is connected to the network by trying to ping it
  * At the terminal prompt, type ```ping <your module IP address>``` and look for a reply
  * Output from this command looks slightly different between Windows and OSX, but it's close enough
  * By default, Windows will end ping after 4 requests, while OSX will continue until you press Ctrl-C to kill it

![Ping Output](ping_output.png "Ping Output")

Note: Most devices connected to a network, including your ESP8266 module, will respond to ping requests.


## Learn More

From a networking point of view, your ESP8266 module is the same as your desktop or laptop or phone or any other device connected to the internet. The basic concept behind "Internet of Things" is taking the same networking protocols and infrastructure which allow your computing devices to communicate over the internet, and reusing it to let your microcontrollers and embedded modules communicate over the internet.

If you want a deep understanding of how the internet works, learn about the basic protocols behind it:

* [Ethernet](https://en.wikipedia.org/wiki/Ethernet) - physical layer protocol
* [ARP](https://en.wikipedia.org/wiki/Address_Resolution_Protocol) - runs on top of Ethernet
* [IP](https://en.wikipedia.org/wiki/Internet_Protocol) - runs on top of Ethernet
* [TCP](https://en.wikipedia.org/wiki/Transmission_Control_Protocol) - runs on top of IP
* [DNS](https://en.wikipedia.org/wiki/Domain_Name_System) - runs on top of IP
* [ICMP](https://en.wikipedia.org/wiki/Internet_Control_Message_Protocol) - runs on top of IP
* [HTTP](https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol) - runs on top of TCP
* [SMTP](https://en.wikipedia.org/wiki/Simple_Mail_Transfer_Protocol) - runs on top of TCP
* [MQTT](https://en.wikipedia.org/wiki/MQTT) - runs on top of TCP







