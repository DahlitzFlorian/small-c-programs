/*  Including a function to calculate the circumference
    and the area of a circle
---------------------------------------------------------*/
#include <stdio.h>

#define PI          3.1415926536
#define LOW_LIMIT   0.5
#define LIMIT       10.0
#define STEP        0.5

// prototypes
void circle( double radius, double *area, double *circumference );


int main()
{
    double r, a, c;
    
    printf("\n\n"
            "----- Circle Calculation -----"
            "\n\n");
    printf("%-4c | %-6s | %-s\n", 'n', "Area", "Circumference");
    printf("-----------------------------\n");

    for(r = LOW_LIMIT; r <= LIMIT; r += STEP)
    {
        circle(r, &a, &c);
        printf("%-4.1f | %6.2f | %5.2f\n", r, a, c);
    }

    return 0;
}


void circle( double radius, double *area, double *circumference )
{
    *area = PI * radius * radius;
    *circumference = 2 * PI * radius;
}