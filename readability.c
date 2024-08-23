#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    //get text to analyze text
    string text = get_string("Text: ");

    int letterCount = 0, wordCount = 0, sentenceCount = 0;
    //Counts letters, words, sentences
    for (int i = 0, stringlength = strlen(text); i < stringlength + 1; i++)
    {
        // assuming a...z and A...Z is a letter
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letterCount++;
        }

        // any chars seperated by space is a word, check end of string count last word
        if (text[i] == ' ' || text[i] == '\0')
        {
            wordCount++;
        }

        // when you see a . ! or ? count as sentence
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentenceCount++;
        }
    }

    //Calculating the Grade Reading Index
    float avgWordsPer100 = (100 / (float) wordCount) * (float) letterCount;
    float avgSentencePer100 = (100 / (float) wordCount) * (float) sentenceCount;
    int index = round(0.0588 * avgWordsPer100 - 0.296 * avgSentencePer100 - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}