#include <Arduino.h>

#include "caracters.hpp"
#include "functions.hpp"
#include "pixel_arts.hpp"

#include <MD_MAX72xx.h>
#include <SPI.h>

/**
 * @file main.cpp
 * Main file that stores the main program that will be executed the the arduino
 */

#define Max7219_pinCLK 2
#define Max7219_pinCS 3
#define Max7219_pinDIN 4


void setup() {
  pinMode(Max7219_pinCLK, OUTPUT);
  pinMode(Max7219_pinCS, OUTPUT);
  pinMode(Max7219_pinDIN, OUTPUT);

  // Serial.begin(9600);

  randomSeed(analogRead(0));
}


MD_MAX72XX* M = new MD_MAX72XX(M->FC16_HW, 4, 2, 3, 4);
bool check = true;

void loop() {
  M->begin();
  M->update(M->OFF);
  while(1) {
    // random_stuffs_part_friendly(M);

    init_controller();
    dinosaur_game(M);

    // write_word(M, "EIRBOT", 0, 0, 0, 31);
    // scrolling_to_end(M, 0, 0, 31);

    // battle_aliens(M);
  }
}