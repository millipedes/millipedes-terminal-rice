/**
* @file ascii_art.c
* @brief This functions in this file handle the aquisition and processing of
* the ascii art
* @author Matthew C. Lindeman
* @date Novermber 14, 2021
* @bug None currently.
* @todo Make smart coloring system
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"include/ascii_art.h"
#include"../constants/constants.h"

/**
 * Initializes the srt structure
 */
art_t * init_art(void) {
    art_t * art;
    art = calloc(1, sizeof(struct ART_T));
    art->art_lines = NULL;
    art->art_height = 0;
    art->art_width = 0;
    return art;
}

/**
 * Takes in a file containing ascii art and returns an art struct with
 * appropriate values.
 * @param  filename        The name of the file with the art
 * @return                 The art structure
 */
art_t * read_file(char * filename) {
    char buf[LINE_SIZE];
    /*The character buffer used to store input from file*/
    FILE * fp = fopen(filename, "r");
    /*The file pointer used to read the art*/
    int max_lines = 4;
    /*The default smallest size of a piece of artwork*/
    art_t * art = init_art();
    /*The structure used to store the art*/

    art->art_lines = calloc(max_lines, sizeof(char *));;

    /** This while loop reads the file and doubles the size of the art_lines
     * if needed.
     */
    while(fgets(buf, LINE_SIZE, fp)) {
        if(max_lines == art->art_height){
            art->art_lines = realloc(art->art_lines, 2 * max_lines * sizeof(char *));
            if(!art->art_lines){
                fprintf(stderr, "[ERROR]: No memory available for realloc\n");
                exit(1);
            }
            max_lines *= 2;
        }
        int strl = strnlen(buf, LINE_SIZE);
        art->art_lines[art->art_height] = malloc(strl);
        buf[strl - 1] = '\0';
        strncpy(art->art_lines[art->art_height], buf, strl);
        art->art_height++;
        if(art->art_width < strnlen(buf, LINE_SIZE)) {
            art->art_width = (int)(strnlen(buf, LINE_SIZE) + 1);
        }
    }
    fclose(fp);
    return art;
}

/**
 * This function prints the art struct given to it as many times as it can fit
 * into LINE_SIZE
 * @param art  the art to be printed
 */
void print_art(art_t * art) {
    int fit_width_coef = 80 / art->art_width;
    /*i.e. how many times can the art fit in LINE_SIZE*/

    for(int i = 0; i < art->art_height; i++) {
        for(int s = 0; s < (40 - ((fit_width_coef*art->art_width)/2) - (fit_width_coef*ART_BUFFER/2) + 1); s++) {
            printf(" ");
        }
        for(int j = 0; j < fit_width_coef; j++) {
            print_color((j % 8) + 2);
            printf("%s", art->art_lines[i]);
            for(int k = 0; k < (art->art_width - strnlen(art->art_lines[i], LINE_SIZE) + ART_BUFFER); k++) {
                printf(" ");
            }
        }
        printf("\n");
    }
    print_color(-1);
}

/**
 * A less messy way of changing terminal colors based off palette_no
 * @param color the color palette entry that the user wishes to apply
 */
void print_color(int color) {
    switch(color) {
        case 0:
            printf(PALETTE_NO_ZERO);
            break;
        case 1:
            printf(PALETTE_NO_ONE);
            break;
        case 2:
            printf(PALETTE_NO_TWO);
            break;
        case 3:
            printf(PALETTE_NO_THREE);
            break;
        case 4:
            printf(PALETTE_NO_FOUR);
            break;
        case 5:
            printf(PALETTE_NO_FIVE);
            break;
        case 6:
            printf(PALETTE_NO_SIX);
            break;
        case 7:
            printf(PALETTE_NO_SEVEN);
            break;
        default:
            printf(NC);
            break;
    }
}

/**
 * A debugging tool used to just print 80 chars to screen
 */
void print_eighty(void) {
    for(int i = 0; i < 80; i++) {
        printf("-");
    }
    printf("\n");
}

/**
 * Frees an art struct (valgrind says no leaks possible so it works i.g.)
 * @param art - the art struct to be freed
 */
void free_art(art_t * art) {
    for(int i = 0; i < art->art_height; i++) {
        free(art->art_lines[i]);
    }
    free(art->art_lines);
    free(art);
}
