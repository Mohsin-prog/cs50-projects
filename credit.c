#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompting User for Credit Card Number
    long x = 0;
    do
    {
        x = get_long("Number ");
    }
    while (x <= 0);

    int digit = 0, sum = 0;

    // Using digit to check odd and even number
    long y = x;

    // Checksum card digits
    while (y != 0)
    {
        int even = 0, odd = 0;
        int reminder = y % 10;
        digit++;

        // Checking if digit number is even
        if (digit % 2 == 0)
        {
            int multiply = reminder * 2;
            if (multiply == 0)
            {
                even += multiply;
            }

            else
            {
                // Adding all digits number after
                while (multiply != 0)
                {
                    even += multiply % 10;
                    //Minus last digit number to multiply
                    multiply /= 10;
                }
            }
        }

        //if digit number is odd
        else
        {
            odd += reminder;
        }
        // Minus last digit number from y
        y /= 10;

        sum += even + odd;
    }

    //Checking credit card number if valid
    if (digit != 13 && digit != 15 && digit != 16)
    {
        printf("INVALID\n");
    }
    else if (sum % 10 == 0)
    {
        //if card digit is 16
        if (digit == 16)
        {
            if (x / 100000000000000 >= 51 && x / 100000000000000 <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if (x / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            //if card digit is not 16
            else
            {
                printf("INVALID\n");
            }
        }

        //Checking else if card digits are equal to 15
        else if (digit == 15)
        {
            if (x / 10000000000000 == 34 || x / 10000000000000 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        //Checking else if card digits are equal to 13
        else if (digit == 13)
        {
            if (x / 1000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }

    //if credit digit are not valid
    else
    {
        printf("INVALID\n");
    }
}