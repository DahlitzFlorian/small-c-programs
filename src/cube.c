/*  Represents a cube
---------------------------------------------------------*/
#include <stdio.h>
#include <conio.h>
#include "console.h"

#define ESC         27
#define CLS         cls()
#define LOCATE(z,s) setCursor(z,s)


int main()
{
    unsigned c, count = 0;
    CLS;
    LOCATE(1, 25);
    printf("**** CUBE ****");

    LOCATE(3, 1);
    printf("This program gives you a number between 1and 6.\n"
            "It\'s counting until you pressed the space bar.\n"
            "End the program w/ ESC.\n\n"
            "Results:\n\n");
    fflush(stdout);

    do
    {
        while(!kbhit())
            ++count;
        
        if((c = getch()) == ' ')
            printf("%5u", count % 6 + 1);
    } while(c != ESC);
    CLS;

    return 0;
}