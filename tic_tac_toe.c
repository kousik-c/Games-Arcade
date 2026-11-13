
#include <stdio.h>
#include "games.h"

void ticTacToe(void)
{
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    int move, row, col, turn = 0;
    int winner = 0;
    char player;

    printf("\n--- TIC-TAC-TOE ---\n");

    while (turn < 9 && !winner)
    {
        for (row = 0; row < 3; row++)
        {
            printf("\n %c | %c | %c\n",
                   board[row][0],
                   board[row][1],
                   board[row][2]);

            if (row < 2)
                printf("---+---+---\n");
        }

        player = (turn % 2 == 0) ? 'X' : 'O';

        printf("Player %c, enter position (1-9): ", player);

        if (scanf("%d", &move) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            printf("Invalid input!\n");
            continue;
        }

        if (move < 1 || move > 9)
        {
            printf("Choose from 1 to 9.\n");
            continue;
        }

        row = (move - 1) / 3;
        col = (move - 1) % 3;

        if (board[row][col] == 'X' ||
            board[row][col] == 'O')
        {
            printf("Position already occupied!\n");
            continue;
        }

        board[row][col] = player;
        turn++;

        for (row = 0; row < 3; row++)
        {
            if (board[row][0] == player &&
                board[row][1] == player &&
                board[row][2] == player)
                winner = 1;

            if (board[0][row] == player &&
                board[1][row] == player &&
                board[2][row] == player)
                winner = 1;
        }

        if (board[0][0] == player &&
            board[1][1] == player &&
            board[2][2] == player)
            winner = 1;

        if (board[0][2] == player &&
            board[1][1] == player &&
            board[2][0] == player)
            winner = 1;

        if (winner)
            printf("Player %c wins!\n", player);
    }

    if (!winner)
        printf("Game drawn!\n");

    for (row = 0; row < 3; row++)
    {
        printf("%c | %c | %c\n",
               board[row][0], board[row][1], board[row][2]);
        if (row < 2)
            printf("--+---+--\n");
    }
}
