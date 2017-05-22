/*  Compares the Selection-Sort-Algorithm and the
    Quick-Sort-Algorithm
---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// prototypes
int intcmp( const void *a, const void *b );
void selection_sort( int *v, int length );


int main(int argc, char **argv)
{
    int c, i, size, *numbers1, *numbers2;
    time_t sec;
    long begin, end;

    /*  ---     LAYOUT      --- */

    printf("\n\n"
            "----- Comparison of sort-algorithms -----"
            "\n\n");
    
    if(argc != 2)
    {
        printf("Example of correct call: sort_comparison 400\n");
        exit(1);
    }

    /*  ---     CREATE RANDOM NUMBERS   --- */

    size = atoi(argv[1]);
    numbers1 = (int *)malloc(size * sizeof(int));
    numbers2 = (int *)malloc(size * sizeof(int));

    if(numbers1 == NULL ||numbers2 == NULL)
        fprintf(stderr, "Not enough memory available!\n"),
        exit(1);

    time(&sec);
    srand((unsigned)sec);
    
    for(i = 0; i < size; ++i)
        numbers1[i] = numbers2[2] = rand();
    printf("Creates %d random numbers.\n\n", size);

    /*  ---     SORTING     --- */

    printf("Start sorting with Quick-Sort ...\n");
    time(&begin);
    qsort(numbers1, size, sizeof(int), intcmp);
    time(&end);
    printf("Needed time: %ld seconds\n\n", end - begin);

    printf("Please wait while sorting with Selection-Sort ...\n");
    time(&begin);
    selection_sort(numbers2, size);
    time(&end);
    printf("Needed time: %ld seconds\n\n", end - begin);

    /*  ---     PRINTING NUMBERS    --- */

    fflush(stdin);
    printf("Do you want to print the numbers? (y/n) --> ");
    if((c = getchar()) == 'y')
    {
        for(i = 0; i < size; ++i)
        {
            if(((i + 1) % 4) == 0)
                printf("%8d\n", numbers1[i]);
            else
                printf("%8d", numbers1[i]);
        }
    }

    return 0;
}


int intcmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}


void selection_sort(int *v, int length)
{
    void swapmin( int *v, int length );

    if(length > 1)
    {
        swapmin(v, length);
        selection_sort(v+1, length-1);
    }
}


void swapmin(int *v, int length)
{
    int i, mini;
    int tmp;

    for(mini = 0, i = 1; i < length; ++i)
        if(v[i] < v[mini])
            mini = i;

        tmp = v[0], v[0] = v[mini], v[mini] = tmp;
}