#include <SPI.h>
#include <WiFi101.h>
#include "arduino_secrets.h" 

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      4
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 500; // delay for half a second


char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                // your network key Index number (needed only for WEP)

int led =  LED_BUILTIN;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

long randNumber;  //Pixel random number variable
long randNumberR;  //RED random number variable
long randNumberG;  //GREEN random number variable
long randNumberB;  //BLUE random number variable

void setup() {
  WiFi.setPins(8,7,4,2);
  
  pixels.begin(); // This initializes the NeoPixel library.
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Access Point Web Server");

  pinMode(led, OUTPUT);      // set the LED pin mode

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);
  }

  WiFi.config(IPAddress(192, 168, 1, 1));

  Serial.print("Creating access point named: ");
  Serial.println(ssid);

  // Create open network. Change this line if you want to create an WEP network:
  status = WiFi.beginAP(ssid);
  if (status != WL_AP_LISTENING) {
    Serial.println("Creating access point failed");
    // don't continue
    while (true);
  }

  delay(10000);
  server.begin();
  printWiFiStatus();
}


void loop() {
  // compare the previous status to the current status
  if (status != WiFi.status()) {
    // it has changed update the variable
    status = WiFi.status();

    if (status == WL_AP_CONNECTED) {
      byte remoteMac[6];

      // a device has connected to the AP
      Serial.print("Device connected to AP, MAC address: ");
      WiFi.APClientMacAddress(remoteMac);
      Serial.print(remoteMac[5], HEX);
      Serial.print(":");
      Serial.print(remoteMac[4], HEX);
      Serial.print(":");
      Serial.print(remoteMac[3], HEX);
      Serial.print(":");
      Serial.print(remoteMac[2], HEX);
      Serial.print(":");
      Serial.print(remoteMac[1], HEX);
      Serial.print(":");
      Serial.println(remoteMac[0], HEX);
    } else {
      // a device has disconnected from the AP, and we are back in listening mode
      Serial.println("Device disconnected from AP");
    }
  }
  
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("sorryaboutyourcatears for Lychi<br><br>");
            client.print("Click <a href=\"/R\">here</a> turn the LED red<br>");
            client.print("Click <a href=\"/G\">here</a> turn the LED green<br>");
            client.print("Click <a href=\"/B\">here</a> turn the LED blue<br>");
            client.print("Click <a href=\"/P\">here</a> turn the LED pink<br>");
            client.print("Click <a href=\"/T\">here</a> turn the LED teal<br>");
            client.print("Click <a href=\"/Y\">here</a> turn the LED yellow<br>");
            client.print("Click <a href=\"/U\">here</a> turn the LED purple<br>");
            client.print("Click <a href=\"/Q\">here</a> turn the LED random<br><br>");
            client.print("Click <a href=\"/1\">here</a> turn the LED police pattern<br>");
            client.print("Click <a href=\"/2\">here</a> turn the LED random pattern<br><br>");
            client.print("Click <a href=\"/0\">here</a> turn the LED off<br>");
            
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          }
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /R")) {
          // red
          pixels.setPixelColor(0, pixels.Color(150,0,0));
          pixels.show();
          pixels.setPixelColor(1, pixels.Color(150,0,0));
          pixels.show();
          pixels.setPixelColor(2, pixels.Color(150,0,0));
          pixels.show();
          pixels.setPixelColor(3, pixels.Color(150,0,0));
          pixels.show();          
        }
        if (currentLine.endsWith("GET /G")) {
          // green
          pixels.setPixelColor(0, pixels.Color(0,150,0));
          pixels.show();
          pixels.setPixelColor(1, pixels.Color(0,150,0));
          pixels.show();
          pixels.setPixelColor(2, pixels.Color(0,150,0));
          pixels.show();
          pixels.setPixelColor(3, pixels.Color(0,150,0));
          pixels.show();          
        }
        if (currentLine.endsWith("GET /B")) {
          // blue
          pixels.setPixelColor(0, pixels.Color(0,0,150));
          pixels.show();
          pixels.setPixelColor(1, pixels.Color(0,0,150));
          pixels.show();
          pixels.setPixelColor(2, pixels.Color(0,0,150));
          pixels.show();
          pixels.setPixelColor(3, pixels.Color(0,0,150));
          pixels.show();          
        }
        if (currentLine.endsWith("GET /P")) {
          // pink
          pixels.setPixelColor(0, pixels.Color(150,0,150));
          pixels.show();
          pixels.setPixelColor(1, pixels.Color(150,0,150));
          pixels.show();
          pixels.setPixelColor(2, pixels.Color(150,0,150));
          pixels.show();
          pixels.setPixelColor(3, pixels.Color(150,0,150));
          pixels.show();          
        }
         if (currentLine.endsWith("GET /T")) {
          // teal
          pixels.setPixelColor(0, pixels.Color(0,150,150));
          pixels.show();
          pixels.setPixelColor(1, pixels.Color(0,150,150));
          pixels.show();
          pixels.setPixelColor(2, pixels.Color(0,150,150));
          pixels.show();
          pixels.setPixelColor(3, pixels.Color(0,150,150));
          pixels.show();          
        }
         if (currentLine.endsWith("GET /Y")) {
          // yellow
          pixels.setPixelColor(0, pixels.Color(150,150,0));
          pixels.show();
          pixels.setPixelColor(1, pixels.Color(150,150,0));
          pixels.show();
          pixels.setPixelColor(2, pixels.Color(150,150,0));
          pixels.show();
          pixels.setPixelColor(3, pixels.Color(150,150,0));
          pixels.show();          
        }
         if (currentLine.endsWith("GET /U")) {
          // purple
          pixels.setPixelColor(0, pixels.Color(100,0,220));
          pixels.show();
          pixels.setPixelColor(1, pixels.Color(100,0,220));
          pixels.show();
          pixels.setPixelColor(2, pixels.Color(100,0,220));
          pixels.show();
          pixels.setPixelColor(3, pixels.Color(100,0,220));
          pixels.show();          
        }
         if (currentLine.endsWith("GET /Q")) {
          randNumberR = random(0, 150);   //Random RED value
          randNumberG = random(0, 200);   //Random GREEN value
          randNumberB = random(0, 150);   //Random BLUE value
          pixels.setPixelColor(0, pixels.Color(randNumberR, randNumberG, randNumberB));
          pixels.show();
          randNumberR = random(0, 150);   //Random RED value
          randNumberG = random(0, 150);   //Random GREEN value
          randNumberB = random(0, 200);   //Random BLUE value
          pixels.setPixelColor(1, pixels.Color(randNumberR, randNumberG, randNumberB));
          pixels.show();
          randNumberR = random(0, 200);   //Random RED value
          randNumberG = random(0, 150);   //Random GREEN value
          randNumberB = random(0, 150);   //Random BLUE value
          pixels.setPixelColor(2, pixels.Color(randNumberR, randNumberG, randNumberB));
          pixels.show();
          randNumberR = random(0, 200);   //Random RED value
          randNumberG = random(0, 150);   //Random GREEN value
          randNumberB = random(0, 200);   //Random BLUE value
          pixels.setPixelColor(3, pixels.Color(randNumberR, randNumberG, randNumberB));
          pixels.show();
        }
         if (currentLine.endsWith("GET /1")) {
          for (int police=0; police <=3; police++){
          pixels.setPixelColor(0, pixels.Color(200,0,0));
          pixels.show();
          pixels.setPixelColor(1, pixels.Color(200,0,0));
          pixels.show();
          pixels.setPixelColor(2, pixels.Color(0,0,200));
          pixels.show();
          pixels.setPixelColor(3, pixels.Color(0,0,200));
          pixels.show();
          delay(500);
          pixels.setPixelColor(2, pixels.Color(200,0,0));
          pixels.show();
          pixels.setPixelColor(3, pixels.Color(200,0,0));
          pixels.show();
          pixels.setPixelColor(0, pixels.Color(0,0,200));
          pixels.show();
          pixels.setPixelColor(1, pixels.Color(0,0,200));
          pixels.show();                    
          delay(500);
        }
       }
         if (currentLine.endsWith("GET /2")) {
          for (int randomLights=0; randomLights <=6; randomLights++){
          randNumberR = random(0, 150);   //Random RED value
          randNumberG = random(0, 200);   //Random GREEN value
          randNumberB = random(0, 150);   //Random BLUE value
          pixels.setPixelColor(0, pixels.Color(randNumberR, randNumberG, randNumberB));
          pixels.show();
          randNumberR = random(0, 150);   //Random RED value
          randNumberG = random(0, 150);   //Random GREEN value
          randNumberB = random(0, 200);   //Random BLUE value
          pixels.setPixelColor(1, pixels.Color(randNumberR, randNumberG, randNumberB));
          pixels.show();
          randNumberR = random(0, 200);   //Random RED value
          randNumberG = random(0, 150);   //Random GREEN value
          randNumberB = random(0, 150);   //Random BLUE value
          pixels.setPixelColor(2, pixels.Color(randNumberR, randNumberG, randNumberB));
          pixels.show();
          randNumberR = random(0, 200);   //Random RED value
          randNumberG = random(0, 150);   //Random GREEN value
          randNumberB = random(0, 200);   //Random BLUE value
          pixels.setPixelColor(3, pixels.Color(randNumberR, randNumberG, randNumberB));
          pixels.show();
          delay(500);
         }
        }
       
        if (currentLine.endsWith("GET /0")) {
          pixels.setPixelColor(1, pixels.Color(0,0,0));
          pixels.show();
          pixels.setPixelColor(0, pixels.Color(0,0,0));
          pixels.show();
          pixels.setPixelColor(3, pixels.Color(0,0,0));
          pixels.show();
          pixels.setPixelColor(2, pixels.Color(0,0,0));
          pixels.show();                    
       }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);

}
