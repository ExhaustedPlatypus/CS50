#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int starting_population;
    int ending_population;
    int n = 0;
    int new_born;
    int dead;
    
    // TODO: Prompt for start size
    do
    {
        starting_population = get_int("What's your starting population? ");
    }
    while (starting_population < 9);

    // TODO: Prompt for end size
    do
    {
        ending_population = get_int("What's your ending population? ");
    }
    while (ending_population < starting_population);

    // TODO: Calculate number of years until we reach threshold
    
    while (starting_population < ending_population)
    {
        new_born = starting_population / 3;
        dead = starting_population / 4;
        starting_population = starting_population + new_born - dead;
        n = n + 1;
    }
    
    // TODO: Print number of years
    printf("Years: %i\n", n);
}
