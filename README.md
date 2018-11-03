LED Cat Ears Version 0.000000000000001

<img src="https://i.imgur.com/RT1uAXD.jpg" alt="Lychi using the cat ears">

---
Parts

- Adafruit Feather M0 WiFi
	- https://www.adafruit.com/product/3010
	- https://amzn.to/2EYq2Bq

- Flora RGB Smart NeoPixel version 2
	- [4] https://www.adafruit.com/product/1260
	- [4] https://amzn.to/2Rw1IbG
	- [20] https://www.adafruit.com/product/1559
	- [20] https://amzn.to/2SG398y

- Any wireless dongle to connect from the PC to the Feather M0

---
Setting up Arduino IDE

https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/setup

https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/using-with-arduino-ide

---
Setting up the WiFi and updating firmware

https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/using-the-wifi-module

https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/updating-firmware

---
Wiring the lights

- Feather M0 - 3V      ->  NeoPixel +
- Feather M0 - GND     ->  NeoPixel -
- Feather M0 - PIN 6   ->  NeoPixel arrow pointing to middle

[I'll have a photo of this up if needed.]

---
Loading up the web server

- Open the Arduino IDE
- Load LEDwebserver.ino
- Select the correct port and board
- Upload the code
- Open the Serial Monitor
- Connect to the Feather SSID from your PC
- Open 192.168.1.1 on your browser

---
Setting up web requests in Mix It Up

- Set up your board and all that good stuff
- Add Command, Advanced Command
- Add Web Request action
- Put the URL http://192.168.1.1/ [letter of color or pattern]
	- Say R for Red, look at code (currentLine.endsWith("GET /R"))
- Action to Perform with Response should be None

---
Useful products

- Arduino Starter Kit
	- https://amzn.to/2yP02mt

- Arduino For Dummies
	- https://amzn.to/2SHC6d2

- Soldering Iron
	- https://amzn.to/2SHC6d2

- Helping Hands
	- https://amzn.to/2QhDXUj

---
Other Links

- NeoPixel Guide
	- https://learn.adafruit.com/adafruit-neopixel-uberguide?view=all

---
Looks

<img src="https://i.imgur.com/oM1Nl4p.jpg" alt="Feather connection">

<img src="https://i.imgur.com/Y1XwrDM.jpg" alt="NeoPixel connection">
