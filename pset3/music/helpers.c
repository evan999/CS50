// Helper functions for music

#include <cs50.h>

#include <stdio.h>
#include "helpers.h"
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    int eighths = (x/y) * 8;
    return eighths;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
   // int n;

    int letter = note[0] - '0';
    int octave = note[1] - '0';

   // int octave = strlen(note-1) - '0';
    int freq;

    if (letter == 'A')
    {
        freq = round(440 * pow(2, octave - 4));
        printf("freq: %i\n", freq);
        return freq;
    }
    else if (letter == 'B')
    {
        freq = round(494 * pow(2, octave - 4));
        printf("freq: %i\n", freq);
        return freq;
    }
    else if (letter == 'C')
    {
        freq = round(262 * pow(2, octave - 4));
         printf("freq: %i\n", freq);
        return freq;
    }
    else if (letter == 'D')
    {
        freq = round(294 * pow(2, octave - 4));
         printf("freq: %i\n", freq);
        return freq;
    }
    else if (letter == 'E')
    {
        freq = round(329 * pow(2, octave - 4));
         printf("freq: %i\n", freq);
        return freq;
    }
    else if (letter == 'F')
    {
        freq = round(349 * pow(2, octave - 4));
         printf("freq: %i\n", freq);
        return freq;
    }
    else if (letter == 'G')
    {
        freq = round(392 * pow(2, octave - 4));
        printf("freq: %i\n", freq);
        return freq;
    }

    return 0;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
