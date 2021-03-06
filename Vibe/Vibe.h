/*
  Vibe.h - Library for controlling 5 vibrational motors independently with variable pattern and speed.
  Created by Yvan Chu, March 2, 2021.
*/

#ifndef Vibe_h
#define Vibe_h

#include "Arduino.h"

class Vibe
{
  public:
    //initialize with the 5 input pins that the vibrational motors are connected to
    Vibe(int inputPin[5]);
    
    //indicate the pin port
    int pin[5];
    
    //indicate the mode of vibration
    //0 - no vibration
    //1 - long beat (.5 sec)
    //2 - short beat (.2 sec)
    //3 - heartbeat (.1-.3-.1 sec)
    int mode[5];
    
    //indicate the frequency (bpm)
    int freq[5];
    
    //(not implemented) the intensity of the vibration (0-255)
    int intensity[5];
    
    //sets the pth pin to vibration mode m with f bpm
    void set(int p, int m, int f);
    
    //put in the loop() to update vibration status
    void runLoop();
  private:
    //time intervals for each beat
    int timeTarget[5];
    
    //updates the indth pin
    void update(int ind, int time);
    
    //updates the indth pin for different patterns
    void pattern1m(int ind, int time);
    void pattern2m(int ind, int time);
    void pattern3m(int ind, int time);
};

#endif
