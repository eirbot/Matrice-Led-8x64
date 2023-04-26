#ifndef PIXEL_ARTS_HPP
#define PIXEL_PIXEL_ARTS_HPP

#include <MD_MAX72xx.h>
#include <SPI.h>
#include "functions.hpp"


struct dinosaur {
    int position;
    int count_spam;
    bool check_spam;
    int score;
    bool win;
    int DELAY;
};


/**
 * @brief Function that returns the draw of a pokeball
 * 
 * @return int* the buffer that stores the datas of the drawing
 */
struct buffer* pokeball();


/**
 * @brief Function that returns the drawing of a laser
 * 
 * @param length the lenght of the 3xlenght laser
 * @return int* the buffer that stores the datas of the laser drawing
 */
struct buffer* laser(int length);


/**
 * @brief Function that returns the drawing of an alien
 * 
 * @param type the type of the alien, 1 or 2
 * @return int* the buffer that stores the datas of the alien drawing
 */
struct buffer* aliens(int type);


/**
 * @brief Function that generates a battle between alien 1 and 2, they will shoot 5x3 laser alternatively until a winner is randomly chosen
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which the battle will be displayed
 */
void battle_aliens(MD_MAX72XX* M);


/**
 * @brief Function that returns the drawing of a crew member of a famous game
 * 
 * @return int* the buffer that stores the datas of the crew member
 */
struct buffer* amogus();


/**
 * @brief Function that draws a famous crew with his iconic line
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which this will be displayed
 */
void sus(MD_MAX72XX* M);


/**
 * @brief function that returns the drawing of a famous penguin
 * 
 * @return int* the buffer that stores the datas of the crew penguin
 */
struct buffer* noot();


/**
 * @brief Function that draws a famous penguin and his line
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which this will be displayed
 */
void noot_noot(MD_MAX72XX* M);


struct buffer* random_obstacle();


struct buffer* controller();


void dinosaur_game(MD_MAX72XX* M);


struct dinosaur* dinosaur_game_routine(MD_MAX72XX* M, struct dinosaur* dinosaur);

#endif