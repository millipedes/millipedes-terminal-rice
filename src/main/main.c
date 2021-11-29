/**
* @file main.c
* @brief This file calls the manager.
* @author Matthew C. Lindeman
* @date Novermber 14, 2021
* @bug None currently.
* @todo None currently
*/
#include<stdio.h>
#include"../startup_manager/include/startup.h"

int main(int argc, char * argv[]) {
	printf("%s, %s, %d\n", argv[0], argv[1], argc);
    start(argc, argv);
    return 0;
}
