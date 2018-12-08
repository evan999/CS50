#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

int duration(string fraction);
int frequency(string note);
bool is_rest(string s);

int main(void)
{

}

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
    // TODO
    int freqNum = atoi(note[1]);

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