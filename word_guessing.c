
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "games.h"

void wordGuessing(void)
{
    const char word[] = "EMBEDDED";
    int guessed[sizeof(word)] = {0};
    int remaining = 6;
    int i, complete, found;
    char letter;

    printf("\n--- WORD GUESSING ---\n");
    printf("Hint: A field of electronics and programming.\n");

    while (remaining > 0)
    {
        complete = 1;

        printf("\nWord: ");

        for (i = 0; word[i] != '\0'; i++)
        {
            if (guessed[i])
                printf("%c ", word[i]);
            else
            {
                printf("_ ");
                complete = 0;
            }
        }

        if (complete)
        {
            printf("\nCongratulations! You won!\n");
            return;
        }

        printf("\nAttempts remaining: %d\n", remaining);
        printf("Enter a letter: ");

        if (scanf(" %c", &letter) != 1)
            return;

        letter = (char)toupper((unsigned char)letter);
        found = 0;

        for (i = 0; word[i] != '\0'; i++)
        {
            if (word[i] == letter && !guessed[i])
            {
                guessed[i] = 1;
                found = 1;
            }
        }

        if (found)
            printf("Correct letter!\n");
        else
        {
            printf("Wrong or already guessed!\n");
            remaining--;
        }
    }

    printf("You lost! The word was %s.\n", word);
}
