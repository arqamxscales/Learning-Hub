#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>  // for uint8_t
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // 1. Check command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // 2. Open memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // 3. Create buffer for 512-byte blocks
    uint8_t buffer[512];

    // 4. JPEG counter and file pointer
    int jpeg_count = 0;
    FILE *img = NULL;
    char filename[8]; // enough for "000.jpg\0"

    // 5. Read memory card block by block
    while (fread(buffer, sizeof(uint8_t), 512, card) == 512)
    {
        // 5a. Check if block is the start of a JPEG
        bool is_jpeg_start = buffer[0] == 0xff &&
                             buffer[1] == 0xd8 &&
                             buffer[2] == 0xff &&
                             (buffer[3] & 0xf0) == 0xe0;

        if (is_jpeg_start)
        {
            // 5b-i. Close previous JPEG if open
            if (img != NULL)
            {
                fclose(img);
            }

            // 5b-ii. Create new JPEG filename
            sprintf(filename, "%03d.jpg", jpeg_count++);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create %s.\n", filename);
                fclose(card);
                return 1;
            }
        }

        // 5c. If a JPEG is open, write the block
        if (img != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, img);
        }
    }

    // 6. Close any remaining files
    if (img != NULL)
    {
        fclose(img);
    }

    // 7. Close memory card
    fclose(card);

    // 8. Done
    return 0;
}
