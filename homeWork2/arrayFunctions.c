#include<stdio.h> 
#include "arrayHeader.h"

int check_inputs( int _arr [], int _size)
{
    printf("Input validation Start \n");
    if (_size<=0)
    {
       printf("ERROR, The Size should be 1 or more");
       return SIZE_ERROR;
    }

   printf("Input validation successful \n");
   return OK;
}


int Swap_function(int *num1, int *num2)
{
    int swap=0;
    swap=*num1;
    *num1=*num2;
    *num2=swap;
    return 1;
}

int print_Array(int _arr[], int _size)
{

    for(int i=0; i<_size; i++)
    {
        printf(" %d ", _arr[i]);
    }
printf("\n");
}

int * Array_sort(int _arr[], int _size, int flag)
{
    if (flag==1)
    {
        printf("Start To Sort The Array : ");
        print_Array(_arr, _size);
        check_inputs(_arr,+_size);
    }
    int swapCounter=0;
for (int i=0 ; i < _size; i++)
   {
    for (int j=0; j<_size-1; j++)
    {
        
        if (_arr[j] > _arr[j+1])
        {
          Swap_function( &_arr[j], &_arr[j+1] );
          swapCounter++;
        }
    }
    if (swapCounter == 0)
    {
        printf("The Array Already Sorted, Thank you ");
        return _arr;
    }
   }
    if (flag == 1)
    {
    printf("The Sorted Array is :");
    print_Array(_arr, _size);
    }

   return _arr; 
}

int Most_popular_num(int _arr[], int _size)
{

    int result =check_inputs(_arr,_size);
    if (result<= 0)
    {
        return result;
    }
    printf("Start to check most popular number in array:  ");
    print_Array(_arr, _size);
    int * sortedArrayFunction= Array_sort( _arr, _size, 0);
    int currentNumCounter =0;
    int maxNumberCounter=0;
    int maxNumber =0;
    int i=0;
   for (int i=0; i<_size-1; i++)
   {
    if(sortedArrayFunction[i] != sortedArrayFunction[i+1])
    {
        if(currentNumCounter > maxNumberCounter)
        {
            maxNumberCounter= currentNumCounter;
            maxNumber=sortedArrayFunction[i];
            currentNumCounter =1;

        }

    }
    else if (sortedArrayFunction[i] == sortedArrayFunction[i+1])
    {
        currentNumCounter++;

    }
   }
   if(currentNumCounter>maxNumberCounter)
        {
            maxNumber=sortedArrayFunction[_size-1];

        }

     printf("The most popular number is : %d \n", maxNumber);

     
}


int sort_even_odd_numbers(int _arr[], int _size)
{
    
     printf("Start to sort even odd number in array:  ");
     print_Array(_arr, _size);
    int result =check_inputs(_arr, _size);
    if (result<= 0)
    {
        return result;
    }
    int i=0;
    int j=_size-1;
    int evenCounter=0;
    while(i<j)
    { 
        if(_arr[i]%2==1 && _arr[j]%2==0)
        {
            Swap_function(&_arr[i], &_arr[j]);
            evenCounter++;
        }
        else if (_arr[i]%2==1 && _arr[j]%2==1)
        {
            j--;
        }
        else if (_arr[i]%2==0 && _arr[j]%2==0)
        {
            i++;
            evenCounter++;
        }
        else
        {
            i++;
            j--;
        }
    }
    printf("The even odd sorted array ");
    print_Array(_arr, 8);
    printf("The even Number is %d \n" , evenCounter);

    
}

int sort_Zero_One(int _arr[], int _size)
{
    
     printf("Start to sort zero and one in array:  ");
     print_Array(_arr, _size);
    int result =check_inputs(_arr,+_size);
    if (result<= 0)
    {
        return result;
    }
    int i=0;
    int j=_size-1;
    while(i<j)
    { 
        if(_arr[i]==1 && _arr[j]==0)
        {
            Swap_function(&_arr[i], &_arr[j]);
        }
        else if (_arr[i]==1 && _arr[j]==1)
        {
            j--;
        }
        else if (_arr[i]==0 && _arr[j]==0)
        {
            i++;
        }
        else
        {
            i++;
            j--;
        }
    }
    printf("The Zero One Array : ");
    print_Array(_arr, 8);
    
     
}
