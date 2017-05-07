/*  Replaces german umlauts ä, ö, ü, ß
---------------------------------------------------------*/
#include <stdio.h>


int main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        switch(c)
        {
            case 0x84:
                putchar('a');
                putchar('e');
                break;
            case 0x94:
                putchar('o');
                putchar('e');
                break;
            case 0x81:
                putchar('u');
                putchar('e');
                break;
            case 0xE1:
                putchar('s');
                putchar('s');
                break;
            default:
                putchar(c);
        }
    }

    return 0;
}