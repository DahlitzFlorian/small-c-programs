/*  filter to number the rows of a text-file

    USAGE: go to the directory build/ and type in
    the following command to print it in console:
    rows.exe < example.txt
    OR to write it into another file type in:
    rows.exe < example.txt > result.txt
---------------------------------------------------------*/
#include <stdio.h>


int main()
{
    int c;
    int new_line = 1;
    int number = 0;

    while((c = getchar()) != EOF)
    {
        if(new_line == 1)
        {
            printf("%-5d ", ++number);
            new_line = 0;
        }

        putchar(c);

        if(c == '\n')
            new_line = 1;
    }

    return 0;
}