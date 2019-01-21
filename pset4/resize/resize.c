// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    int n = atoi(argv[1]);

    if (n <= 0 || n > 100)
    {
        fprintf(stderr, "Usage: integer must be between 1 and 100\n");
        return 1;
    }

    char *infile = argv[2];
    char *outfile = argv[3];

    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, resizeBf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    resizeBf = bf;
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, resizeBi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    resizeBi = bi;
    /*
    BITMAPINFOHEADER resizeBi;
    fread(&resizeBi, sizeof(BITMAPINFOHEADER), 1, inptr);

    resizeBi.biWidth = bi.biWidth * n;

    resizeBi.biHeight = abs(bi.biHeight) * n;

    */



    //TODO
    // Change file size -> bfSize
    // Change image size -> biSizeImage
    // Change width -> biWidth
    // Change height -> biHeight
  //  bi.biWidth *= n;
  //  bi.biHeight *= n;

    // Resize biWidth and biHeight

    resizeBi.biWidth *= n;
    resizeBi.biHeight *= n;




    //Width -> biWidth

    //Height -> biHeight
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    int newPadding = (4 - (resizeBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    resizeBi.biSizeImage = ((sizeof(RGBTRIPLE) * resizeBi.biWidth) + newPadding) * abs(resizeBi.biHeight);

    resizeBf.bfSize = resizeBi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&resizeBf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&resizeBi, sizeof(BITMAPINFOHEADER), 1, outptr);

    //bi.biWidth *= n;
    // bf.bfSize = biSize + 54;
    //bi.biHeight *= n;




    // determine padding for scanlines



    // bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);

    // bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // int newPadding = (4 - (resizeBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int a = 0; a < n; a++)
        {
        // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                //RGBTRIPLE pixels[sizeof(bi.biSizeImage)] = { }; // needs editing
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write each pixel into the output file's scanline
                // write RGB triple to outfile n times
                for (int p = 0 ; p < n; p++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                // pixels[p] = &triple; // needs editing
            }
            for (int k = 0; k < newPadding; k++)
            {
                fputc(0x00, outptr);
            }

            if (a < n - 1)
            {
                // Reset position to beginning of scanline
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            }
        }
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
