// scrabble.c
// CS50x - Week 2, Problem Set 2
//
// Exercise: Scrabble
// -------------------
// Two players each enter a word. Compute each word's Scrabble score
// and announce the winner (or a tie).
//
// How to compile:  make scrabble
// How to run:      ./scrabble
// How to check:    check50 cs50/problems/2024/x/scrabble

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Point values for each letter A-Z (index 0 = A, index 25 = Z)
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype
int compute_score(string word);

int main(void)
{
    // Prompt both players for their words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    
    // Compute scores for each player
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner or "Tie!"
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

// ---------------------------------------------------------------------------
// Given a word, return its Scrabble score.
// ---------------------------------------------------------------------------
int compute_score(string word)
{
    int score = 0;

    // Loop through each character of the word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Check if the character is a letter (ignore punctuation/spaces)
        if (isalpha(word[i]))
        {
            // Convert to uppercase so 'A' and 'a' are treated the same
            // Subtract 'A' to get the alphabet index (0 to 25)
            int index = toupper(word[i]) - 'A';

            // Add the corresponding points to the total score
            score += POINTS[index];
        }
    }

    return score;
}
