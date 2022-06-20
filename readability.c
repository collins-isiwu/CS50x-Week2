//readability of texts
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//main is declared
int main(void)
{
    //declaration of variables
    int tally_letters, tally_words, tally_sentences;
    tally_letters = tally_sentences = 0;
    tally_words = 1;

    //request texts from user
    string s = get_string();

    //loop the process of finding the various tallies
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            tally_letters++;
        }
        if (s[i] == ' ')
        {
            tally_words += 1;
        }
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            tally_sentences += 1;
        }
    }
    //calculate the averages
    float L = tally_letters / (tally_words * 0.01);
    float S = tally_sentences / (tally_words * 0.01);

    //apply the coleman-Liau Index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //print grades
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", index);
    }

    printf("\n");
}
