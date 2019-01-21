#include <stdio.h>
#include <stdlib.h>

// TODO
// Open memory card file
// Find beginning of JPEG
// Open a new JPEG
// Write 512 bytes until new JPEG is found
// Detect end of file


int main(int argc, char *argv[])
{
    // Open memory card file
    FILE *raw_file = fopen(argv[1], "r");

    char* buffer = malloc(sizeof(char) * 512);
    // Read into memory card
    while(!feof(raw_file))
    {
        // fread(buffer, 1, 512, raw_file);

        // Read first 4 blocks of header

        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // header for JPEG file
            // Read 512
            fread(buffer, 1, 512, raw_file);

            // close JPEG and open new one once new JPEG is found
            fclose(raw_file);

            // open new file
            sprintf(filename, "%00i.jpg", i);
            // named in order the files are found
            // keep track of files! (how?)
            // filename: char array to store the resultant string
            // #filenames: ###.jpg
            FILE *img = fopen(filename, "w");

            // write new file 512 bytes at a time until new JPEG
            // is found
            fwrite(data, size, number, outptr);
            // read 512 blocks
        }
        else
        {
            // not a JPEG
            // Skip ahead 508 bytes to next block
            fread(buffer, 512, 1, raw_file);

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
