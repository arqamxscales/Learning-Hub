// Copies a BMP file
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./bottomup input.bmp output.bmp\n");
        return 1;
    }

    // Open input file
    FILE *inptr = fopen(argv[1], "rb");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Open output file
    FILE *outptr = fopen(argv[2], "wb");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", argv[2]);
        return 1;
    }

    // Read file header
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read info header
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Flip image orientation by changing metadata
    bi.biHeight = -bi.biHeight;

    // Write headers to output file
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Calculate padding
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Absolute height (since we changed the sign)
    int height = abs(bi.biHeight);

    // Copy pixel data
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE pixel;
            fread(&pixel, sizeof(RGBTRIPLE), 1, inptr);
            fwrite(&pixel, sizeof(RGBTRIPLE), 1, outptr);
        }

        // Skip padding
        fseek(inptr, padding, SEEK_CUR);

        // Write padding
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Close files
    fclose(inptr);
    fclose(outptr);

    return 0;
}
