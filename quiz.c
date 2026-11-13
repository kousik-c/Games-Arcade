
#include <stdio.h>
#include "games.h"

void quizGame(void)
{
    const char *questions[] = {
        "Which is the brain of a computer?",
        "Which language is used in this project?",
        "How many bits are in one byte?",
        "Which device measures temperature?",
        "Which symbol ends a C statement?"
    };

    const char *options[][4] = {
        {"1. RAM", "2. CPU", "3. Monitor", "4. Keyboard"},
        {"1. Java", "2. Python", "3. C", "4. HTML"},
        {"1. 4", "2. 8", "3. 16", "4. 32"},
        {"1. Thermometer", "2. Ammeter",
         "3. Voltmeter", "4. Barometer"},
        {"1. :", "2. ,", "3. ;", "4. ."}
    };

    int answers[] = {2, 3, 2, 1, 3};
    int choice, score = 0, i, j;

    printf("\n--- GENERAL KNOWLEDGE QUIZ ---\n");

    for (i = 0; i < 5; i++)
    {
        printf("\nQ%d. %s\n", i + 1, questions[i]);

        for (j = 0; j < 4; j++)
            printf("%s\n", options[i][j]);

        printf("Your answer (1-4): ");

        if (scanf("%d", &choice) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            printf("Invalid input. Question skipped.\n");
            continue;
        }

        if (choice == answers[i])
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Wrong! Correct answer: %s\n",
                   options[i][answers[i] - 1]);
        }
    }

    printf("\nFinal score: %d/5\n", score);

    if (score == 5)
        printf("Excellent!\n");
    else if (score >= 3)
        printf("Good job!\n");
    else
        printf("Keep practising!\n");
}
