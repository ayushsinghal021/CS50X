#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        printf("Height: \n");
        scanf("%d", &h);
    }
    while (h < 1 || h > 8);
    h = h + 1;
    for (int i = 1; i < h; i++)
    {
        for (int j = h - i - 1; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}