/*  Copying one file to another or from and to default
    streams if not specified.
---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

char use[] = "Usage: fcopy  [ Source  [ Target ] ]\n";

int main(int argc, char **argv)
{
    int c;
    FILE *infp, *outfp;

    switch(argc)
    {
        case 1:
            infp = stdin;
            outfp = stdout;
            break;
        case 2:
            infp = fopen(argv[1], "r");
            outfp = stdout;
            break;
        case 3:
            infp = fopen(argv[1], "r");
            outfp = fopen(argv[2], "w");
            break;
        default:
            fprintf(stderr, use);
            exit(1);
    }

    if(infp == NULL)
        fprintf(stderr, "Error while opening %s\n", argv[1]), exit(2);
    if(outfp == NULL)
        fprintf(stderr, "Error while opening %s\n", argv[2]), exit(3);
    
    while((c = getc(infp)) != EOF)
        putc(c, outfp);

    return 0;
}