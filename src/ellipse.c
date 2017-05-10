/*  Displays an ellipse for coordinates x, y w/
    x = A*cos(t) ; y = B*sin(t)
---------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include "console.h"

#define CLS         cls()
#define LOCATE(r,c) setCursor(r,c)
#define DOT(x,y)    LOCATE(y,x), putchar('*')

#define PI          3.1416
#define Mx          40
#define My          12
#define A           25
#define B           20


int main()
{
    int x, y;
    double t, scale = 0.4;

    CLS;
    for(t = 0.0; t < PI/2; t += 0.03)
    {
        x = (int) (A * cos(t) + 0.5);
        y = (int) (scale * B * sin(t) + 0.5);

        DOT(x+Mx, y+My);
        DOT(x+Mx, -y+My);
        DOT(-x+Mx, y+My);
        DOT(-x+Mx, -y+My);
    }

    LOCATE(24, 0);

    return 0;
}