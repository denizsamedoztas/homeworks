#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for credit card number
    long card_number = get_long("Number: ");

    // Calculate length and extract the first two digits
    int length = 0;
    long temp = card_number;
    long first_two = card_number;

    while (temp > 0)
    {
        temp = temp / 10;
        length++;
    }

    while (first_two >= 100)
    {
        first_two = first_two / 10;
    }

    // Apply Luhn's Algorithm
    long cc = card_number;
    int sum_doubled = 0;
    int sum_rest = 0;
    int i = 0;

    while (cc > 0)
    {
        int digit = cc % 10;

        // Multiply every other digit by 2, starting with the number's second-to-last digit
        if (i % 2 == 1)
        {
            int doubled = digit * 2;
            sum_doubled += (doubled % 10) + (doubled / 10);
        }
        else
        {
            sum_rest += digit;
        }

        cc = cc / 10;
        i++;
    }

    // Check validity
    int total_sum = sum_doubled + sum_rest;

    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine card type based on length and starting digits
    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (first_two / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
