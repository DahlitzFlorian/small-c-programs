/*  Displaying the first 20 fibonacci numbers and it's
    fibonacci quotient
---------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

#define LIMIT   20

long fib[LIMIT+1] = {0, 1};
char header[] = "\n\n"
                "Index Fibonacci-Number Fibonacci-Quotient Variance"
                "\n\n";


int main()
{
    int i;
    double q, lim;

    for(i = 1; i < LIMIT; ++i)
        fib[i+1] = fib[i] + fib[i-1];
    
    lim = (1.0 + sqrt(5.0)) / 2.0;

    printf(header);
    printf("%5d %10ld\n", 0, fib[0]);
    printf("%5d %10ld\n", 1, fib[1]);

    for(i = 2; i <= LIMIT; ++i)
    {
        q = (double) fib[i] / (double) fib[i-1];
        printf("%5d %10ld %22.14f %13.3e\n", i, fib[i], q, lim-q);
    }

    return 0;
}