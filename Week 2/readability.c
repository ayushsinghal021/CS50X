#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string t = get_string("Text: ");
    int letters = 0;
    int words = 1;
    int sen = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] == ' ')
        {
            words++;
        }
        else if (t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            sen++;
        }
        else if (isalpha(t[i]))
        {
            letters++;
        }
    }

    float L = (float) letters / words * 100;
    float S = (float) sen / words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}