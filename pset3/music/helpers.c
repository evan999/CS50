// Helper functions for music

#include <cs50.h>

#include "helpers.h"
#include <stdbool.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    int x = atoi(fraction[0]);
    int y = atoi(fraction[2]);
    int eighths = (x/y) * 8;
    return eighths;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int n = 0;

    int key = atoi(note[1]);
    if(note[2] == '#' || note[2] == 'b')
    {
        int accidental = atoi(note[2]);
    }
    else
    {
        int octave = atoi(note[2]);
    }
    float freq = 1.00;

    // TODO
    switch(key){
        case 'A':
            n = 0;
            if (octave > 4)
            {
                for(int i = 4; i < octave; i++)
                {
                    n += 12;
                }
            }
            else if (octave < 4)
            {
                for(int i = 4; i > octave; i--)
                {
                    n -= 12;
                }
            }
        case 'B':
            n = 2;
            if (octave > 4)
            {
                for(int i = 4; i < octave; i++)
                {
                    n += 12;
                }
            }
            else if (octave < 4)
            {
                for(int i = 4; i > octave; i--)
                {
                    n -= 12;
                }
            }
        case 'C':
            n = -9;
            if (octave > 4)
            {
                for(int i = 4; i < octave; i++)
                {
                    n += 12;
                }
            }
            else if (octave < 4)
            {
                for(int i = 4; i > octave; i--)
                {
                    n -= 12;
                }
            }
        case 'D':
            n = -7;
            if (octave > 4)
            {
                for(int i = 4; i < octave; i++)
                {
                    n += 12;
                }
            }
            else if (octave < 4)
            {
                for(int i = 4; i > octave; i--)
                {
                    n -= 12;
                }
            }
        case 'E':
            n = -5;
            if (octave > 4)
            {
                for(int i = 4; i < octave; i++)
                {
                    n += 12;
                }
            }
            else if (octave < 4)
            {
                for(int i = 4; i > octave; i--)
                {
                    n -= 12;
                }
            }
        case 'F':
            n = -4;
            if (octave > 4)
            {
                for(int i = 4; i < octave; i++)
                {
                    n += 12;
                }
            }
            else if (octave < 4)
            {
                for(int i = 4; i > octave; i--)
                {
                    n -= 12;
                }
            }
        case 'G':
            n = -2;
            if (octave > 4)
            {
                for(int i = 4; i < octave; i++)
                {
                    n += 12;
                }
            }
            else if (octave < 4)
            {
                for(int i = 4; i > octave; i--)
                {
                    n -= 12;
                }
            }
    }

    //int num_semitones = pow(2, (n/12) * 440.00);

    float freq = (pow(2, n/12.0) * 440.00);
    int result = round(freq);

    return result;
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
