#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        for (int j = i + 1; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    string text = get_string("plaintext: ");
    string key = argv[1];
    string cipher = text;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                int index = text[i] - 'A';
                cipher[i] = toupper(key[index]);
            }
            else
            {
                int index = text[i] - 'a';
                cipher[i] = tolower(key[index]);
            }
        }
    }
    printf("ciphertext: %s\n", cipher);
    return 0;
}