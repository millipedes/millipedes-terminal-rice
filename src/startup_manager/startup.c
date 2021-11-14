/**
* @file startup.c
* @brief
* @author Matthew C. Lindeman
* @date Novermber 14, 2021
* @bug None currently.
* @todo N/a
*/
#include"include/startup.h"
#include"../ascii_art/include/ascii_art.h"
#include"../quotes/include/quotes.h"

void start(void) {
    art_t * art = read_file("/home/knd/.rice_terminal/src/ascii_art/include/picture_test.txt");
    print_random_quote("/home/knd/.rice_terminal/src/quotes/include/quotes.txt");
    print_art(art);
    free_art(art);
}
