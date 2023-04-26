#include <MD_MAX72xx.h>
#include <SPI.h>
#include "functions.hpp"
#include "caracters.hpp"

#include <string.h>


/**
 * @file caracters.cpp
 * File in which there functions that generates and draws ASCII caracters for/on a MD_MAX72XX displays
 */


struct buffer* write_letter(char letter) {
    struct buffer *buffer = buffer_alloc(32);

    // Write " " into buffer
    if (letter == 32) {
        buffer_realloc(buffer, 4);
    }

    // Write "'" into buffer
    if (letter == 39) {
        buffer_realloc(buffer, 2);

        buffer->buffer[3 + 0*8] = true;

        buffer->buffer[1 + 1*8] = true;
        buffer->buffer[2 + 1*8] = true;
    }

    // Write "(" into buffer
    if (letter == 40) {
        buffer_realloc(buffer, 2);

        for (int i = 2; i < 7; i ++) {
            buffer->buffer[i + 0*8] = true;
        }

        buffer->buffer[1 + 1*8] = true;
        buffer->buffer[7 + 1*8] = true;
    }

    // Write ")" into buffer
    if (letter == 41) {
        buffer_realloc(buffer, 2);

        buffer->buffer[1 + 0*8] = true;
        buffer->buffer[7 + 0*8] = true;

        for (int i = 2; i < 7; i ++) {
            buffer->buffer[i + 1*8] = true;
        }
    }

    // Write "x" into buffer
    if (letter == 42) {
        buffer_realloc(buffer, 5);

        buffer->buffer[3 + 0*8] = true;
        buffer->buffer[7 + 0*8] = true;

        buffer->buffer[4 + 1*8] = true;
        buffer->buffer[6 + 1*8] = true;

        buffer->buffer[5 + 2*8] = true;

        buffer->buffer[4 + 3*8] = true;
        buffer->buffer[6 + 3*8] = true;

        buffer->buffer[3 + 4*8] = true;
        buffer->buffer[7 + 4*8] = true;
    }

    // Write "+" into buffer
    if (letter == 43) {
        buffer_realloc(buffer, 5);

        for (int j = 0; j < 3; j++) {
            buffer->buffer[5 + j*8] = true;
        }

        for (int i = 3; i < 8; i++) {
            buffer->buffer[i + 2*8] = true;
        }

        for (int j = 3; j < 5; j++) {
            buffer->buffer[5 + j*8] = true;
        }
    }

    // Write "," into buffer
    if (letter == 44) {
        buffer_realloc(buffer, 2);

        buffer->buffer[7 + 0*8] = true;

        buffer->buffer[6 + 1*8] = true;
    }

    // Write "-" into buffer
    if (letter == 45) {
        buffer_realloc(buffer, 5);

        for (int j = 0; j < 5; j++) {
            buffer->buffer[4 + j*8] = true;
        }
    }

    // Write "." into buffer
    if (letter == 46) {
        buffer_realloc(buffer, 1);

        buffer->buffer[7 + 0*8] = true;
    }

    // Write "/" into buffer
    if (letter == 47) {
        buffer_realloc(buffer, 5);

        buffer->buffer[7 + 0*8] = true;

        buffer->buffer[6 + 1*8] = true;
        buffer->buffer[5 + 1*8] = true;

        buffer->buffer[4 + 2*8] = true;

        buffer->buffer[3 + 3*8] = true;
        buffer->buffer[2 + 3*8] = true;

        buffer->buffer[1 + 4*8] = true;
    }

    // Write "0" into buffer
    if (letter == 48) {
        buffer_realloc(buffer, 5);

        for (int i = 2; i < 7; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        buffer->buffer[1 + 1*8] = true;
        buffer->buffer[3 + 1*8] = true;
        buffer->buffer[7 + 1*8] = true;

        buffer->buffer[1 + 2*8] = true;
        buffer->buffer[4 + 2*8] = true;
        buffer->buffer[7 + 2*8] = true;

        buffer->buffer[1 + 3*8] = true;
        buffer->buffer[5 + 3*8] = true;
        buffer->buffer[7 + 3*8] = true;

        for (int i = 2; i < 7; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "1" into buffer
    if (letter == 49) {
        buffer_realloc(buffer, 3);

        buffer->buffer[2 + 0*8] = true;
        buffer->buffer[7 + 0*8] = true;

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 1*8] = true;
        }

        buffer->buffer[7 + 2*8] = true;
    }

    // Write "2" into buffer
    if (letter == 50) {
        buffer_realloc(buffer, 5);

        buffer->buffer[2 + 0*8] = true;
        buffer->buffer[7 + 0*8] = true;

        buffer->buffer[1 + 1*8] = true;
        buffer->buffer[6 + 1*8] = true;
        buffer->buffer[7 + 1*8] = true;

        buffer->buffer[1 + 2*8] = true;
        buffer->buffer[5 + 2*8] = true;
        buffer->buffer[7 + 2*8] = true;

        buffer->buffer[1 + 3*8] = true;
        buffer->buffer[4 + 3*8] = true;
        buffer->buffer[7 + 3*8] = true;

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[3 + 4*8] = true;
        buffer->buffer[7 + 4*8] = true;
    }

    // Write "3" into buffer
    if (letter == 51) {
        buffer_realloc(buffer, 5);

        buffer->buffer[2 + 0*8] = true;
        buffer->buffer[6 + 0*8] = true;

        buffer->buffer[1 + 1*8] = true;
        buffer->buffer[7 + 1*8] = true;

        for (int j = 2; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[3 + 4*8] = true;
        buffer->buffer[5 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
    }

    // Write "4" into buffer
    if (letter == 52) {
        buffer_realloc(buffer, 5);

        buffer->buffer[4 + 0*8] = true;
        buffer->buffer[5 + 0*8] = true;

        buffer->buffer[3 + 1*8] = true;
        buffer->buffer[5 + 1*8] = true;

        buffer->buffer[2 + 2*8] = true;
        buffer->buffer[5 + 2*8] = true;

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 3*8] = true;
        }

        buffer->buffer[5 + 4*8] = true;
    }

    // Write "5" into buffer
    if (letter == 53) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 5; i++) {
            buffer->buffer[i + 0*8] = true;
        }
        buffer->buffer[7 + 0*8] = true;

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        buffer->buffer[1 + 4*8] = true;
        buffer->buffer[5 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
    }

    // Write "6" into buffer
    if (letter == 54) {
        buffer_realloc(buffer, 5);

        for (int i = 2; i < 7; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[5 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
    }

    // Write "7" into buffer
    if (letter == 55) {
        buffer_realloc(buffer, 5);

        for (int j = 0; j < 2; j++) {
            buffer->buffer[1 + j*8] = true;
        }

        buffer->buffer[1 + 2*8] = true;
        for (int i = 4; i < 8; i++) {
            buffer->buffer[i + 2*8] = true;
        }

        buffer->buffer[1 + 3*8] = true;
        buffer->buffer[3 + 3*8] = true;

        buffer->buffer[1 + 4*8] = true;
        buffer->buffer[2 + 4*8] = true;
    }

    // Write "8" into buffer
    if (letter == 56) {
        buffer_realloc(buffer, 5);

        buffer->buffer[2 + 0*8] = true;
        buffer->buffer[3 + 0*8] = true;
        buffer->buffer[5 + 0*8] = true;
        buffer->buffer[6 + 0*8] = true;

        for (int j = 1;j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[3 + 4*8] = true;
        buffer->buffer[5 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
    }

    // Write "9" into buffer
    if (letter == 57) {
        buffer_realloc(buffer, 5);

        buffer->buffer[2 + 0*8] = true;
        buffer->buffer[3 + 0*8] = true;
        buffer->buffer[6 + 0*8] = true;

        for (int j = 1;j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        for (int i = 2; i < 7; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write ":" into buffer
    if (letter == 58) {
        buffer_realloc(buffer, 1);

        buffer->buffer[4 + 0*8] = true;
        buffer->buffer[6 + 0*8] = true;
    }

    // Write ";" into buffer
    if (letter == 59) {
        buffer_realloc(buffer, 2);

        buffer->buffer[7 + 0*8] = true;

        buffer->buffer[4 + 1*8] = true;
        buffer->buffer[6 + 1*8] = true;
    }

    // Write "<" into buffer
    if (letter == 60) {
        buffer_realloc(buffer, 4);

        buffer->buffer[4 + 0*8] = true;

        buffer->buffer[3 + 1*8] = true;
        buffer->buffer[5 + 1*8] = true;

        buffer->buffer[2 + 2*8] = true;
        buffer->buffer[6 + 2*8] = true;

        buffer->buffer[1 + 3*8] = true;
        buffer->buffer[7 + 3*8] = true;
    }

    // Write "=" into buffer
    if (letter == 61) {
        buffer_realloc(buffer, 4);

        for (int j = 0; j < 5; j++) {
            buffer->buffer[3 + j*8] = true;
            buffer->buffer[5 + j*8] = true;
        }
    }

    // Write ">" into buffer
    if (letter == 62) {
        buffer_realloc(buffer, 4);

        buffer->buffer[1 + 0*8] = true;
        buffer->buffer[7 + 0*8] = true;

        buffer->buffer[2 + 1*8] = true;
        buffer->buffer[6 + 1*8] = true;

        buffer->buffer[3 + 2*8] = true;
        buffer->buffer[5 + 2*8] = true;

        buffer->buffer[4 + 3*8] = true;
    }

    // Write "?" into buffer
    if (letter == 63) {
        buffer_realloc(buffer, 5);

        buffer->buffer[2 + 0*8] = true;

        buffer->buffer[1 + 1*8] = true;

        buffer->buffer[1 + 2*8] = true;
        buffer->buffer[5 + 2*8] = true;
        buffer->buffer[7 + 2*8] = true;
        
        buffer->buffer[1 + 3*8] = true;
        buffer->buffer[4 + 3*8] = true;
        
        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[3 + 4*8] = true;
    }

    // Write "A" into buffer
    if (letter == 65) {
        buffer_realloc(buffer, 5);

        for (int i = 2; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1;j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
        }

        for (int i = 2; i < 8; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "B" into buffer
    if (letter == 66) {
        buffer_realloc(buffer, 5);

        for (int i = 1;i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[3 + 4*8] = true;
        buffer->buffer[5 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
    }

    // Write "C" into buffer
    if (letter == 67) {
        buffer_realloc(buffer, 5);

        for (int i = 2; i < 7; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
    }

    // Write "D" into buffer
    if (letter == 68) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }
        for (int i = 2; i < 7; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "E" into buffer
    if (letter == 69) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        buffer->buffer[1 + 4*8] = true;
        buffer->buffer[7 + 4*8] = true;
    }

    // Write "F" into buffer
    if (letter == 70) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
        }

        buffer->buffer[1 + 4*8] = true;
    }

    // Write "G" into buffer
    if (letter == 71) {
        buffer_realloc(buffer, 5);

        for (int i = 2; i < 7; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        buffer->buffer[1 + 1*8] = true;
        buffer->buffer[7 + 1*8] = true;

        for (int j = 2; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[4 + 4*8] = true;
        buffer->buffer[5 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
    }

    // Write "H" into buffer
    if (letter == 72) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[4 + j*8] = true;
        }

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "I" into buffer
    if (letter == 73) {
        buffer_realloc(buffer, 3);

        buffer->buffer[1 + 0*8] = true;
        buffer->buffer[7 + 0*8] = true;

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 1*8] = true;
        }

        buffer->buffer[1 + 2*8] = true;
        buffer->buffer[7 + 2*8] = true;
    }

    // Write "J" into buffer
    if (letter == 74) {
        buffer_realloc(buffer, 5);

        buffer->buffer[6 + 0*8] = true;

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        for (int i = 1; i < 7; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "K" into buffer
    if (letter == 75) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 3; j++) {
            buffer->buffer[4 + j*8] = true;
        }

        buffer->buffer[3 + 3*8] = true;
        buffer->buffer[5 + 3*8] = true;

        buffer->buffer[1 + 4*8] = true;
        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
        buffer->buffer[7 + 4*8] = true;
    }

    // Write "L" into buffer
    if (letter == 76) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 5; j++) {
            buffer->buffer[7 + j*8] = true;
        }
    }

    // Write "M" into buffer
    if (letter == 77) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        buffer->buffer[2 + 1*8] = true;

        buffer->buffer[3 + 2*8] = true;

        buffer->buffer[2 + 3*8] = true;

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "N" into buffer
    if (letter == 78) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        buffer->buffer[3 + 1*8] = true;

        buffer->buffer[4 + 2*8] = true;

        buffer->buffer[5 + 3*8] = true;

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "O" into buffer
    if (letter == 79) {
        buffer_realloc(buffer, 5);

        for (int i = 2; i < 7; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        for (int i = 2; i < 7; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "P" into buffer
    if (letter == 80) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
        }

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[3 + 4*8] = true;
    }

    // Write "Q" into buffer
    if (letter == 81) {
        buffer_realloc(buffer, 5);

        for (int i = 2; i < 7; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        buffer->buffer[1 + 1*8] = true;
        buffer->buffer[7 + 1*8] = true;

        buffer->buffer[1 + 2*8] = true;
        buffer->buffer[5 + 2*8] = true;
        buffer->buffer[7 + 2*8] = true;

        buffer->buffer[1 + 3*8] = true;
        buffer->buffer[6 + 3*8] = true;
        buffer->buffer[7 + 3*8] = true;
        
        for (int i = 2; i < 8; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "R" into buffer
    if (letter == 82) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
        }

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[3 + 4*8] = true;
        buffer->buffer[5 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
        buffer->buffer[7 + 4*8] = true;
    }

    // Write "S" into buffer
    if (letter == 83) {
        buffer_realloc(buffer, 5);

        buffer->buffer[2 + 0*8] = true;
        buffer->buffer[3 + 0*8] = true;
        buffer->buffer[6 + 0*8] = true;

        for (int j = 1; j < 4; j++) {
            buffer->buffer[1 + j*8] = true;
            buffer->buffer[4 + j*8] = true;
            buffer->buffer[7 + j*8] = true;
        }

        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[5 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
    }

    // Write "T" into buffer
    if (letter == 84) {
        buffer_realloc(buffer, 5);

        for (int j = 0; j < 2; j++) {
            buffer->buffer[1 + j*8] = true;
        }

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 2*8] = true;
        }

        for (int j = 3; j < 5; j++) {
            buffer->buffer[1 + j*8] = true;
        }
    }

    // Write "U" into buffer
    if (letter == 85) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 7; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        for (int j = 1; j < 4; j++) {
            buffer->buffer[7 + j*8] = true;
        }

        for (int i = 1; i < 7; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "V" into buffer
    if (letter == 86) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 6; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        buffer->buffer[6 + 1*8] = true;
        
        buffer->buffer[7 + 2*8] = true;

        buffer->buffer[6 + 3*8] = true;

        for (int i = 1; i < 6; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "W" into buffer
    if (letter == 87) {
        buffer_realloc(buffer, 5);

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 0*8] = true;
        }

        buffer->buffer[6 + 1*8] = true;

        buffer->buffer[5 + 2*8] = true;

        buffer->buffer[6 + 3*8] = true;

        for (int i = 1; i < 8; i++) {
            buffer->buffer[i + 4*8] = true;
        }
    }

    // Write "X" into buffer
    if (letter == 88) {
        buffer_realloc(buffer, 5);

        buffer->buffer[1 + 0*8] = true;
        buffer->buffer[2 + 0*8] = true;
        buffer->buffer[6 + 0*8] = true;
        buffer->buffer[7 + 0*8] = true;

        buffer->buffer[3 + 1*8] = true;
        buffer->buffer[5 + 1*8] = true;

        buffer->buffer[4 + 2*8] = true;

        buffer->buffer[3 + 3*8] = true;
        buffer->buffer[5 + 3*8] = true;

        buffer->buffer[1 + 4*8] = true;
        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[6 + 4*8] = true;
        buffer->buffer[7 + 4*8] = true;
    }

    // Write "Y" into buffer
    if (letter == 89) {
        buffer_realloc(buffer, 5);

        buffer->buffer[1 + 0*8] = true;
        buffer->buffer[2 + 0*8] = true;

        buffer->buffer[3 + 1*8] = true;

        for (int i = 4; i < 8; i++) {
            buffer->buffer[i + 2*8] = true;
        }

        buffer->buffer[3 + 3*8] = true;

        buffer->buffer[1 + 4*8] = true;
        buffer->buffer[2 + 4*8] = true;
    }

    // Write "Z" into buffer
    if (letter == 90) {
        buffer_realloc(buffer, 5);

        buffer->buffer[1 + 0*8] = true;
        buffer->buffer[6 + 0*8] = true;
        buffer->buffer[7 + 0*8] = true;

        buffer->buffer[1 + 1*8] = true;
        buffer->buffer[5 + 1*8] = true;
        buffer->buffer[7 + 1*8] = true;

        buffer->buffer[1 + 2*8] = true;
        buffer->buffer[4 + 2*8] = true;
        buffer->buffer[7 + 2*8] = true;

        buffer->buffer[1 + 3*8] = true;
        buffer->buffer[3 + 3*8] = true;
        buffer->buffer[7 + 3*8] = true;

        buffer->buffer[1 + 4*8] = true;
        buffer->buffer[2 + 4*8] = true;
        buffer->buffer[7 + 4*8] = true;
    }

    // Write "_" into buffer
    if (letter == 95) {
        buffer_realloc(buffer, 5);

        for (int j = 0; j < 5; j++) {
            buffer->buffer[7 + j*8] = true;
        }
    }

    return buffer;
}


int write_word(MD_MAX72XX* M, String w, int mod, int way, int c_min, int c_max) {
    int l = w.length();

    int c = c_max;

    if (way == 1) {
        for (int i = l - 1; i >= 0; i--) {
            struct buffer* buffer = write_letter(w[i]);

            if (mod == 0) {
                print_with_scroll(M, buffer, way, c_min, c_max);
            }

            buffer_free(buffer);
        }
        scrolling_reverse(M, c_min, c_max);
    }

    else {
        for (int i = 0; i < l; i++) {
            struct buffer* buffer = write_letter(w[i]);

            if (mod == 0) {
                print_with_scroll(M, buffer, way, c_min, c_max);
            }

            if (mod == 1 && c >= 0) {
                print_on_column(M, buffer, c);
                c = c - 1 - buffer->size;
            }

            buffer_free(buffer);
        }
    }

    char length_without_spaces = l;

    for (int i = 0; i < l; i++) {
        if (w[i] == 32) {
            length_without_spaces -= true;
        }
    }

    return length_without_spaces;
}