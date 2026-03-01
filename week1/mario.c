// mario.c
// CS50x - Week 1, Problem Set 1
//
// Exercise: Mario (Less Comfortable)
// ------------------------------------
// Print a right-aligned half-pyramid of # symbols.
// The user provides the height (1–8).
//
// Expected output (height = 4):
//    #
//   ##
//  ###
// ####
//
// How to compile:  make mario
// How to run:      ./mario
// How to check:    check50 cs50/problems/2024/x/mario/less

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // TODO: Same do-while input validation as mario.c (height 1–8)
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // TODO: Print each row of the double pyramid
    for (int row = 1; row <= height; row++)
    {
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // Print hashes for the left side
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Print the gap between the two pyramids
        printf("  ");

        // Print hashes for the right side
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
