// caesar.c
// CS50x - Week 2, Problem Set 2
//
// Exercise: Caesar Cipher
// ------------------------
// Encrypt a message by rotating each letter forward in the alphabet
// by a numeric key given as a command-line argument.
//
//   Example (key = 3):  A→D, B→E, Z→C (wraps around)
//   "hello" → "khoor"
//
// Usage:
//   ./caesar KEY       (KEY must be a non-negative integer)
//   ./caesar           → prints usage error
//   ./caesar abc       → prints usage error
//
// How to compile:  make caesar
// How to run:      ./caesar 13
// How to check:    check50 cs50/problems/2024/x/caesar

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // 1. Check if the program is run with exactly one command-line argument
    // Also verify that the argument consists only of digits
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 2. Convert the key from string to int
    int key = atoi(argv[1]);

    // 3. Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // 4. Encrypt and print the ciphertext
    printf("ciphertext: ");

    // Loop through each character of the plaintext
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // Print the rotated character
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

// Check if a string contains only digits
bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Rotate a character by n positions, preserving case
char rotate(char c, int n)
{
    // If it's an uppercase letter
    if (isupper(c))
    {
        return (c - 'A' + n) % 26 + 'A';
    }
    // If it's a lowercase letter
    else if (islower(c))
    {
        return (c - 'a' + n) % 26 + 'a';
    }
    // If it's not a letter (e.g., punctuation, space), leave it unchanged
    else
    {
        return c;
    }
}
