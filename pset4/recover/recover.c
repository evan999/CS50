#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// TODO
// Open memory card file
// Find beginning of JPEG
// Open a new JPEG
// Write 512 bytes until new JPEG is found
// Detect end of file


int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open memory card raw data file with read permission
    FILE *raw_file = fopen(argv[1], "r");

    // Unable to open file
    if (raw_file == NULL)
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
    int jpeg_found = 0;

    // Read into memory card file
    while(fread(buffer, sizeof buffer, 1, raw_file) == 1)
    {
        // fread(buffer, 1, 512, raw_file);

        // Read first 4 bytes of header for each block
        // Determine if block contains a JPEG.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If not first JPEG

                // found start of new JPEG, close current JPEG
                //fclose(img);
                // create new JPEG
            //fclose(img);
            if (jpeg_found == 1)
            {
                // first JPEG found
                fclose(img);
                //img = NULL;
                //fwrite(&buffer, 512, 1, img);

                //jpeg_found = true;
            }
            else
            {
                jpeg_found = 1;
            }

            sprintf(filename, "%03i.jpg", jpeg_counter);
            img = fopen(filename, "w");
            jpeg_counter++;
            //fwrite(&buffer, 1, 512, img);
                // close JPEG and open new one once new JPEG is found


                // open new file


                // named in order the files are found
                // keep track of files! (how?)
                // filename: char array to store the resultant string
                // #filenames: ###.jpg


                // write new file 512 bytes at a time until new JPEG
                // is found
                //fwrite(data, size, number, outptr);
                // read 512 blocks
            //}


        }

        if (jpeg_found == 1)
        {
            fwrite(&buffer, 512, 1, img);
        }

        // if (jpeg_found == true)
        // {
        //     // not a JPEG
        //     // Skip ahead 508 bytes to next block
        //     // fread(buffer, 512, 1, raw_file);
        //     fwrite(&buffer, sizeof buffer, 1, img);

        // }
    }
    printf("Total jpegs found: %i\n", jpeg_counter);
    fclose(raw_file);
    fclose(img);

    return 0;
}