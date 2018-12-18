#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int image[3][3] = {{1, 1, 1}, {1,0,1},{1,1,1}};

    int n = 2;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", image[i][j]);
        }
    }

    // for (int i = 0; i < sizeof(image); i++)
    // {
    //     // sub_image = image[i];
    //     for (int j = 0; j < sizeof(image[i]); j++)
    //     {
    //         for (int i_n = 0; i_n < 0; i_n++)
    //         {

    //         }
    //     }

    // }

}