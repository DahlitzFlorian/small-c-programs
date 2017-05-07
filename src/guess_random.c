/* This program generates a random number between 1 and 15
    and the user has to guess the number within three attempts
---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    time_t sek;
    char run;
    unsigned int number;
    unsigned int guess;
    unsigned int attempts;

    do {
        time(&sek);
        srand((unsigned) sek);
        number = rand() % 15 + 1;
        attempts = 0;

        while(attempts < 3)
        {
            ++attempts;
            printf("Your guess: ");
            scanf("%d", &guess);
            fflush(stdin);

            if(guess == number)
            {
                printf("Congratiolation, it\'s correct!\n");
                break;
            }
            else if(attempts == 3)
                printf("Bad luck! Number was: %d\n", number);
            else if(guess > number)
                printf("Your guess is too big.\n");
            else if(guess < number)
                printf("Your guess is too small.\n");
        }
        printf("Another run? (Y/N): ");
        scanf("%c", &run);
        fflush(stdin);
        run = toupper(run);
    } while(run == 'Y');
}