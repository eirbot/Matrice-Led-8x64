#include <MD_MAX72xx.h>
#include <SPI.h>
#include <stdlib.h>
#include "pixel_arts.hpp"
#include "functions.hpp"
#include "caracters.hpp"

/**
 * @file pixel_arts.cpp
 * File in which there are functions that generates and draws some pixel-arts for/on a MD_MAX72XX display
 */


struct buffer* pokeball() {

    struct buffer* buffer = buffer_alloc(8);

    buffer_init(buffer, 8);

   buffer->buffer[3 + 0*8] = true;
   buffer->buffer[4 + 0*8] = true;

   buffer->buffer[1 + 1*8] = true;
   buffer->buffer[2 + 1*8] = true;
   buffer->buffer[4 + 1*8] = true;
   buffer->buffer[5 + 1*8] = true;
   buffer->buffer[6 + 1*8] = true;

   buffer->buffer[0 + 2*8] = true;
   buffer->buffer[4 + 2*8] = true;
   buffer->buffer[7 + 2*8] = true;


    for (int j = 3; j < 5; j++) {
       buffer->buffer[0 + j*8] = true;
       buffer->buffer[3 + j*8] = true;
       buffer->buffer[5 + j*8] = true;
       buffer->buffer[7 + j*8] = true;
    }
    
   buffer->buffer[0 + 5*8] = true;
   buffer->buffer[4 + 5*8] = true;
   buffer->buffer[7 + 5*8] = true;

   buffer->buffer[1 + 6*8] = true;
   buffer->buffer[2 + 6*8] = true;
   buffer->buffer[4 + 6*8] = true;
   buffer->buffer[5 + 6*8] = true;
   buffer->buffer[6 + 6*8] = true;

   buffer->buffer[3 + 7*8] = true;
   buffer->buffer[4 + 7*8] = true;

    return buffer;
}


struct buffer* laser(int length) {
    struct buffer* buffer = buffer_alloc(32);
    buffer_realloc(buffer, length);

    for (int i = 0; i < length; i++) {
        buffer->buffer[3 + i*8] = true;
        buffer->buffer[4 + i*8] = true;
    }

    return buffer;
}


struct buffer* aliens(int type) {
    struct buffer* buffer = buffer_alloc(32);
    buffer_realloc(buffer, 8);

    // Draw alien n°1 in buffer 1
    if (type == 1) {
        buffer->buffer[3 + 0*8] = true;
        buffer->buffer[4 + 0*8] = true;
        buffer->buffer[7 + 0*8] = true;

        buffer->buffer[2 + 1*8] = true;
        buffer->buffer[3 + 1*8] = true;
        buffer->buffer[4 + 1*8] = true;
        buffer->buffer[6 + 1*8] = true;

        buffer->buffer[1 + 2*8] = true;
        buffer->buffer[2 + 2*8] = true;
        buffer->buffer[4 + 2*8] = true;
        buffer->buffer[5 + 2*8] = true;
        buffer->buffer[6 + 2*8] = true;

        buffer->buffer[0 + 3*8] = true;
        buffer->buffer[1 + 3*8] = true;
        buffer->buffer[2 + 3*8] = true;
        buffer->buffer[4 + 3*8] = true;
        buffer->buffer[5 + 3*8] = true;
        buffer->buffer[6 + 3*8] = true;

        buffer->buffer[0 + 4*8] = true;
        buffer->buffer[1 + 4*8] = true;
        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[4 + 4*8] = true;
        buffer->buffer[5 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;

        buffer->buffer[1 + 5*8] = true;
        buffer->buffer[2 + 5*8] = true;
        buffer->buffer[4 + 5*8] = true;
        buffer->buffer[5 + 5*8] = true;
        buffer->buffer[6 + 5*8] = true;
        
        buffer->buffer[2 + 6*8] = true;
        buffer->buffer[3 + 6*8] = true;
        buffer->buffer[4 + 6*8] = true;
        buffer->buffer[6 + 6*8] = true;

        buffer->buffer[3 + 7*8] = true;
        buffer->buffer[4 + 7*8] = true;
        buffer->buffer[7 + 7*8] = true;
    }

    // Draw alien n°2 in buffer 2
    if (type == 2) {
        buffer->buffer[1 + 0*8] = true;
        buffer->buffer[2 + 0*8] = true;
        buffer->buffer[7 + 0*8] = true;

        buffer->buffer[0 + 1*8] = true;
        buffer->buffer[3 + 1*8] = true;
        buffer->buffer[4 + 1*8] = true;
        buffer->buffer[6 + 1*8] = true;

        buffer->buffer[2 + 2*8] = true;
        buffer->buffer[4 + 2*8] = true;
        buffer->buffer[5 + 2*8] = true;
        buffer->buffer[6 + 2*8] = true;
        buffer->buffer[7 + 2*8] = true;

        buffer->buffer[2 + 3*8] = true;
        buffer->buffer[3 + 3*8] = true;
        buffer->buffer[5 + 3*8] = true;

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[3 + 4*8] = true;
        buffer->buffer[5 + 4*8] = true;
    
        buffer->buffer[2 + 5*8] = true;
        buffer->buffer[4 + 5*8] = true;
        buffer->buffer[5 + 5*8] = true;
        buffer->buffer[6 + 5*8] = true;
        buffer->buffer[7 + 5*8] = true;

        buffer->buffer[0 + 6*8] = true;
        buffer->buffer[3 + 6*8] = true;
        buffer->buffer[4 + 6*8] = true;
        buffer->buffer[6 + 6*8] = true;

        buffer->buffer[1 + 7*8] = true;
        buffer->buffer[2 + 7*8] = true;
        buffer->buffer[7 + 7*8] = true;
    }

    return buffer;
}


void battle_aliens(MD_MAX72XX* M) {
    struct buffer* alien_1 = aliens(1);
    struct buffer* alien_2 = aliens(2);

    struct buffer* las = laser(5);

    print_on_column(M, alien_1, 31);
    print_on_column(M, alien_2, 7);

    int side = 0;

    bool check = true;

    while(random(10) > 1 || check) {

        print_with_scroll(M, las, side, 8, 23);

        if (side == 0) {
            for (int i = 0; i < 14; i++) {
                scrolling(M, 8, 23);
            }

            for (int i = 0; i < 3; i++) {
                flicker(M, 24, 31, 0, 7);
            }
        }

        if (side == 1) {
            for (int i = 0; i < 14; i++) {
                scrolling_reverse(M, 8, 23);
            }

            for (int i = 0; i < 3; i++) {
                flicker(M, 0, 7, 0, 7);
            }
        }

        check = false;

        side = (1 - side);
    }
    

    if (side == 0) {
        
        clear_matrix(M, 0, 8);
        delay(1000);

        clear_matrix(M, 0, 31);

        print_with_scroll(M, alien_1, side, 0, 31);
        for (int i = 0; i < 22; i++) {
            scrolling(M, 0, 31);
        }
        write_word(M, "WINS", 1, 0, 0, 20);
    }
    if (side == 1) {

        clear_matrix(M, 21, 31);
        delay(1000);

        clear_matrix(M, 0, 31);

        print_with_scroll(M, alien_2, side, 0, 31);
        for (int i = 0; i < 22; i++) {
            scrolling_reverse(M, 0, 31);
        }

        
        write_word(M, "WINS", 1, 0, 0, 31);
    }


    for (int i = 0; i < 5; i++) {
        inversion(M, 0, 8, 0, 31);
    }

    delay(2000);

    buffer_free(alien_1);
    buffer_free(alien_2);
    buffer_free(las);

    clear_matrix(M, 0, 31);
}


struct buffer* amogus() {
    struct buffer* buffer = buffer_alloc(7);

   buffer->buffer[2 + 0*8] = true;
   buffer->buffer[4 + 0*8] = true;
   buffer->buffer[5 + 0*8] = true;
   buffer->buffer[6 + 0*8] = true;

   buffer->buffer[1 + 1*8] = true;
   buffer->buffer[3 + 1*8] = true;
   buffer->buffer[7 + 1*8] = true;

    for (int j = 2; j < 4; j++) {
       buffer->buffer[1 + j*8] = true;
       buffer->buffer[6 + j*8] = true;
    }

   buffer->buffer[1 + 4*8] = true;
   buffer->buffer[7 + 4*8] = true;

    for (int i = 2; i < 7; i++) {
       buffer->buffer[i + 5*8] = true;
    }

    for (int i = 3; i < 6; i++) {
       buffer->buffer[i + 6*8] = true;
    }

    return buffer;
}


void sus(MD_MAX72XX* M) {
    struct buffer* buffer = amogus();

    print_with_scroll(M, buffer, 0, 0, 31);

    for(int i = 0; i < 22; i++) {
        scrolling(M, 0, 31);
    }

    write_word(M, "SUS", 1, 0, 0, 20);

    delay(3000);

    clear_matrix(M, 0, 31);

    buffer_free(buffer);
}


struct buffer* noot() {
    struct buffer* buffer = buffer_alloc(13);

    for (int i = 2; i < 6; i++) {
       buffer->buffer[i + 0*8] = true;
    }

   buffer->buffer[1 + 1*8] = true;
   buffer->buffer[6 + 1*8] = true;

    for (int j = 2; j < 7; j++) {
       buffer->buffer[0 + j*8] = true;
       buffer->buffer[7 + j*8] = true;
    }
    
   buffer->buffer[1 + 7*8] = true;
   buffer->buffer[6 + 7*8] = true;

    for (int i = 2; i < 6; i++) {
       buffer->buffer[i + 8*8] = true;
    }

   buffer->buffer[2 + 5*8] = 8;
   buffer->buffer[3 + 5*8] = 8;
   buffer->buffer[2 + 6*8] = 8;
   buffer->buffer[3 + 6*8] = 8;

   buffer->buffer[4 + 9*8] = 8;
   buffer->buffer[5 + 9*8] = 8;

    for (int j = 10; j < 13; j++) {
       buffer->buffer[3 + j*8] = 8;
       buffer->buffer[6 + j*8] = 8;
    }

   buffer->buffer[4 + 12*8] = 8;
   buffer->buffer[5 + 12*8] = 8;

    return buffer;
}


void noot_noot(MD_MAX72XX* M) {
    struct buffer* n = noot();

    print_on_column(M, n, 31);

    write_word(M, "NOOT NOOT", 0, 1, 0, 18);
    scrolling_to_end(M, 1, 0, 18);

    buffer_free(n);
}


struct buffer* random_obstacle() {
    struct buffer* obstacle = buffer_alloc(32);
    buffer_realloc(obstacle, 1);

    int height = random(2, 5);

    for (int i = 7; i > 7 - height; i--) {
        obstacle->buffer[i] = true;
    }

    return obstacle;
}


struct buffer* controller() {
    struct buffer* buffer = buffer_alloc(16);
    // buffer_realloc(buffer, 17);

    for (int i = 2; i < 6; i++) {
        for (int j = 2; j < 6; j++) {
            buffer->buffer[i + j *8] = true;
        }
    }

    for (int i = 4; i < 6; i++) {
        for (int j = 9; j < 11; j++) {
            buffer->buffer[i + j * 8] = true;
        }
    }

    for (int i = 2; i < 4; i++) {
        for (int j = 12; j < 14; j++) {
            buffer->buffer[i + j * 8] = true;
        }
    }

    for (int i = 0; i < 7; i++) {
        buffer->buffer[i + 0 * 8] = true;
        buffer->buffer[i + 15 * 8] = true;
    }

    for (int j = 0; j < 16; j++) {
        buffer->buffer[0 + j * 8] = true;
        buffer->buffer[7 + j * 8] = true;
    }

    return buffer;
}


void dinosaur_game(MD_MAX72XX* M) {
    
    int* boutons;

    boutons = read_controller();

    if (boutons[3] == 0) {

        struct  dinosaur* dinosaur = (struct dinosaur*) malloc(sizeof(struct dinosaur));
        
        dinosaur->position = 7;
        dinosaur->check_spam = false;
        dinosaur->count_spam = 0;
        dinosaur->score = 0;
        dinosaur->win = true;

        while (dinosaur->win) {
            dinosaur = dinosaur_game_routine(M, dinosaur);
        }

        clear_matrix(M, 0, 31);

        String score = String(dinosaur->score);

        write_word(M, score, 1, 0, 0, 31);

        delay(3000);

        clear_matrix(M, 0, 31);

        free(dinosaur);
    }

    free_boutons(boutons);

    struct buffer* contr = controller();

    print_on_column(M, contr, 23);
    flicker(M, 9, 11, 2, 3);
    flicker(M, 9, 11, 2, 3);
    flicker(M, 9, 11, 2, 3);
    flicker(M, 9, 11, 2, 3);

    delay(500);

    clear_matrix(M, 0, 31);

    // buffer_free(contr);
}


struct dinosaur* dinosaur_game_routine(MD_MAX72XX* M, struct dinosaur* dinosaur) {

    int* boutons;

    struct buffer* obstacle = random_obstacle();

    print_with_scroll(M, obstacle, 0, 0, 31);
    dinosaur->score++;

    if (M->getPoint(dinosaur->position, 28) == 1) {
        dinosaur->win = false;
    }

    for (int i = 0; i < 15; i++) {
        boutons = read_controller();
        
        if (dinosaur->position == 7) {
            dinosaur->check_spam = false;
            dinosaur->count_spam = 0;
        }

        if (dinosaur->count_spam == 10) {
            dinosaur->check_spam = true;
        }

        if (boutons[3] == 0 && dinosaur->position > 0 && dinosaur->check_spam == false) {
            dinosaur->position--;
        }
        else if (dinosaur->position < 7) {
            dinosaur->position++;
            dinosaur->check_spam = true;
        }

        if (boutons[3] == 0) {
            dinosaur->count_spam++;
        }

        M->setPoint(dinosaur->position, 29, true);     

        dinosaur->DELAY = dinosaur->score/10;

        if (dinosaur->DELAY > 70) {
            dinosaur->DELAY = 70;
        }

        scrolling(M, 0, 31, 70 - dinosaur->DELAY);
        M->setPoint(dinosaur->position, 30, false);

        if (M->getPoint(dinosaur->position, 28) == 1) {
            dinosaur->win = false;
            break;
        }

        free_boutons(boutons);
        dinosaur->score++;
    }

    buffer_free(obstacle);

    return dinosaur;
}