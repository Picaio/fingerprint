

#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display
#include <SPI.h>
#include <Wire.h>
Adafruit_SSD1306 display;  // Create display
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <Fonts/FreeMonoBold12pt7b.h>  // Add a custom font
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font


static const uint8_t icon [] PROGMEM = {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x3f,0xc0,0x0,0x0,0x0,
0x0,0x0,0x3,0xff,0xf8,0x0,0x0,0x0,
0x0,0x0,0x7,0xff,0xfe,0x0,0x0,0x0,
0x0,0x0,0x1f,0xc0,0x7f,0x80,0x0,0x0,
0x0,0x0,0x3e,0x0,0x7,0xc0,0x0,0x0,
0x0,0x0,0x7c,0x0,0x3,0xe0,0x0,0x0,
0x0,0x0,0xfd,0xff,0x81,0xf0,0x0,0x0,
0x0,0x0,0xff,0xff,0xe0,0xf0,0x0,0x0,
0x0,0x1,0xff,0xff,0xf8,0x78,0x0,0x0,
0x0,0x1,0xff,0x80,0x7c,0x38,0x0,0x0,
0x0,0x3,0xfc,0x0,0xe,0x3c,0x0,0x0,
0x0,0x3,0xf0,0x0,0x7,0x1c,0x0,0x0,
0x0,0x7,0xc0,0x7f,0x83,0x8e,0x0,0x0,
0x0,0x7,0x83,0xff,0xe0,0xe,0x0,0x0,
0x0,0x7,0xf,0xff,0xf8,0xf,0x0,0x0,
0x0,0x6,0x1f,0x80,0xfc,0x7,0x0,0x0,
0x0,0x4,0x7e,0x0,0x3f,0x7,0x0,0x0,
0x0,0x0,0xf8,0x0,0xf,0x7,0x0,0x0,
0x0,0x0,0xf0,0x3e,0x7,0x87,0x0,0x0,
0x0,0x1,0xe1,0xff,0x83,0x83,0x80,0x0,
0x0,0x3,0xc3,0xff,0xc3,0xc3,0x80,0x0,
0x0,0x3,0xc7,0xc3,0xe1,0xc3,0x80,0x0,
0x0,0x3,0x8f,0x0,0xf1,0xe3,0x80,0x0,
0x0,0x7,0x1e,0x0,0x78,0xe3,0x80,0x0,
0x0,0x7,0x1e,0x3c,0x38,0xe3,0x80,0x0,
0x0,0x7,0x1c,0x7e,0x38,0xe3,0x80,0x0,
0x0,0xf,0x1c,0x7f,0x38,0xe3,0x80,0x0,
0x0,0xe,0x3c,0xf7,0x38,0x71,0x80,0x0,
0x0,0xe,0x38,0xe7,0x38,0x71,0xc0,0x0,
0x0,0xe,0x38,0xe7,0x38,0x71,0xc0,0x0,
0x0,0xe,0x38,0xe7,0x38,0x73,0xc0,0x0,
0x0,0xe,0x38,0xe3,0x98,0xe3,0xc0,0x0,
0x0,0xe,0x38,0xe3,0xb8,0xe3,0x80,0x0,
0x0,0x0,0x38,0xe3,0xf8,0xe3,0x80,0x0,
0x0,0x0,0x38,0xe3,0xf8,0xe3,0x80,0x0,
0x0,0x0,0x3c,0xf1,0xf1,0xe3,0x80,0x0,
0x0,0x6,0x1c,0x70,0x1,0xc7,0x80,0x0,
0x0,0xe,0x1c,0x78,0x3,0xc7,0x80,0x0,
0x0,0xf,0x1c,0x3e,0x7,0x87,0x0,0x0,
0x0,0xf,0x1e,0x3f,0xff,0x8f,0x0,0x0,
0x0,0xf,0x1e,0x1f,0xff,0x1f,0x0,0x0,
0x0,0xf,0xf,0x7,0xfc,0x3e,0x0,0x0,
0x0,0x7,0x87,0x80,0x0,0x7c,0x0,0x0,
0x0,0x7,0x87,0xe0,0x0,0xfc,0x0,0x0,
0x0,0x3,0xc3,0xf8,0x7,0xf8,0x0,0x0,
0x0,0x3,0xe1,0xff,0xff,0xe1,0x0,0x0,
0x0,0x1,0xe0,0x7f,0xff,0x83,0x0,0x0,
0x0,0x1,0xf8,0xf,0xfe,0x7,0x0,0x0,
0x0,0x0,0xfc,0x0,0x0,0xe,0x0,0x0,
0x0,0x0,0x3f,0x0,0x0,0x3c,0x0,0x0,
0x0,0x0,0x1f,0xe0,0x1,0xf8,0x0,0x0,
0x0,0x0,0x7,0xff,0xff,0xf0,0x0,0x0,
0x0,0x0,0x1,0xff,0xff,0xc0,0x0,0x0,
0x0,0x0,0x0,0x1f,0xfc,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
};

SoftwareSerial mySerial(10, 11);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int fingerprintID = 0;


void setup()  // Start of setup
{                
   
  delay(100);  // This delay is needed to let the display to initialize
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
  display.clearDisplay();  // Clear the buffer
  display.setTextColor(WHITE);  // Set color of the text
  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3
  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
                               // To override this behavior (so text will run off the right side of the display - useful for
                               // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
                               // with setTextWrap(true).

  display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)

   startFingerprintSensor();
     displayLockScreen(); 

}  // End of setup






void loop()  // Start of loop
{



fingerprintID = getFingerprintID();
  delay(50);
  if(fingerprintID == 1)
  {
   
    displayCamacho();
    delay(5000);
    displayLockScreen();
  }

   if(fingerprintID == 0)
  {
    
    displayArango();
    delay(5000);
    displayLockScreen();
  }
  

}  




void displayArango()
{
   display.clearDisplay();  // Clear the display so we can refresh
  display.setFont(&FreeMono9pt7b);  // Set a custom font
  display.setTextSize(0); 
  display.setCursor(10, 10);  // (x,y)
  display.println("UNLOCK");  // Text or value to print
  display.setCursor(10, 30);  // (x,y)
  display.println("WELCOME!");  // Text or value to print
  display.setCursor(10, 50);  // (x,y)
  display.println("ARANGO");  // Text or value to print
   display.display();  // Print everything we set previously
}

void displayCamacho()
{
  display.clearDisplay();  // Clear the display so we can refresh
  display.setFont(&FreeMono9pt7b);  // Set a custom font
  display.setTextSize(0); 
  display.setCursor(10, 10);  // (x,y)
  display.println("UNLOCK");  // Text or value to print
  display.setCursor(10, 30);  // (x,y)
  display.println("WELCOME!");  // Text or value to print
  display.setCursor(10, 50);  // (x,y)
  display.println("CAMACHO");  // Text or value to print
   display.display();  // Print everything we set previously
}

void displayLockScreen()
{
  display.clearDisplay();  // Clear the display so we can refresh
  display.setFont(&FreeMono9pt7b);  // Set a custom font
  display.setTextSize(0); 
  display.setCursor(70, 30);  // (x,y)
  display.println("LOCK");  // Text or value to print
  display.drawBitmap(0,0,icon,60,60,WHITE);
  display.display();  // Print everything we set previously
}
void startFingerprintSensor()
{
  Serial.begin(9600);
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor");
  }
  Serial.println("Waiting for valid finger...");
}

int getFingerprintID() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}

