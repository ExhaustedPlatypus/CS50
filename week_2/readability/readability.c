#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// function prototypes
int letter_counter(string text);
int word_counter(string text);
int sentence_counter(string text);

int main(void)
{
    // get sentence from user
    string text = get_string("Text: ");

    //apply the Coleman-Liau Index
    int letter = letter_counter(text);
    int word = word_counter(text);
    int sentence = sentence_counter(text);

    float L = (float)letter / (float)word * 100;
    float S = (float)sentence / (float)word * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int round_index = round(index);

    // tests
    /*
    printf("%i letter(s)\n", letter);
    printf("%i word(s)\n", word);
    printf("%i sentence(s)\n", sentence);
    */
    
    // showing results
    if (round_index < 16 && round_index >= 1)
    {
        printf("Grade %i\n", round_index);
    }
    else if (round_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

}

// function to count letters
int letter_counter(string text)
{
    int i;
    int length = strlen(text);
    int letter_count = 0;
    for (i = 0; i <= length; i++)
    {
        char character = text[i];
        if (isalpha(character))
        {
            letter_count += 1;
        }
    }
    return letter_count;
}

// function to count words
int word_counter(string text)
{
    int i;
    int length = strlen(text);
    int word_count = 1;
    for (i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            word_count += 1;
        }
    }
    return word_count;
}

//function to count sentences
int sentence_counter(string text)
{
    int i;
    int length = strlen(text);
    int sentence_count = 0;
    for (i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count += 1;
        }
    }
    return sentence_count;
}
