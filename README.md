LED Cat Ears Version 0.000000000000001

---
Parts

- Adafruit Feather M0 WiFi
	- https://www.adafruit.com/product/3010
	- https://amzn.to/2EYq2Bq

- Flora RGB Smart NeoPixel version 2
	[4] https://www.adafruit.com/product/1260
	[4] https://amzn.to/2Rw1IbG
	[20] https://www.adafruit.com/product/1559
	[20] https://amzn.to/2SG398y

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

Feather M0 - 3V        ->  NeoPixel +
Feather M0 - GND     ->  NeoPixel -
Feather M0 - PIN 6   ->  NeoPixel arrow pointing to middle

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
If you need additional help with this harass me on Twitter.
=D
