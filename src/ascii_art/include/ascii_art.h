/**
* @file ascii_art.h
* @brief Function definitions of those defined in ascii_art.c
* @author Matthew C. Lindeman
* @date Novermber 14, 2021
* @bug None currently.
* @todo N/a
*/
#ifndef AAR_H
#define AAR_H

typedef struct ART_T {
    char ** art_lines;
    int art_height;
    int art_width;
    // int palette_no;
} art_t;

art_t * init_art(void);
art_t * read_file(char * filename);
char * fill_buffer(char * buf, int fill, char filler);
void print_art(art_t * art);
void print_color(int color);
void print_eighty(void);
void free_art(art_t * art);

#endif
