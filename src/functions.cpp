#include "functions.hpp"
#include "caracters.hpp"
#include "pixel_arts.hpp"

#include <MD_MAX72xx.h>
#include <SPI.h>


/**
 * @file functions.cpp
 * File in which there are functions for general manipulation for a MD_MAX72XX display
 */


/// Define the base delay used when scrolling is applied on the display
#define BASE_DELAY 70
/// Define the delay used when flicker is applied on the display
#define FLICKER_DELAY 50
/// Define the dalay used when pixel inversion is applied on the display
#define INVERSION_DELAY 500


#define HORIZONTAL A1
#define VERTICAL A2

#define BAS 6
#define HAUT 7
#define JOYSTICK 8


void test_all_points(MD_MAX72XX* M) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 32; j++) {    
        M->setPoint(i, j, 1);
        M->update(M->ON);
        M->update(M->OFF);
        delay(BASE_DELAY);
        M->setPoint(i, j, 0);
    }
  }
}


void scrolling(MD_MAX72XX* M, int c_min, int c_max, int DELAY) {
    int state;
    for (int i = 0; i < 8; i++) {
        for (int j = c_max; j > c_min; j--) {
            state = M->getPoint(i, j - 1);
            M->setPoint(i, j, state);
        }
    }
    for (int i = 0; i < 8; i++) {
        M->setPoint(i, c_min, 0);    
    }
    M->update(M->ON);
    M->update(M->OFF);
    delay(DELAY);
}


void scrolling_reverse(MD_MAX72XX* M, int c_min, int c_max) {
    int state;
    for (int i = 0; i < 8; i++) {
        for (int j = c_min; j < c_max; j++) {
            state = M->getPoint(i, j + 1);
            M->setPoint(i, j, state);
        }
    }
    for (int i = 0; i < 8; i++) {
        M->setPoint(i, c_max, 0);    
    }
    M->update(M->ON);
    M->update(M->OFF);
    delay(BASE_DELAY);
}


void scrolling_to_end(MD_MAX72XX* M, int way, int c_min, int c_max) {

    int count_tot = 0;

    int count = 0;

    int check = 1;

    while (count_tot <= 6|| check) {
        for (int i = 0; i < 8; i++) {
            if (M->getPoint(i, (1 - way)*c_max + way*c_min)) {
                count++;
            }
        }

        if (count == 0) {
            count_tot++;
        }
        else {
            count_tot = 0;
            check = 0;
        }

        if (check) {
            count_tot = 0;
        }

        count = 0;

        if (way == 0) {
            scrolling(M, c_min, c_max);
        }
        else {
            scrolling_reverse(M, c_min, c_max);
        }
    }
}


void inversion(MD_MAX72XX* M, int l_min, int l_max, int c_min, int c_max) {
    int status;
    for (int k = 0; k < 2; k++) {
        for (int i = l_min; i <= l_max; i++) {
            for (int j = c_min; j <= c_max; j++) {
                status = M->getPoint(i, j);
                M->setPoint(i, j, !status);
            }
        }
        M->update(M->ON);
        M->update(M->OFF);
        delay(INVERSION_DELAY);
    }
}


void flicker(MD_MAX72XX* M, int c_min, int c_max, int l_min, int l_max) {
    
    struct buffer* buffer = buffer_alloc(c_max - c_min);
    
    for (int i = l_min; i <= l_max; i++) {
        for (int j = c_min; j <= c_max; j++) {
            buffer->buffer[i + j*8] = M->getPoint(i, j);
            M->setPoint(i, j, 0);
        }
    }
    M->update(M->ON);
    M->update(M->OFF);
    delay(FLICKER_DELAY);

    for (int i = l_min; i <= l_max; i++) {
        for (int j = c_min; j <= c_max; j++) {
            M->setPoint(i, j, buffer->buffer[i + j*8]);
        }
    }
    M->update(M->ON);
    M->update(M->OFF);
    delay(FLICKER_DELAY);

    buffer_free(buffer);
}


void print_with_scroll(MD_MAX72XX* M, struct buffer* buffer, int way, int c_min, int c_max) {
    if (way == 0) {
        for (int j = 0; j < buffer->size; j++) {
            for (int i = 0; i < 8; i++) {
                M->setPoint(i, c_min, buffer->buffer[i + j*8]);
            }
            scrolling(M, c_min, c_max);
        }
        scrolling(M, c_min, c_max);
    }
    
    if (way == 1) {
        for (int j = buffer->size - 1; j >= 0; j--) {
            for (int i = 0; i < 8; i++) {
                M->setPoint(i, c_max, buffer->buffer[i + j*8]);
            }
            scrolling_reverse(M, c_min, c_max);
        }
        scrolling_reverse(M, c_min, c_max);
    }
}


void print_on_column(MD_MAX72XX* M, struct buffer* buffer, int c) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < buffer->size; j++) {
            if (c - j >= 0) {
                M->setPoint(i, c - j, buffer->buffer[i + j*8]);
            }
        }
    }
    M->update(M->ON);
    M->update(M->OFF);
}


void clear_matrix(MD_MAX72XX* M, int c_min, int c_max) {
    for (int i = 0; i < 8; i++) {
        for (int j = c_min; j <= c_max; j++) {
            M->setPoint(i, j, 0);
        }
    }
    M->update(M->ON);
    M->update(M->OFF);
}


struct buffer* buffer_alloc(int width) {
    struct buffer* buffer = (struct buffer*) malloc(sizeof(struct buffer));
    buffer->buffer = (bool*) malloc(sizeof(bool)*width);
    buffer_init(buffer, width);
    return buffer;
}


void buffer_realloc(struct buffer* buffer, int width) {
    realloc(buffer->buffer, sizeof(int)*(8*width + 1));
    buffer_init(buffer, width);
}


void buffer_init(struct buffer* buffer, int width) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < width; j++) {
            buffer->buffer[i + j*8] = 0;
        }
    }
    buffer->size = width;
}


void buffer_free(struct buffer* buffer) {
    free(buffer->buffer);
    free(buffer);
}


void random_stuffs(MD_MAX72XX* M) {
    int test = random(7);

    if (test < 1 && test >= 0) {
        write_word(M, "EIRBOT", 1, 0, 0, 31);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                flicker(M, 0, 31, 0, 7);
            }
            delay(1000);
        }
    }   


    else if (test < 2 && test >= 1) {
        if (random(2) >= 1) {
            write_word(M, "DECOLT'EIRB <3", 0, 0, 0, 31);
            scrolling_to_end(M, 0, 0, 31);
        }
        else {
            write_word(M, "_ _ _ _ _", 0, 1, 0, 31);
            scrolling_to_end(M, 1, 0, 31);
        }
    }

    else if (test < 3 && test >= 2) {
        write_word(M, "DEMOUL'EIRB <3", 0, 0, 0, 31);
        scrolling_to_end(M, 0, 0, 31);
    }

    else if (test < 4 && test >= 3) {
        battle_aliens(M);
    }

    else if (test < 5 && test >= 6) {
        struct buffer* poke = pokeball();

        print_on_column(M, poke, 19);

        delay(2000);

        buffer_free(poke);
    }

    else if (test < 6 && test >= 5) {
        sus(M);
    }

    else {
        noot_noot(M);
    }

    clear_matrix(M, 0, 31);
}


void parts(MD_MAX72XX* M) {
    int test = random(5);

    if (test < 1 && test >= 0) {
        write_word(M, "BEAR", 0, 0, 0, 31);
        scrolling_to_end(M, 0, 0, 31);
    }
    else if (test < 2 && test >= 1) {
        write_word(M, "EMS PROTO", 0, 0, 0, 31);
        scrolling_to_end(M, 0, 0, 31);
    }
    else if (test < 3 && test >= 2) {
        write_word(M, "ELSYS DESIGN", 0, 0, 0, 31);
        scrolling_to_end(M, 0, 0, 31);
    }
    else if (test < 4 && test >= 3) {
        write_word(M, "RS", 0, 0, 0, 31);
        scrolling_to_end(M, 0, 0, 31);
    }
    else {
        write_word(M, "LE EIRBLAB", 0, 0, 0, 31);
        scrolling_to_end(M, 0, 0, 31);
    }
}


void random_stuffs_part_friendly(MD_MAX72XX* M) {
    int test = random(4);

    if (test < 1 && test >= 0) {
        parts(M);
    }
    else if (test < 2 && test >= 1) {
        battle_aliens(M);
    }
    else if (test < 3 && test >= 2) {
        write_word(M, "JE PEUX VRAIMENT ECRIRE CE QUE JE VEUX SUR L'AFFICHEUR LCD MD_MAX72X, LE MESSAGE PEUT VRAIMENT ETRE TRES TRES LONG CA NE POSE PAS DE PROBLEMES.", 0, 0, 0, 31);
        scrolling_to_end(M, 0, 0, 31);
    }
    else {
        write_word(M, "EIRBOT", 1, 0, 0, 31);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                flicker(M, 0, 31, 0, 7);
            }
            delay(1000);
        }
    }

    clear_matrix(M, 0, 31);
}


void init_controller() {
    pinMode(HORIZONTAL, INPUT_PULLUP);
    pinMode(VERTICAL, INPUT_PULLUP);

    pinMode(BAS, INPUT_PULLUP);
    pinMode(HAUT, INPUT_PULLUP);
    pinMode(JOYSTICK, INPUT_PULLUP);
}


int* read_controller() {
    
    int* bouton = (int*) malloc(sizeof(int)*5);
    
    int horizontal = analogRead(HORIZONTAL);
    int vertical = analogRead(VERTICAL);

    int bas = digitalRead(BAS);
    int haut = digitalRead(HAUT);
    int joysitck  = digitalRead(JOYSTICK);

    bouton[0] = horizontal;
    bouton[1] = vertical;
    bouton[2] = bas;
    bouton[3] = haut;
    bouton[4] = joysitck;

    // Serial.print(vert);
    // Serial.print(" ");
    // Serial.println(hori);

    // Serial.print(horizontal);
    // Serial.print(" ");

    // Serial.print(vertical);
    // Serial.print(" ");

    // Serial.print(bas);
    // Serial.print(" ");

    // Serial.print(haut);
    // Serial.print(" ");
    
    // Serial.println(joysitck);

    return bouton;
}


void free_boutons(int* boutons) {
    free(boutons);
}