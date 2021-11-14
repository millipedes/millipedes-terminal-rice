/**
* @file quotes.h
* @brief Function definitions of those defined in quotes.c
* @author Matthew C. Lindeman
* @date Novermber 14, 2021
* @bug None currently.
* @todo N/a
*/
#ifndef QUOTES_H
#define QUOTES_H

void print_heading(int width, int space_buffer);
int get_quote_no(char * filepath);
void print_random_quote(char * filepath);

#endif
