/*  Drawing the sine curve
    HINT: Bad try 'cause of multi-character
---------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include "console.h"

#define PI          3.141592653
#define LIMIT       (2 + PI)
#define LOWER_LIMIT 0
#define PNT         64
#define STEP        ((LIMIT - LOWER_LIMIT) / PNT)
#define RZ          15          // row of zero
#define CZ          10          // column of zero
#define CLS         cls()
#define LOCATE(r,c) setCursor(r,c)


int main()
{
    int row, column, begin, end;

    CLS;
    LOCATE(2, 25);
    printf("**** The Sine Curve ****");

    /*  ---     axis of abscissas       --- */

    // x-axis
    LOCATE(RZ, 1);
    for(column = 1; column < 78; ++column)
        (column - CZ) % 8 ? putchar('|') : putchar('-');
    putchar('\020');
    LOCATE(RZ - 1, CZ + 64);
    printf("2 PI    x");

    // y-axis
    for(row = 6; row < 25; ++row)
        LOCATE(row, CZ), putchar('-');
    LOCATE(5, CZ);
    printf("\036 sin(x)");

    LOCATE(CZ - 8, CZ + 1), printf(" 1");
    LOCATE(CZ + 8, CZ + 1), printf(" -1");

    /*  ---     draw sine curve         --- */

    begin = CZ;
    end = begin + PNT;

    for(column = begin; column <= end; ++column)
    {
        double y = sin((column - CZ) * STEP);
        row = (int) (RZ - 8.0 * y + 0.5);

        LOCATE(row, column);
        putchar('*');
    }

    LOCATE(25, 1);

    return 0;
}