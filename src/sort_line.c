/*  Sorts text-lines lexicographically
    In this example MAXLINES equals 1000 but it can be
    changed to whatever number e.g. 2541.
---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES    1000
#define MAX         512

// prototypes
void error_exit( int error_nr );
char *getline( void );

// global variables
char *line[MAXLINES];


int main()
{
    int i, j, mini, count = 0;
    char *help;

    while(count < MAXLINES && (line[count] = getline()) != NULL)
        ++count;

    if(count == MAXLINES)
        error_exit(1);
    else if(!feof(stdin))
        error_exit(2);
    else if(count == 0)
        error_exit(3);
    
    for(i = 0; i < count - 1; ++i)
    {
        mini = i;
        for(j = i + 1; j < count; ++j)
            if(strcmp(line[i], line[mini]) < 0)
                mini = j;
        
        help = line[i];
        line[i] = line[mini];
        line[mini] = help;
    }

    puts("\n\nThe sorted lines:\n\n");

    for(i = 0; i < count; ++i)
        puts(line[i]);

    return 0;
}


void error_exit(int error_nr)
{
    static char *error_msg[] = {
        "Invalid error number.\n",
        "Error 1: To much data.\n",
        "Error 2: Not enough memory.\n",
        "Error 3: No data.\n"
    };

    if(error_nr < 1 || error_nr > 3)
        error_nr = 0;
    
    fputs(error_msg[error_nr], stderr);
    exit(error_nr);
}


char *getline(void)
{
    char *line, *s;
    int c;

    if((line = s = (char *)malloc(MAX)) != NULL)
    {
        while(s < line + MAX - 1 && (c = getchar()) != '\n' && c != EOF)
            *s++ = c;
        *s = '\0';

        if(c == EOF && s == line)
            free(line), line = NULL;
        else
            line = (char *)realloc(line, s - line + 1);
    }

    return line;
}