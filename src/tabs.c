/*  Replaces tabs with whitespaces
---------------------------------------------------------*/
#include <stdio.h>

#define TAB_SP  4


int main()
{
    int c, column = 0;

    while((c = getchar()) != EOF)
    {
        switch(c)
        {
            case '\n':
                putchar(c);
                column = 0;
                break;
            case '\t':
                do
                    putchar(' ');
                while(++column % TAB_SP == 0);
                break;
            default:
                putchar(c);
                ++column;
        }

        return 0;
    }
}