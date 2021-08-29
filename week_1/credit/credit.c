#include <cs50.h>
#include <stdio.h>
#include <math.h>

// function prototypes
int get_first_number(long card_number, int n);


int main(void)
{
    // declaring variables
    int even_number_double;
    int even_number_sum = 0;
    int odd_number_sum = 0;
    int total_sum;
    int number;
    int digit_counter = 1;

    // input card number
    long card_number = get_long("Card number: ");
    long card_number_still = card_number;

    // applying Luhn's Algorithm
    do
    {
        // separating odd and even numbers
        number = card_number % 10;
        if (digit_counter % 2 > 0) 
        {
            // calculating odd number sum
            odd_number_sum = odd_number_sum + number;
        } 
        else 
        {
            // calculating even number sum
            even_number_double = number * 2;
            if (even_number_double > 9) 
            {
                even_number_double = even_number_double % 10 + (even_number_double / 10 % 10);
            }
            even_number_sum = even_number_double + even_number_sum;
        }
        
        // updating
        card_number = card_number / 10;
        digit_counter++;

    } 
    while (card_number != 0);
    
    total_sum = even_number_sum + odd_number_sum;
    
    // adjusting digit counter
    digit_counter--;

    
    int mc_number = get_first_number(card_number_still, 14);
    
    // defining condition for AMEX card
    if (total_sum % 10 == 0 && digit_counter == 15 && (get_first_number(card_number_still, 13) == 34 
            || get_first_number(card_number_still, 13) == 37)
       )
    {
        printf("AMEX\n");
    }
    
    // defining condition for MasterCard
    else if (
        total_sum % 10 == 0 && digit_counter == 16 && (
            mc_number == 51
            || mc_number == 52
            || mc_number == 53
            || mc_number == 54
            || mc_number == 55
        )
    )
    {
        printf("MASTERCARD\n");
    }
    
    // defining condition for VISA card
    else if (total_sum % 10 == 0 && (
                 (digit_counter == 13 && (get_first_number(card_number_still, 12) == 4)) 
                 || (digit_counter == 16 && (get_first_number(card_number_still, 15) == 4))
             )
            )
    {
        printf("VISA\n");
    }
    
    // defining invalid condition
    else
    {
        printf("INVALID\n");
    }
}

// determining initial card digits
int get_first_number(long card_number, int n)
{
    return card_number / pow(10, n);
}
