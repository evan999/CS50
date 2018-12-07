// Helper functions for music

#include <cs50.h>

#include "helpers.h"
#include <stdbool.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(s == '\r')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
