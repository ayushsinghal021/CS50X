#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char name[10];
    printf("What is your name? ");
    scanf("%s",name);
    printf("hello, %s\n",name);
}