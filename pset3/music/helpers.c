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
    int n;

    char key = note[0];
    //int octave = note[1];
   // int length = strlen(note)
    int octave = note[strlen(note + 1)] - '0';
    int freq;
    // TODO
    switch(key){
        case 'A':
            n = 0.0;
            // printf("%i\n", n);
            // freq = 440.00;
            // printf("freq: %i\n", freq);
            break;
        case 'B':
            n = 2.0;
            // printf("%i\n", n);
            // freq = pow(2.0, (2.0/12.0)) * 440.00;
            // printf("freq: %i\n", freq);
            break;
        case 'C':
            n = -9.0;
            // freq =  pow(2.0, (-9.0/12.0)) * 440.00;
            // printf("freq: %i\n", freq);
            break;
        case 'D':
            n = -7.0;
            // freq = pow(2.0, (-7.0/12.0)) * 440.00;
            //
            break;
        case 'E':
            n = -5.0;
            // freq = pow(2.0, (-5.0/12.0)) * 440.00;
            // printf("freq: %i\n", freq);
            break;
        case 'F':
            n = -4.0;
            // freq = pow(2.0, (-4.0/12.0)) * 440.00;
            // printf("freq: %i\n", freq);
            break;
        case 'G':
            n = -2.0;
            // freq = pow(2.0, (-2.0/12.0)) * 440.00;
            // printf("freq: %i\n", freq);
            break;
    }

    //int num_semitones = pow(2, (n/12) * 440.00);
    if (note[1] == '#')
    {
        n += 1;
    }
    else if (note[1] == 'b')
    {
        n -= 1;
    }

    if (octave >= 0 && octave <= 8)
    {
        n +=  (octave - 4.0) * 12.0;
        //n *= 12;
    }

    // else
    // {

    // }
    // freq = 440 * pow(2, octave-4);
   // printf("%i\n", n);
    freq = round(pow(2.0, (n/12.0)) * 440.00);
    //int result = round(freq);
    // printf("final freq: %i\n", freq);

    return freq;
    // Frequency = 2^(n\12) * 440

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
