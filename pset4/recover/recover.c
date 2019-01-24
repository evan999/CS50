#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{
    // Need to enter the memory card file to read from.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open memory card raw data file with read permission
    FILE *memory_card = fopen(argv[1], "r");

    // Unable to open file
    if (memory_card == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    unsigned char buffer[512]; //save 512 bytes at a time per block into a buffer array

    char filename[8]; //array of chars in filename

    // Output file for writing JPEGs to
    FILE *img = NULL;

    int jpeg_counter = 0; // counter variable for JPEGs found in file.

    // If JPEG found, set to 1
    // int jpeg_found = 0;

    // Read into memory card file
    while (fread(buffer, sizeof buffer, 1, memory_card) == 1)
    {

        // Read first 4 bytes of header for each block
        // Determine if block contains a JPEG.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                // close current JPEG so the next JPEG can be read
                fclose(img);
            }
            else
            {
                // JPEG found
                img = NULL;
            }

            // Output JPEG files
            sprintf(filename, "%03i.jpg", jpeg_counter);
            img = fopen(filename, "w");
            jpeg_counter++;
        }

        if (img != NULL)
        {
            // Write to block 512 blocks 1 byte each for each image found
            fwrite(&buffer, 512, 1, img);
        }
    }
    // printf("Total jpegs found: %i\n", jpeg_counter);

    // Close memory card file and any open JPEG files
    fclose(memory_card);
    fclose(img);

    return 0;
}