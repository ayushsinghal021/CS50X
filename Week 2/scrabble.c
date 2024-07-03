#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getLetterValue(char letter);
int main(void)
{
    string p1, p2;
    p1 = get_string("Player 1: ");
    p2 = get_string("Player 2: ");
    int sum1 = 0;
    int sum2 = 0;
    char letter = '\0';

    for (int temp = 0; temp < strlen(p1); temp++)
    {
        letter = p1[temp];
        sum1 = sum1 + getLetterValue(letter);
    }
    for (int temp = 0; temp < strlen(p2); temp++)
    {
        letter = p2[temp];
        sum2 = sum2 + getLetterValue(letter);
    }
    if (sum1 > sum2)
    {
        printf("Player 1 wins!");
    }
    else if (sum1 < sum2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!\n");
    }
}

int getLetterValue(char letter)
{
    switch (toupper(letter))
    {
        case 'A':
            return 1;
        case 'B':
            return 3;
        case 'C':
            return 3;
        case 'D':
            return 2;
        case 'E':
            return 1;
        case 'F':
            return 4;
        case 'G':
            return 2;
        case 'H':
            return 4;
        case 'I':
            return 1;
        case 'J':
            return 8;
        case 'K':
            return 5;
        case 'L':
            return 1;
        case 'M':
            return 3;
        case 'N':
            return 1;
        case 'O':
            return 1;
        case 'P':
            return 3;
        case 'Q':
            return 10;
        case 'R':
            return 1;
        case 'S':
            return 1;
        case 'T':
            return 1;
        case 'U':
            return 1;
        case 'V':
            return 4;
        case 'W':
            return 4;
        case 'X':
            return 8;
        case 'Y':
            return 4;
        case 'Z':
            return 10;
        default:
            return 0; // If the character is not in the list, return 0
    }
}