#include <stdio.h>
#include "functionHeader.h"

int Swap_function(int *num1, int *num2)
{
    int swap = 0;
    swap = *num1;
    *num1 = *num2;
    *num2 = swap;
    return 1;
}

int sort(int *_arr, int _size, SortCriteria c)
{

    int swapCounter = 0;
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size - 1; j++)
        {

            if (c(_arr[j], _arr[j + 1]))
            {
                Swap_function(&_arr[j], &_arr[j + 1]);
                swapCounter++;
            }
        }
        if (swapCounter == 0)
        {
            printf("The Array Already Sorted, Thank you ");
            return _arr;
        }
    }

    return _arr;
}