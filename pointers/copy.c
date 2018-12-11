#include <stdio.h>

void copy(int*, int*);
void changeArray(int[]);

int main(void)
{
    int num1 = 5;
    int num2 = 10;
    printf("5 + 10 = %i\n", num1 + num2);
    copy(&num1, &num2); // send the reference, not the value
    printf("%i + %i = %i\n", num1, num2, num1 + num2);
    // int arr[5] = {1, 4, 18, 2, 59};
  //  printf("arr[2]: %i\n", arr[2]);
  //  changeArray(arr);
   // printf("arr[2]: %i\n", arr[2]);

}

void copy(int* x, int* y)
{
    *y = *x; // EDIT: go to this address, and change to this address
}

void changeArray(int theArray[])
{
    theArray[2] = 30;
}
