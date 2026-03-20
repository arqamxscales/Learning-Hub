#include<stdio.h>
#include<string.h>
#include<ctype.h>

int compute_score(char word[]);

int main(void)
{
    char word1[50];
    char word2[50];

    // Get input from both players
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);

      printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(char word[])
{
    // Scrabble points for A to Z
    int points[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
        5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
        1, 4, 4, 8, 4, 10
    };

    int score = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            char letter = toupper(word[i]);
            score += points[letter - 'A'];
        }
    }

    return score;
}

