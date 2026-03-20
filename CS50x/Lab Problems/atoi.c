#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Base case: only one character left
    if (strlen(input) == 1)
    {
        return input[0] - '0';
    }

    // Recursive case
    int last_digit = input[strlen(input) - 1] - '0';

    // Temporarily shorten the string
    input[strlen(input) - 1] = '\0';

    return convert(input) * 10 + last_digit;
}
