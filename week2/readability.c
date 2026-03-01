// readability.c
// CS50x - Week 2, Problem Set 2
//
// Exercise: Readability
// ----------------------
// Compute the Coleman-Liau readability index of a text sample
// and print the corresponding U.S. grade level.
//
// Formula:
//   index = 0.0588 * L - 0.296 * S - 15.8
//   L = average letters per 100 words
//   S = average sentences per 100 words
//
// Output:
//   index >= 16  → "Grade 16+"
//   index < 1   → "Before Grade 1"
//   otherwise   → "Grade X"
//
// How to compile:  make readability   (links -lm automatically via cs50.h)
// How to run:      ./readability
// How to check:    check50 cs50/problems/2024/x/readability

#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count letters, words, and sentences
    int letters   = count_letters(text);
    int words     = count_words(text);
    int sentences = count_sentences(text);

    // Compute L and S (averages per 100 words)
    // Cast to float to avoid integer division
    float L = (float) letters / (float) words * 100.0;
    float S = (float) sentences / (float) words * 100.0;

    // Apply the Coleman-Liau formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level based on the index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

// ---------------------------------------------------------------------------
// Return the number of letters (a-z, A-Z) in text.
// ---------------------------------------------------------------------------
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i])) // Checks if the character is an alphabet letter
        {
            count++;
        }
    }
    return count;
}

// ---------------------------------------------------------------------------
// Return the number of words in text.
// ---------------------------------------------------------------------------
int count_words(string text)
{
    int count = 1; // Starts at 1 because 1 space means 2 words
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ') // Checks for spaces
        {
            count++;
        }
    }
    return count;
}

// ---------------------------------------------------------------------------
// Return the number of sentences in text.
// ---------------------------------------------------------------------------
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Checks for standard sentence-ending punctuation
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
