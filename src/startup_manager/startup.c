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
    art_t * art = read_file("config/ascii_art/picture_test.txt");
    print_random_quote("config/quotes/quotes.txt");
    print_art(art);
    free_art(art);
}
