
#include <stdio.h>
#include <stdlib.h>
#include "games.h"

void rockPaperScissors(void)
{
    int player, computer;

    printf("\n--- ROCK PAPER SCISSORS ---\n");
    printf("1. Rock\n2. Paper\n3. Scissors\n");
    printf("Enter your choice: ");

    if (scanf("%d", &player) != 1)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        printf("Invalid input!\n");
        return;
    }

    if (player < 1 || player > 3)
    {
        printf("Choose 1, 2 or 3.\n");
        return;
    }

    computer = rand() % 3 + 1;

    printf("You chose: %s\n",
           player == 1 ? "Rock" :
           player == 2 ? "Paper" : "Scissors");

    printf("Computer chose: %s\n",
           computer == 1 ? "Rock" :
           computer == 2 ? "Paper" : "Scissors");

    if (player == computer)
        printf("Draw!\n");
    else if ((player == 1 && computer == 3) ||
             (player == 2 && computer == 1) ||
             (player == 3 && computer == 2))
        printf("You win!\n");
    else
        printf("Computer wins!\n");
}
