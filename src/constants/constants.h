/**
* @file constants.h
* @brief Contains the various constants used throughout the program
* @author Matthew C. Lindeman
* @date Novermber 14, 2021
* @bug None currently.
* @todo N/a
*/
#ifndef CONS_H
#define CONS_H

#define PATH_TO_QUOTES "/home/knd/.rice_terminal/bash/quotes/quotes.txt"
#define PATH_TO_ART "/home/knd/.rice_terminal/bash/ascii_art/weed_leaves.txt"

#define PALETTE_NO_ZERO "\033[0;30m" // dark blue for developer
#define PALETTE_NO_ONE "\033[0;31m" // pink for developer
#define PALETTE_NO_TWO "\033[0;32m" // green for developer
#define PALETTE_NO_THREE "\033[0;33m" // red for developer
#define PALETTE_NO_FOUR "\033[0;34m" // light blue for developer
#define PALETTE_NO_FIVE "\033[0;35m" // purple for developer
#define PALETTE_NO_SIX "\033[0;36m" // light purple for developer
#define PALETTE_NO_SEVEN "\033[0;37m" // white for developer
#define NC "\033[0m"

#define MAX_QUOTE 1024
#define LINE_SIZE 80
#define QUOTE_LINE_SIZE 78
#define ART_BUFFER 3

#endif
