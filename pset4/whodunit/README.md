# Questions

## What's `stdint.h`?

'stdint.h' is a C standard library that defines a set of typedefs that specify exact-width integer types,
along with the defined maximum and minimum allowable values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are fixed-width integer data types.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

'BYTE' - 1 byte (8 bits)
'DWORD'- 4 bytes
'LONG' - 4 bytes
'WORD' - 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x42 0x4D in hexadecimal
BM in ASCII


## What's the difference between `bfSize` and `biSize`?

bfSize defines the size, in bytes, of the file.
biSize defines the size, in bytes, required by the structure.

## What does it mean if `biHeight` is negative?

If biHeight is negative, it indicates a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Some possibilities are that the file to be opened cannot be found as
it hasn't been created yet, or no file is specified in the command line.

## Why is the third argument to `fread` always `1` in our code?

It reads the hash.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?



## What does `fseek` do?

TODO

## What is `SEEK_CUR`?

TODO

## Whodunit?

It was Professor Plum with the candlestick in the library.
