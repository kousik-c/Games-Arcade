
#include <stdio.h>
#include <stdlib.h>
#include "games.h"

void numberGuessing(void)
{
    int secret = rand() % 100 + 1;
    int guess, attempts = 0;

    printf("\n--- NUMBER GUESSING ---\n");
    printf("Guess a number between 1 and 100.\n");

    while (1)
    {
        printf("Enter your guess: ");

        if (scanf("%d", &guess) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            printf("Enter a valid integer!\n");
            continue;
        }

        attempts++;

        if (guess < secret)
            printf("Too low! Try again.\n");
        else if (guess > secret)
            printf("Too high! Try again.\n");
        else
        {
            printf("Correct! You won in %d attempts.\n", attempts);
            break;
        }
    }
}
