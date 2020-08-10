#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isInteger(string s);
void cipher(string argv, string s);

int main(int argc, string argv[])
{
    if (argc != 2 || isInteger(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    cipher(argv[1], plaintext);

    return 0;
}

// Functions

int isInteger(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

void cipher(string argv, string s)
{
    char ciphertext[strlen(s)];
    int key = atoi(argv);
    if (key >= 26)
    {
        key %= 26;
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) == 0)
        {
            ciphertext[i]  = s[i];
        }
        else
        {
            if (isupper(s[i]))
            {
                if (s[i] + key > 90)
                {
                    ciphertext[i]  = s[i] + key - 26;
                }
                else
                {
                    ciphertext[i]  = s[i] + key;
                }
            }
            if (islower(s[i]))
            {
                if (s[i] + key > 122)
                {
                    ciphertext[i]  = s[i] + key - 26;
                }
                else
                {
                    ciphertext[i]  = s[i] + key;
                }
            }
        }

    }
    printf("ciphertext: %s\n", ciphertext);
}