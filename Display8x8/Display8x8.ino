#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1); // DIN, CLK, CS, NRDEV

byte letraT[] = {
  B11111111,
  B11111111,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};

byte letraD[] = {
  B01111000,
  B01101100,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01101100,
  B01111000
};

byte letraC[] = {
  B00011100,
  B01111110,
  B01100110,
  B01100000,
  B01100000,
  B01100110,
  B01111110,
  B00011100
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
}

void letrat() {
  for (int i = 0; i < 8; i++)  {
    lc.setRow(0, i, letraT[i]);
  }
}

void letrad() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, letraD[i]);
  }
}

void letrac() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, letraC[i]);
  }
}


void loop() {
  letrat();
  delay(1000);
  letrad();
  delay(1000);
  letrac();
  delay(1000);



}
