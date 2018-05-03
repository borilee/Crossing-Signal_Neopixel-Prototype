#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6 // pin you attach to your board



Adafruit_NeoPixel strip = Adafruit_NeoPixel(48, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Set keyboard at pin13
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  //Initialize Neopixel
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}



void loop() {

  if (Serial.available()) {
    char control = Serial.read();

    if (control == '1') {
      BlinkingGreen();
    }
    if (control == '2') {
      FullGreen();
    }
    if (control == "3") {
      LoadingGreen();
    }
    if (control == "4") {
      FullRed();
    }
    if (control == "5") {
      Cross();
    }
    if (control == "6") {
      NoCross();
    }
    else {
      for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, 0, 0);
        strip.show();
      }
    }
  }
}


void BlinkingGreen() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 255, 0);
  }
  delay(500);
  strip.show();
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  delay(500);
  strip.show();
}

void FullGreen() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 255, 0);
    strip.show();
  }

}

void LoadingGreen() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 255, 0);
    strip.show();
  }
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
    strip.setPixelColor(strip.numPixels() - i, 0, 0, 0);
    delay(1000);
    strip.show();
  }
}

void FullRed() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
  }
}

void Cross() {
  //Blicking
  for (uint16_t j = 0; j < 2; j++) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 255, 0);
    }
    delay(200);
    strip.show();
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 0, 0);
    }
    delay(200);
    strip.show();
    j++;
  }
  //Full green
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 255, 0);
    strip.show();
  }
  delay(15000); //wait for 15 sec to loading green
  //Loading green
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
    strip.setPixelColor(strip.numPixels() - i, 0, 0, 0);
    delay(1000);
    strip.show();
  }
  //Full red
  delay(1000); //wait for 1sec to Red
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
  }
  //turn off
  delay(2000);//wait for 2sec to turn off
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
}

void NoCross() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
  }
}

