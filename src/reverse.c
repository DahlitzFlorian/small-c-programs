/*  Prints a given string reverse
---------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define LIMIT   81


void reverse(char str[], char reverse_str[]);


int main()
{
    char word[LIMIT], re_word[LIMIT];

    printf("\nType in a word: ");
    scanf("%80s", word);

    reverse(word, re_word);
    printf("The reverse string is: %s", re_word);

    return 0;
}


void reverse(char str[], char reverse_str[])
{
    int i, j;

    for(i = strlen(str)-1, j = 0; i >= 0; --i, j++)
        reverse_str[j] = str[i];
    reverse_str[j] = '\0';
}