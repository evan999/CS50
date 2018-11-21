TODO:

1. Prompt and validate user input

2. Draw the half pyramid

get_int -> ensures user inputs an integer

User must enter an integer value.
Otherwise, user is prompted to retry.

Valid heights: [0, 23]
Invalid heights: less than 0, more than 23

Pseudocode:

int n;

do
{
    n = get_int();
}
while(n is invalid)

Right-aligned pyramid:

    ##
   ###
  ####
 #####
######

For every row:

-Print spaces
-Print hashes
-Print a new line


Determine the Pattern:

In a pyramid where height = 8:

first row: 2 #, 7 spaces
second row: 3 #, 6 spaces
third row: 4 #, 5 spaces
fourth: 5 #, 4 spaces
fifth: 6 #, 3 spaces
sixth: 7 #, 2 spaces
seventh: 8 #, 1 space
eight: 9 #, 0 spaces
...
nth row: x #, y spaces

Pattern:

nth row: n + 1 #, (n - 1) - 1 spaces

       ##
      ###
     ####
    #####
   ######
  #######
 ########
#########


For every row:

-Print spaces
-Print hashes
-Print a new line



