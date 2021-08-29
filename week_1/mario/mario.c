#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pyramid_height;
    char space = ' ';
    string double_space = "  ";
    char brick = '#';
    
    // pyramid height choice
    do
    {
        pyramid_height = get_int("Choose the pyramid height from 1 to 8: ");
    }
    while (pyramid_height < 1 || pyramid_height > 8);
    
    // create the pyramid
    for (int i = 1; i <= pyramid_height; i++)
    {
        
        // create spaces
        for (int j = 1; j <= pyramid_height - i; j++) 
        {
            printf("%c", space);
        }
        
        // create bricks
        for (int k = 1; k <= pyramid_height - (pyramid_height - i); k++)
        {
            printf("%c", brick);
        }
        
        // create middle space
        printf("%s", double_space);
        
        // create second section of bricks
        for (int k = 1; k <= pyramid_height - (pyramid_height - i); k++)
        {
            printf("%c", brick);
        }
        
        // break line
        printf("\n");
    }
}