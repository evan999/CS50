#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

// int duration(string fraction);
int frequency(string note);
bool is_rest(string s);

int main(void)
{
    printf("Frequency: %i", frequency());
}

// Converts a fraction formatted as X/Y to eighths
// int duration(string fraction)
// {
//     // TODO
//     int x = atoi(fraction[0]);
//     int y = atoi(fraction[2]);
//     int eighths = (x/y) * 8;
//     return eighths;
// }

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    int n = 0;

    int key = atoi(&note[1]);
    // if(note[2] == '#' || note[2] == 'b')
    // {
    //     int accidental = atoi(&note[2]);
    //     int octave = atoi(&note[3]);
    // }
    // else
    // {
    //     int octave = atoi(&note[2]);
    // }
    int octave = atoi(&note[2]);
    float freq;
    // TODO
    switch(key){
        case 'A':
            // n = 0;
            freq = 440.00;
            printf("freq: %f\n", freq);
            break;
        case 'B':
            // n = 2;
            freq = 440.00 * (pow(2, (2.0/12.0)));
            printf("freq: %f\n", freq);
            break;
        case 'C':
            // n = -9;
            freq =  440.00 * (pow(2, (-9.0/12.0)));
            printf("freq: %f\n", freq);
            break;
        case 'D':
            // n = -7;
            freq = 440.00 * (pow(2, (-7.0/12.0)));
            printf("freq: %f\n", freq);
            break;
        case 'E':
            // n = -5;
            freq = 440.00 * (pow(2, (-5.0/12.0)));
            printf("freq: %f\n", freq);
            break;
        case 'F':
            // n = -4;
            freq = 440.00 * (pow(2, (-4.0/12.0)));
            printf("freq: %f\n", freq);
            break;
        case 'G':
            // n = -2;
            freq = (pow(2, -2.0/12.0) * 440.00);
            printf("freq: %f\n", freq);
            break;
    }

    //int num_semitones = pow(2, (n/12) * 440.00);
    if (octave > 4)
    {
        for(int i = 4; i < octave; i++)
        {
            freq *= 2;
            printf("freq o+: %f\n", freq);
        }
    }
    else if (octave < 4)
    {
        for(int i = 4; i > octave; i--)
        {
            freq /= 2;
            printf("freq o-: %f\n", freq);
        }
    }
    // else
    // {

    // }
    // freq = 440 * pow(2, octave-4);

    //float freq = (pow(2, n/12.0) * 440.00);
    int result = round(freq);
    printf("final freq: %i\n", result);

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