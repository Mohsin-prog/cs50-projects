#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Points assigned to each letter of the alpabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//Recall the function
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");


    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Printing the winner
    //if player 1 win!
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    //if player 2 wins!
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }

    //if the game is tie!
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Initializing variable
    int score = 0;
    // Compute score and return score for string
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}