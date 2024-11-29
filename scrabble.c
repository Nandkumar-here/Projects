#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calc_score(string word);
string upr(string word);

const char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");
    word1 = upr(word1);
    word2 = upr(word2);
    int score1 = calc_score(word1);
    int score2 = calc_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int calc_score(string word)
{
    int score = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (word[i] == LETTERS[j])
            {
                score += POINTS[j];
            }
        }
    }
    return score;
}

string upr(string word)
{
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word[i] - 32;
        }
    }
    return word;
}
