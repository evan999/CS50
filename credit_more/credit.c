#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX16 5599999999999999
#define MIN16 4000000000000000

#define MAX15 379999999999999
#define MIN15 340000000000000

#define MAX13 4999999999999
#define MIN13 4000000000000

#define VISAFIRST 4
#define MASTERCARDFIRST 5
#define MASTERCARDSECONDMIN 1
#define MASTERCARDSECONDMAX 5
#define AMEXFIRST 3


int isMasterCard(int first, int second)
{
     return first == 5 && (second >= 1 && second <= 5);
}

int main(void)
{
     long long ccnum = get_long_long("Number: ");
     int length = 0;
     int modifier = 0;
    //  printf("%lld\n", ccnum);
     // Validate that credit card number is valid
     if(ccnum >= MIN16 && ccnum <= MAX16)
     {
        //   printf("Card may be Visa or Mastercard\n");
          length = 16;
          modifier = 1;
          // start count on first number
     }
     else if(ccnum >= MIN15 && ccnum <= MAX15)
     {
        //   printf("Card may be an AMEX\n");
          // start count on second
          length = 15;
     }
     else if(ccnum >= MIN13 && ccnum <= MAX13)
     {
        //   printf("Card may be a Visa\n");
          // start count on second
          length = 13;
     }
     else
     {
          printf("INVALID\n");
          return 0;
     }
     int timesTwo = 0;
     int noTimes = 0;
     int firstDigit = 0;
     int secondDigit = 0;

     // Luhn's Algorithm to determine card carrier
     for(; length > 0; length--)
     {
          int digit = ccnum % 10;
          //printf("length: %i\tDigit: %i\n", length, digit);
          if(length == 2)
          {
               secondDigit = digit;
          }
          else if (length == 1)
          {
               firstDigit = digit;
          }
          ccnum = ccnum / 10;
          if(length % 2 == 0)
          {
               int temp = digit * 2;
               timesTwo += temp % 10 + temp / 10;
          }
          else
          {
               noTimes += digit;
          }
     }
     int final = noTimes + timesTwo;
     if (final % 10 == 0)
     {
          if (firstDigit == VISAFIRST)
          {
               printf("VISA\n");
          }
          else if (isMasterCard(firstDigit, secondDigit))
          {
               printf("MASTERCARD\n");
          }
          else if (firstDigit == AMEXFIRST)
          {
               if (secondDigit == 4 || secondDigit == 7)
               {
                  printf("AMEX\n");
               }
          }
     }
     else
     {
          printf("INVALID\n");
     }
     printf("%i\n", final);
     //printf("timesTwo: %i\tnoTimes: %i\n", timesTwo, noTimes);
     //printf("total: %i\n", final);
}
//378282246310005