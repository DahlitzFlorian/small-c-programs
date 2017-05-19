/*  Sorts double-numbers w/ the selection-sort-algorithm
---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// global variables
double numbers[MAX];

// prototypes
void selection_sort( double v[], int length );


int main()
{
    int i;
    long sec;

    printf("\n\n"
            "----- Sorting %d random numbers -----"
            "\n", MAX);
    
    time(&sec);
    srand( (unsigned) sec );

    for(i = 0; i < MAX; ++i)
        numbers[i] = (double) (rand()-RAND_MAX/2) / 100;

    selection_sort(numbers, MAX);

    printf("\n\nThe sorted numbers:\n\n");

    for(i = 0; i < MAX; ++i)
    {
        if(i % 5 == 0 && i != 0)
            printf("\n");
            
        printf("%10.2f", numbers[i]);
    }
    printf("\n");

    return 0;
}


void selection_sort( double v[], int length )
{
    void swapmin( double v[], int length );

    if(length > 1)
    {
        swapmin(v, length);
        selection_sort(v+1, length-1);
    }
}


void swapmin( double v[], int length )
{
    int i, mini;
    double tmp;

    for(mini = 0, i = 1; i < length; ++i)
        if(v[i] < v[mini])
            mini = i;

        tmp = v[0], v[0] = v[mini], v[mini] = tmp;
}