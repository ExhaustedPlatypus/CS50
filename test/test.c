#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_card_digit(long card_number, int n);

int main(void)
{
    int digit;
    long card_number = 657283461838;
    
    printf("\n");
    
    digit = get_card_digit(card_number, 2);
    printf("2 digit: %i\n", digit); // 3
    
    digit = get_card_digit(card_number, 5);
    printf("5 digit: %i\n", digit); // 6

    printf("\n");
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
