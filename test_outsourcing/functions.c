#include "functions.h"


void draw_line(unsigned int i)
{
    for(unsigned int j = 0; j < i; ++j)
        printf("-");
    
    printf("\n");

    return;
}


void message()
{
    printf("This is a message.\n");
}