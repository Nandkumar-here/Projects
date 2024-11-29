#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calc_l(string text);
int calc_w(string text);
int calc_s(string text);

int main(void)
{
    int letters, words, sentences, index;
    float L, S, cl_index;

    // prompt the user for text
    string text = get_string("Text: ");

    // calc no of letters, words, sentences in the text
    letters = calc_l(text);
    words = calc_w(text);
    sentences = calc_s(text);

    // calc coleman liau index
    L = (letters * 100.0 / words);
    S = (sentences * 100.0 / words);
    cl_index = 0.0588 * L - 0.296 * S - 15.8;
    index = (int) round(cl_index);

    // display grade lvl
    if ((index >= 1) && (index < 16))
    {
        printf("Grade %i\n", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int calc_l(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int calc_w(string text)
{
    int spaces = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isblank(text[i]))
        {
            spaces++;
        }
    }
    int words = spaces + 1;
    return words;
}

int calc_s(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentences++;
        }
    }
    return sentences;
}
