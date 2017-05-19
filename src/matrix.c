/*  Calculate the sum of a two-dimensional matrix
---------------------------------------------------------*/
#include <stdio.h>


// global variables
int my_matrix[3][5] = { { 25, 34, 26, 12, 8 },
                        { 19, 27, 24, 11, 4 },
                        { 6, 15, 35, 36, 18 } };

int row_sum[3], column_sum[5];

// prototypes
int sum_matrix( int matrix[][5], int rsum[], int csum[] );


int main()
{
    int i, j, total;

    printf("\nThis is a test of the sum_matrix() function.\n\n");
    total = sum_matrix(my_matrix, row_sum, column_sum);

    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 5; ++j)
            printf("%6d", my_matrix[i][j]);
        printf(" | %6d\n", row_sum[i]);
    }

    printf("---------------------------------------\n");

    for(j = 0; j < 5; ++j)
        printf("%6d", column_sum[j]);
    printf(" | %6d\n", total);

    return 0;
}


int sum_matrix( int matrix[][5], int rsum[], int csum[] )
{
    int r, c;

    for(r = 0; r < 3; ++r)
    {
        rsum[r] = 0;
        for(c = 0; c < 5; ++c)
            rsum[r] += matrix[r][c];
    }

    for(c = 0; c < 5; ++c)
    {
        csum[c] = 0;
        for(r = 0; r < 3; ++r)
            csum[c] += matrix[r][c];
    }

    return rsum[0] + rsum[1] + rsum[2];
}