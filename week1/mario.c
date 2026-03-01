#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user for a valid height between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Iterate over each row
    for (int row = 1; row <= height; row++)
    {
        // Print leading spaces
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // Print hashes
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
