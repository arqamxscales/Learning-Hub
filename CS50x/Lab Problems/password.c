// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
 bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_symbol = false;

    // Loop through each character in the password
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
        {
            has_upper = true;
        }
        else if (islower(password[i]))
        {
            has_lower = true;
        }
        else if (isdigit(password[i]))
        {
            has_digit = true;
        }
        else if (isprint(password[i]))
        {
            has_symbol = true;
        }
    }

    // Check if all conditions are met
    if (has_upper && has_lower && has_digit && has_symbol)
    {
        return true;
    }
    else
    {
        return false;
    }


    return false;
}
