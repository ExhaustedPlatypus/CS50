#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// function prototype
int caesar_algorithm(int key, char text);
int get_index(char character);

// users provides the key
int main (int argc, string argv[])
{
    int i;
    
    if (argc == 2)
    {
        if (isdigit(argv[1]) && argv[1] > 0)
        {
            printf("Success");
            
            // user provides plaintext
            string text[] = get_string("plaintext: ");
            
            // calculate ciphertext
            int length = strlen(text);
            
            for ( i = 0; i < length; i++)
            {
                if (isalpha(text[i]))
                {
                    if (isupper(text[i]))
                    {
                        char text[i] = caesar_algorithm(argv[1], text[i]) + 64;
                    }
                    else
                    {
                        char text[i] = caesar_algorithm(argv[1], text[i]) + 96;
                    }
                }
                
                // print ciphertext
                printf("ciphertext: %s\n", text[]);
            }
        }
        else
        {
            printf("Usage: ./caesar key");
        }
    }
    else
    {
        printf("Usage: ./caesar key");
    }
}

// defining caesar algorithm
int caesar_algorithm(int key, char text)
{
    int index = get_index(text);
    
    int ciphertext_character = ( index + key) % 26;
    return ciphertext_character;
}

// get the character index
int get_index(char character)
{
    return toupper(character) - 'A';
}
