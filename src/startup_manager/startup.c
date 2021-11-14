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
#include"../constants/constants.h"

void start(void) {
    art_t * art = read_file(PATH_TO_ART);
    print_random_quote(PATH_TO_QUOTES);
    print_art(art);
    free_art(art);
}
