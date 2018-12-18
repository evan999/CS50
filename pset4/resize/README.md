Resizing horizontally

for each row
    for each pixel in row
        write to outfile n times
    write outfile's padding
    skip over infile's padding

biWidth -> row

biWidth * n -> resize horizontally

biHeight -> col

biHeight * n -> resize vertically

pixel:

x = 00FF00

00FF00 is an RGBtriple



biWidth * n

bfSize -> size of entire file

biSizeImage -> size of image



RGBtriple row[size]

