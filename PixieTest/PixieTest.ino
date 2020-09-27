#include "Adafruit_Pixie.h"
#include "SoftwareSerial.h"
#define PIXIEPIN 6 //Pin number
#define NUMPIXELS 1 //don't change

SoftwareSerial pixelSerial(-1, PIXIEPIN);
Adafruit_Pixie strip = Adafruit_Pixie(NUMPIXELS, &pixieSerial)
int r;
int g;
int b;
void setup()
{
  pixieSerial.begin(115200); //don't change
  strip.setBrightness(50); //alyssa you're welcome
  r = random(256);
  g = random(256);
  b = random(256);

  //blink twice
  for(int i = 0; i < 2; i++){
    strip.setPixelColor(0, 255, 255, 255);
    strip.show();
    delay(100);
  
    strip.setPixelColor(0, 0, 0, 0);
    strip.show();
    delay(100);
  }
  
}

void loop()
{
  strip.setPixelColor(0, r, g, b);
  strip.show();
  r++;
  g++;
  b++;
  if(r == 256){
    r = 0;
  }
  if(g == 256){
    g = 0;
  }
  if(b == 256){
    b = 0;
  }
  delay(10);
}
