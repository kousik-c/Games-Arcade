
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "games.h"

int main(void)
{
    int choice;

    srand((unsigned int)time(NULL));

    do
    {
        printf("\n===== C GAMING ARCADE =====\n");
        printf("1. Tic-Tac-Toe\n");
        printf("2. Number Guessing\n");
        printf("3. Rock Paper Scissors\n");
        printf("4. Word Guessing\n");
        printf("5. General Knowledge Quiz\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            printf("Invalid input!\n");
            continue;
        }

        switch (choice)
        {
            case 1: ticTacToe(); break;
            case 2: numberGuessing(); break;
            case 3: rockPaperScissors(); break;
            case 4: wordGuessing(); break;
            case 5: quizGame(); break;
            case 0: printf("Thanks for playing!\n"); break;
            default: printf("Choose a number from 0 to 5.\n");
        }

    } while (choice != 0);

    return 0;
}
