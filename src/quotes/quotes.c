/**
* @file quotes.c
* @brief Functions that psuedo-randomly take a quote from the provided quotes
* file and prints/centers it
* @author Matthew C. Lindeman
* @date Novermber 14, 2021
* @bug None currently.
* @todo N/a
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"include/quotes.h"
#include"../constants/constants.h"

/**
 * prints the top/bottom bar above the quotes centers (quote smaller than
 * LINE_SIZE) and only prints to size (quotes smaller than LINE_SIZE).
 * @param width         the size of the bar
 * @param space_buffer  the amount of space to buffer the bar with
 */
void print_heading(int width, int space_buffer) {
    for(int i = 0; i < space_buffer - 1; i++) {
        printf(" ");
    }
    for(int i = 0; i < width + 1; i++) {
        printf("-");
    }
    printf("\n");
}

/**
 * A way to get the number of quotes on another stack frame (i.e. can still
 * use fp in functions called from)
 * @param  filepath          the filepath of the quotes file
 * @return                   the number of lines in the quote file
 */
int get_quote_no(char * filepath) {
    FILE * fp = fopen(filepath, "r");
    char buf[MAX_QUOTE];
    int no_of_lines = 0;
    while(fgets(buf, MAX_QUOTE, fp)) {
        no_of_lines++;
    }
    fclose(fp);
    return no_of_lines;
}

/**
 * A function that takes in a file path and prints a quote pseudo-randomly
 * @param filepath  the file containing the quotes
 */
void print_random_quote(char * filepath) {
    srand(time(NULL));
    int quote_no = get_quote_no(filepath);
    FILE * fp = fopen(filepath, "r");
    int random_no = rand() % (quote_no + 1);
    int i = 0;
    char buf[MAX_QUOTE];

    while(i <= random_no) {
        fgets(buf, MAX_QUOTE, fp);
        i++;
    }

    if(strnlen(buf, MAX_QUOTE) >= LINE_SIZE) {
        print_heading(LINE_SIZE, 0);
        for(int i = 0; i < strnlen(buf, MAX_QUOTE); i++) {
            printf("%c", buf[i]);
            if(i % LINE_SIZE == 0 && i != 0) {
                printf("\n");
                if(buf[i + 1] == ' ') {
                    i++;
                }
            }
        }
        print_heading(LINE_SIZE, 0);
    } else {
        int quote_size = strnlen(buf, MAX_QUOTE);
        int white_space = 80 - quote_size;
        print_heading(strnlen(buf, MAX_QUOTE), white_space/2);
        for(int i = 0; i < white_space/2; i++) {
            printf(" ");
        }
        printf("%s", buf);
        print_heading(strnlen(buf, MAX_QUOTE), white_space/2);
    }
    fclose(fp);
}
