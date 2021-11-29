/**
* @file startup.c
* @brief
* @author Matthew C. Lindeman
* @date Novermber 14, 2021
* @bug None currently.
* @todo N/a
*/
#include<stdio.h>
#include<stdlib.h>
#include"include/startup.h"
#include"../ascii_art/include/ascii_art.h"
#include"../quotes/include/quotes.h"

void start(int file_no, char ** file_names) {
	if(file_no != 3) {
		fprintf(stderr, "[ERROR]: Not enough files provided to rice-terminal.  Expected two files, found %d\n[USE]: $ ./executable path_to_art path_to_quotes\n", file_no);
		exit(1);
	}
    art_t * art = read_file(file_names[1]);
    print_random_quote(file_names[2]);
    print_art(art);
    free_art(art);
}
