#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);

    int length = 0;
    long temp = num;
    int sum = 0;
    bool isSecondDigit = false;

    while (temp != 0)
    {
        int digit = temp % 10;

        if (isSecondDigit)
        {
            digit *= 2;
            while (digit > 0)
            {
                sum += digit % 10;
                digit /= 10;
            }
        }
        else
        {
            sum += digit;
        }

        isSecondDigit = !isSecondDigit;
        temp /= 10;
        length++;
    }

    // Get the first two digits of the card number
    long firstTwoDigits = num;
    while (firstTwoDigits >= 100)
    {
        firstTwoDigits /= 10;
    }

    // Check card type
    if (sum % 10 == 0)
    {
        if ((length == 13 || length == 16) && (firstTwoDigits / 10 == 4))
        {
            printf("VISA\n");
        }
        else if (length == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (firstTwoDigits >= 51 && firstTwoDigits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}