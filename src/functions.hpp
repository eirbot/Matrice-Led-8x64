#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <MD_MAX72xx.h>
#include <SPI.h>

/// @brief Struct of the buffer that stores the datas
struct buffer {
    bool* buffer;
    int size;
};

/**
 * @brief This fonction tests all dots of the displat starting from line 0 and column 0
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which the dots will be print out
 */
void test_all_points(MD_MAX72XX* M);


/**
 * @brief Function that applies one in which one iteration of right to left scrolling on an MD_MAX72XX display
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which the scrooling is applied on
 * @param c_max 
 */
void scrolling(MD_MAX72XX* M, int c_min, int c_max, int DELAY = 70);


/**
 * @brief Function that applies one in which one iteration of right to left scrolling on a MD_MAX72XX display
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which the reverse scrooling is applied
 * @param c_min 
 * @param c_max 
 */
void scrolling_reverse(MD_MAX72XX* M, int c_min, int c_max);


/**
 * @brief Function that makes a pattern scrool to his end
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which the reverse scrooling is applied
 * @param way in which way the pattern his scrool (0 : right to left, 1 : left to right)
 * @param c_min 
 * @param c_max 
 */
void scrolling_to_end(MD_MAX72XX* M, int way, int c_min, int c_max);


/**
 * @brief Function that does one iteration of inversion of pixels on a  MD_MAX72XX display
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which the inversion is applied
 * @param l_min the minimun line in which the inversion will be applied
 * @param l_max the maximun line in which the inversion will be applied
 * @param c_min the minimun column in which the inversion will be applied
 * @param c_max the maximun column in which the inversion will be applied
 */
void inversion(MD_MAX72XX* M, int l_min, int l_max, int c_min, int c_max);


/**
 * @brief Function that makes the display flicker one time
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display that will flicker
 * @param c_min the minimun column in which the flicker will occur
 * @param c_max the maximun column in which the flicker will occur
 */
void flicker(MD_MAX72XX* M, int c_min, int c_max, int l_min, int l_max);


/**
 * @brief Function that prints a buffer on a display in scrooling mod
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which the buffer will be print out
 * @param buf a buffer that stores the datas that will be print out
 * @param way the way a the scroll
 * @param c_min the minimum column of the scroll
 * @param c_max the maximum column of the scroll
 */
void print_with_scroll(MD_MAX72XX* M, struct buffer* buffer, int way, int c_min, int c_max);


/**
 * @brief Function that prints a buffer on a display in fixed mod
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which the buffer will be print out
 * @param buf a buffer that stores the datas that will be print out
 * @param c the column from which the display of datas will begin
 */
void print_on_column(MD_MAX72XX* M, struct buffer* buffer, int c);


/**
 * @brief Function that clears the display
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display that will be cleared
 * @param c_min the minimum column from which the erasure will begin
 * @param c_max the maximum column from which the erasure will end
 */
void clear_matrix(MD_MAX72XX* M, int c_min, int c_max);


/**
 * @brief Function that allocates dynamically a buffer of size 8*width*sizeof(int) + 1, this correspond to the datas of a drawing of a size of width column
 * and his size
 * 
 * @param width the maximun width that can be use to draw (typically the number of column of the drawing)
 * @return int* the buffer
 */
struct buffer* buffer_alloc(int width);


/**
 * @brief Function that changes the size of the dynamically allocated buffer to 8*width*sizeof(int) + 1
 * 
 * @param buffer the buffer which will be reallocated
 * @param width the maximun width that can be use to draw (typically the number of column of the drawing)
 */
void buffer_realloc(struct buffer* buffer, int width);


/**
 * @brief Function that entirely sets a buffer to 0
 * 
 * @param buf the buffer that will be set to 0
 * @param width the size of the buffer that will be stores in buf[0]
 */
void buffer_init(struct buffer* buffer, int width);


/**
 * @brief Function that frees the memory associated with the buffer
 * 
 * @param buf the buffer that will be freed
 */
void buffer_free(struct buffer* buffer);


/**
 * @brief Function that displays random stuffs on the display based on functions implemented in caracters.cpp and pixel_arts.cpp
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which this will be displayed
 */
void random_stuffs(MD_MAX72XX* M);


/**
 * @brief Function that displays randomly the name of one of our collaborators
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which this will be displayed
*/
void parts(MD_MAX72XX* M);


/**
 * @brief Function that displays random stuffs partners friendly on the display based on functions implemented in caracters.cpp and pixel_arts.cpp
 * 
 * @param M a MD_MAX72XX* that referes to the MD_MAX72XX display in which this will be displayed
 */
void random_stuffs_part_friendly(MD_MAX72XX* M);


void init_controller();


int* read_controller();


void free_boutons(int* boutons);

#endif