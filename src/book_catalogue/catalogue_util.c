/*  Includes helper functions for book catalogue
---------------------------------------------------------*/
#include <string.h>
#include <ctype.h>
#include "catalogue.h"

void strtoup( char * );

static char msg[] = "Which entries based on the authors " \
                    "name should be displayed?\n\n"
                    "Type in the beginning of the name "
                    "(only <Return> = ALL) --> ";

void show(void)
{
    int show_entry( BOOK *cat, int len, char *name );
    char name[30];
    int count;

    HEADER;
    LOCATE(8, 1);
    printf(msg);

    if(input(name, 29, ESC, CR) == ESC)
        return;

    strtoup(name);

    count = show_entry(catalogue, cat_length, name);

    if(count == 0)
        printf("\n\nNo entries found.\n");
    else
        printf("\n\n%d entries found.\n", count);
    
    NEXT;
}

int add(void)
{
    char buf[50];
    static char prompt[] =  "  BOOK NUMBER  -->\n\n"
                            "  AUTHOR       -->\n\n"
                            "  TITLE        -->\n\n"
                            "  YEAR         -->\n\n"
                            "  PUBLISHER    -->";
    
    HEADER;
    LOCATE(6, 1);

    if(cat_length == CAT_SIZE)
    {
        printf("The catalogue reached the maximum of entries.\n");
        NEXT;

        return 0;
    }

    printf("Please type in new book data.\n"
            "(Esc = cancel.)");
    
    LOCATE(12, 1);
    printf(prompt);
    LOCATE(12, 22);

    if(input(buf, 8, ESC, CR) == ESC)
        return 0;
    
    strtoup(buf);
    strcpy((catalogue+cat_length)->author, buf);

    LOCATE(16, 22);

    if(input(buf, 49, ESC, CR) == ESC)
        return 0;
    strcpy((catalogue+cat_length)->title, buf);

    LOCATE(18, 22);

    if(input(buf, 4, ESC, CR) == ESC)
        return 0;
    (catalogue+cat_length)->year = atoi(buf);

    LOCATE(20, 22);

    if(input(buf, 19, ESC, CR) == ESC)
        return 0;
    strtoup(buf);
    strcpy((catalogue+cat_length)->publisher, buf);

    return 1;
}

void sort(void)
{
    int book_cmp( const void *, const void * );

    HEADER;
    LOCATE(10, 1);
    printf("Start sorting ...");

    qsort(catalogue, cat_length, sizeof(BOOK), book_cmp);

    printf("\n\nThe catalogue is sorted by the authors names.");
    NEXT;
}

int book_cmp(const void *bp1, const void *bp2)
{
    return strcmp(((BOOK *)bp1)->author, ((BOOK *)bp2)->author);
}

int show_entry (BOOK *cat, int len, char *id)
{
    int len_id, count = 0;

    len_id = strlen(id);

    HEADER;
    LOCATE(4, 1);

    for( ; len > 0; --len, cat++)
    {
        if(strncmp(cat->author, id, len_id) == 0)
        {
            printf("\n\tBook number:    %ld\n", cat->book_nr);
            printf(  "\tAuthor:         %s\n", cat->author);
            printf(  "\tTitle:          %s\n", cat->title);
            printf(  "\tYear:           %hd\n", cat->year);
            printf(  "\tPublisher:          %s\n", cat->publisher);

            ++count;
        }
    }

    return count;
}

void strtoup(char *str)
{
    char *s = str;

    while(*s != '\0' && (*s == ' ' || *s == '\t'))
        ++s;
    
    while((*str = toupper(*s)) != '\0')
        ++str, ++s;
}

int input(char *buffer, int max, ...)
{
    int c, breakc;
    int nc;
    va_list argp;

    while(1)
    {
        *buffer = '\0';
        if((c = getch()) == 0)
            c = getch() + 256;

        va_start(argp, max);
        do
        {
            if(c == (breakc = va_arg(argp, int)))
                return breakc;
        } while(breakc != '\r');

        va_end(argp);

        if(c == '\b' && nc > 0)
        {
            --nc, --buffer;
            putch(c);
            putch(' ');
            putch(c);
        }
        else if(c >= 32 && c <= 255 && nc < max)
        {
            ++nc, *buffer++ = c;
            putch(c);
        }
        else if(nc == max)
            putch('\a');
    }
}