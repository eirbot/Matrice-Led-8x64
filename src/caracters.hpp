#ifndef CARACTERS_HPP // include guard
#define CARACTERS_HPP

#include <MD_MAX72xx.h>
#include <SPI.h>



/**
 * @brief Fonction that returns an int* buffer in which is stored the drawing of the ASCII caracters enter in parameter
 *
 * @param letter the ASCII code associated to a caracter
 * @return buffer the buffer associated with the ASCII code entered in parameter
 */
struct buffer* write_letter(char letter);


/**
 * @brief Fonction that draws on a MD_MAX72XX display a String entered in parameters in the specified mod
 *
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which the String will b print out
 * @param w the String that will be printed out
 * @param mod the mod of display, if 0 the String will scrool on the display, with 1 it will be a fixed print starting on c_max column
 * @param way choose in which way the String will scroll, 0 from c_min to c_max (right to left), 1 from c_max to c_min (left to right)
 * @param c_min the minimum column on which the String will be displayed
 * @param c_max the maximum column on which the String will be displayed
 * 
 * @return The size of the word in letters
 */
int write_word (MD_MAX72XX* M, String w, int mod, int way, int c_min, int c_max);


#endif