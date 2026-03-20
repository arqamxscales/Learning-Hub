// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define NUM_ITEMS 10

typedef struct
{
    char item[50];
    float price;
}
menu_item;

void add_items(menu_item menu[]);
float get_cost(string item, menu_item menu[]);

// Convert string to lowercase
void to_lowercase(char *word)
{
    for (int i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);
    }
}

int main(void)
{
    menu_item menu[NUM_ITEMS];
    add_items(menu);

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i].price);
    }

    float total = 0;

    while (true)
    {
        string food = get_string("\nEnter a food item: ");

        if (strlen(food) == 0)
        {
            break;
        }

        total += get_cost(food, menu);
    }

    printf("\nYour total cost is: $%.2f\n", total);
}

// Add menu items
void add_items(menu_item menu[])
{
    strcpy(menu[0].item, "Burger");
    menu[0].price = 9.50;

    strcpy(menu[1].item, "Vegan Burger");
    menu[1].price = 11.00;

    strcpy(menu[2].item, "Hot Dog");
    menu[2].price = 5.00;

    strcpy(menu[3].item, "Cheese Dog");
    menu[3].price = 7.00;

    strcpy(menu[4].item, "Fries");
    menu[4].price = 5.00;

    strcpy(menu[5].item, "Cheese Fries");
    menu[5].price = 6.00;

    strcpy(menu[6].item, "Cold Pressed Juice");
    menu[6].price = 7.00;

    strcpy(menu[7].item, "Cold Brew");
    menu[7].price = 3.00;

    strcpy(menu[8].item, "Water");
    menu[8].price = 2.00;

    strcpy(menu[9].item, "Soda");
    menu[9].price = 2.00;
}

// Linear search for item price
float get_cost(string item, menu_item menu[])
{
    char input[50];
    strcpy(input, item);
    to_lowercase(input);

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        char menu_item_name[50];
        strcpy(menu_item_name, menu[i].item);
        to_lowercase(menu_item_name);

        if (strcmp(input, menu_item_name) == 0)
        {
            return menu[i].price;
        }
    }

    return 0;
}
