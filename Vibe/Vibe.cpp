/*
 Vibe.cpp - Library for controlling 5 vibrational motors independently with variable pattern and speed.
 Created by Yvan Chu, March 2, 2021.
*/

#include "Arduino.h"
#include "math.h"
#include "Vibe.h"

// initialize with an int array indicating which pins control the 5 
// vibration motors.
Vibe::Vibe(int inputPin[5])
{
    pinMode(pin[0], OUTPUT);
    pinMode(pin[1], OUTPUT);
    pinMode(pin[2], OUTPUT);
    pinMode(pin[3], OUTPUT);
    pinMode(pin[4], OUTPUT);
    pin[0] = inputPin[0];
    pin[1] = inputPin[1];
    pin[2] = inputPin[2];
    pin[3] = inputPin[3];
    pin[4] = inputPin[4];
    int mode[5] = {0, 0, 0, 0, 0};
    int freq[5] = {60, 60, 60, 60, 60};
    int intensity[5] = {255, 255, 255, 255, 255};
    int timeTarget[5] = {1000, 1000, 1000, 1000, 1000};
}

void Vibe::set(int p, int m, int f) {
    mode[p] = m;
    freq[p] = f;
    //update sets the timeTarget
    update(p, 0);
}

void Vibe::runLoop() {
    for (int i = 0; i < 5; i++) {
        if (mode[i]) {
            int time = millis() % timeTarget[i];
            update(i, time);
      }
    }
}

void Vibe::update(int ind, int time) {
    switch (mode[ind]) {
        case 1:
            pattern1m(ind, time);
            break;
        case 2:
            pattern2m(ind, time);
            break;
        case 3:
            pattern3m(ind, time);
            break;
        default:
            break;
    }
}

void Vibe::pattern1m(int ind, int time) {
    int on = 500;
    timeTarget[ind] = 60000/freq[ind];
    if (time < on) {
        analogWrite(pin[ind], 255);
    } else {
        analogWrite(pin[ind], 0);
    }
}

void Vibe::pattern2m(int ind, int time) {
    int on = 200;
    timeTarget[ind] = 60000/freq[ind];
    if (time < on) {
        analogWrite(pin[ind], 255);
    } else {
        analogWrite(pin[ind], 0);
    }
}

void Vibe::pattern3m(int ind, int time) {
    int on = 100;
    int off = 300;
    timeTarget[ind] = 60000/freq[ind];
    if (time < on || (time < (2 * on) + off && time > on + off)) {
        analogWrite(pin[ind], 255);
    } else {
        analogWrite(pin[ind], 0);
    }
}
