#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_card_digit(long card_number, int n);

int main(void)
{
    int digit;
    long card_number = get_long("Card number: ");
}

int get_card_digit(long card_number, int n)
{
    int digit;
    for (int i = 0; i < n; i++)
    {
        digit = card_number % 10;
        card_number = card_number / 10;
    }
    return digit;
}
