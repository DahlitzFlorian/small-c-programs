/*  Header-file of the program catalogue.c
---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdarg.h>
#include "../console.h"

#define CLS         cls();
#define LOCATE(r,c) setCursor(r,c);

#define HEADER      CLS; LOCATE(1, 20); \
                    printf("* * * BOOK-CATALOGUE * * *");

#define NEXT        LOCATE(25, 20); \
                    printf("--- Go on with pushing any key ---"); \
                    fflush(stdout); getch();

#define CR          13
#define ESC         27

#define CAT_SIZE    200
#define SHOW        '1'
#define ADD         '2'
#define SORT        '3'

// structures
struct book {
    long book_nr;
    char author[30];
    char title[50];
    short year;
    char publisher[20];
};

// typedef of structure book
typedef struct book BOOK;

// prototypes
extern int menu( void );
extern void show( void );
extern int add( void );
extern void sort( void );
extern int input( char *buffer, int max, ... );

// global variables
extern BOOK catalogue[];
extern int cat_length;