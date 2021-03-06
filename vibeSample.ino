/*
 vibeSample - Demonstrating the Vibe library by showing varying modes and frequencies.
 Created by Yvan Chu, March 6, 2021.
*/
#include <Vibe.h>

#define vibeOutPin 3

int m = 1;
int f = 15;
int pins[5] = {10, 9, 6, 5, 3};
Vibe vibe(pins);

void setup() {
  // put your setup code here, to run once:
  //pinMode(vibeOutPin, OUTPUT);
  Serial.begin(9600);
  vibe.set(0, 1, 30);
  vibe.set(1, 1, 30);
  vibe.set(2, 1, 30);
  vibe.set(3, 1, 30);
  vibe.set(4, 1, 30);
  Serial.print("\n initialization complete");
}

void loop() {
  vibe.runLoop();
  if (millis() % 5000 <= 0) {
    if (m <= 3) {    
      if (f < 130) {
        f *= 2;
        vibe.set(0, m, f);
        vibe.set(1, m, f);
        vibe.set(2, m, f);
        vibe.set(3, m, f);
        vibe.set(4, m, f);
        Serial.print("\n mode:");
        Serial.print(m);
        Serial.print("\n Frequency (bpm):");
        Serial.print(f);
      } else {
        m += 1;
        f = 30;
      }
    } else {
      vibe.set(0, 0, 30);
      vibe.set(1, 0, 30);
      vibe.set(2, 0, 30);
      vibe.set(3, 0, 30);
      vibe.set(4, 0, 30);
    }
  }
}
