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

    // Unable to open file
    if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }


    // Open memory card raw data file with read permission
    FILE *raw_file = fopen(argv[1], "r");

    unsigned char buffer[512]; //save 512 bytes at a time per block into a buffer array

    char filename[8]; //array of chars in filename

    // Output file for writing JPEGs to
    FILE *img = NULL;

    int jpeg_counter = 0; // counter variable for JPEGs found in file.

    // If JPEG found, set to true
    bool jpeg_found = false;

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
            if (jpeg_found == true)
            {
                // found start of new JPEG, close current JPEG
                fclose(img);
                // create new JPEG
                sprintf(filename, "%03i.jpg", jpeg_counter);
                img = fopen(filename, "w");
                jpeg_counter++;
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
            }
            else
            {
                // first JPEG found
                jpeg_found = true;
            }

        }
        if (jpeg_found == true)
        {
            // not a JPEG
            // Skip ahead 508 bytes to next block
            // fread(buffer, 512, 1, raw_file);
            fwrite(&buffer, sizeof buffer, 1, img);

        }
    }

}

    // Write 512 bytes at a time until new JPEG is found

//     fwrite(data, size, number, outptr);

//     // Write condition that indicates when 512 bytes have
//     // been successfully read and condition for when EOF is reached.

//     fclose(raw_file);

//     fclose(img);

//     free(buffer);

// }

// // Pseudocode

// // Open card file
// // Repeat until end of card
// //  read 512 bytes into a buffer
// //  start of a new JPEG?

// //  already found a JPEG?

// // Close any remaining files

// // While not end of card file
// //    Read

// // Check if first 4 bytes of a block indicate a
//     // JPEG header. If not, skip to next block.
//     // Repeat until the first 512th block of a JPEG
//     // is found. This indicates our first JPEG.
//     // All blocks side-to-side from here on will contain JPEGs
//     // When new JPEG is reached, the current JPEG has ended.
//     // Close that then start the new JPEG.
//     // Repeat until EOF is reached.



//     //fread(buffer, 1, 512, raw_file);

//     // or

//     // fread(buffer, 512, 1, raw_file);

//     // Check header of first 4 bytes of block
//     // to indicate whether JPEG or not

//     // Making a new JPEG

//     // Filenames: ###.jpg
//     // Named in order the files are found,
//     // starting at 000.

//     sprintf("card.raw", "%03i.jpg", 2);
//     // filename: char array to store resultant string
//     // ie 002.jpg

//     // Open new file with writing permissions
//     FILE *img = fopen(filename, "w");
