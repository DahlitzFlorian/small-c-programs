/*  Searches a string for a certain char and returns the
    index of the first occurence
---------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 130


int index(char[], int);


int main()
{
    char str[MAX_TEXT_LENGTH], ch;
    int ind;

    printf("Enter a string: ");
    gets(str);
    printf("Enter a char: ");
    scanf("%c", &ch);

    ind = index(str, ch);
    printf("The index is: %d", ind);

    return 0;
}


int index(char str[], int ch)
{
    int i, index = -1;

    for(i = 0; i < strlen(str); ++i)
    {
        if(str[i] == ch)
        {
            index = i;
            i = strlen(str);
        }
    }

    return index;
}