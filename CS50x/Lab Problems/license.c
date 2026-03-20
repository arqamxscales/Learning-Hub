#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./license plates.txt\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Array to store plate strings
    char *plates[8];
    char plate[7];
    int count = 0;

    // Read plates from file
    while (fscanf(file, "%6s", plate) == 1 && count < 8)
    {
        // Allocate memory for each plate
        plates[count] = malloc(7);
        if (plates[count] == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(file);
            return 1;
        }

        // Copy plate into allocated memory
        strcpy(plates[count], plate);
        count++;
    }

    // Close file
    fclose(file);

    // Print plates
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", plates[i]);
    }

    // Free allocated memory
    for (int i = 0; i < count; i++)
    {
        free(plates[i]);
    }

    return 0;
}
