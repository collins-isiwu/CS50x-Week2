//a program to encipher a plaintext
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int num;

//the differences btw the ASCII values of uppercase alphabets & its alphabetic index is 65 = 'A'
int CAP = 65;
//the differences btw the ASCII values of lowercase alphabets & its alphabetic index is 97 = 'a'
int cap = 97;

int main(int argc, string argv[])
{
    if (argc != 2) //command-line prompt shouldn't be anything < one
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++) //iterate over the string to ensure it isn't an alphabet
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //convert the string to int
    string s = argv[1];
    num = atoi(s);

    //prompt user for any plaintext
    string txt = get_string("plaintext: ");


//iterate over the string to encipher it
    printf("ciphertext: ");
    for (int i = 0, n = strlen(txt); i < n; i++)
    {

        if (isupper(txt[i])) //remember that a string is an array of chars
        {
            char results = (((txt[i] - CAP) + num) % 26) + CAP;
            printf("%c", results);
        }
        else if (islower(txt[i]))
        {
            char results = (((txt[i] - cap) + num) % 26) + cap;
            printf("%c", results);
        }
        else
        {
            printf("%c", txt[i]);
        }
    }
    printf("\n");
}
