#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool valid_key(string key);
int encrypt(string text, int key);

int main(int argc, string agrv[])
{
    if (argc != 2)
    {
        printf("Plz enter 1 argument\n");
        return 1;
    }
    else
    {
        if (valid_key(agrv[1]))
        {
            int key = atoi(agrv[1]);
            string p = get_string("plaintext:  ");
            printf("ciphertext: ");
            encrypt(p, key);
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
}

bool valid_key(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!(key[i] >= '0' && key[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}

int encrypt(string text, int key)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i]))
        {
            char c = (text[i] - 'a' + key) % 26 + 'a';
            printf("%c", c);
        }
        else if (isupper(text[i]))
        {
            char c = (text[i] - 'A' + key) % 26 + 'A';
            printf("%c", c);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}
