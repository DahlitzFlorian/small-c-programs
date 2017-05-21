/*  Unknown number of numbers can be typed in and the
    program calculates the arithmetic mean, variance
    and the standard derivation.
---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>     // calloc(), realloc(), free()
#include <math.h>       // sqrt(), atof()

#define SIZE    100

// global variables
char input[21];
char header[] = "\n\n"
                "----- Arithmetic Mean - Variance - Standard Derivation -----"
                "\n\n";

int main()
{
    double *numbers, *numbers_old, sum, mean, variance;
    int i, count = 0, upper = SIZE;

    printf(header);
    printf("Type in the numbers: "
            "(STOP with <Return> in a new line): \n\n");
    
    numbers = (double *) calloc(upper, sizeof(double));

    while(numbers != NULL)
    {
        while(count < upper)
        {
            fflush(stdin);
            printf("%5d. Number --> ", count+1);
            fgets(input, 21, stdin);

            if(input[0] == '\n')
                break;
            
            numbers[count++] = atof(input);
        }

        if(count < upper)
            break;
        
        numbers_old = numbers;
        upper += SIZE;
        numbers = (double *) realloc(numbers_old, upper * sizeof(double));
    }

    if(numbers == NULL)
    {
        printf("\nThere is not enough RAM!\n");
        if(count == 0)
            exit(1);
        else
        {
            numbers = numbers_old;
            printf("Finished input of data.\n");
        }
    }

    if(count == 0)
        printf("No numbers were typed in.\n"),
        exit(0);
    else
        printf("\n\n%d numbers were typed in.\n\n", count);

    /*  ---     Calculation     --- */
    for(sum = i = 0; i < count; ++i)
        sum += numbers[i];
    mean = sum / count;

    for(sum = i = 0; i < count; ++i)
        sum += (numbers[i] - mean) * (numbers[i] - mean);
    variance = sum / count;

    free(numbers);

    printf("\n> Mean:                %16.5f", mean);
    printf("\n\n> Variance:            %16.5f", variance);
    printf("\n\n> Standard Derivation: %16.5f", sqrt(variance));
    printf("\n\n");

    return 0;
}