#include<stdio.h> 
#include "arrayHeader.h"

void main( )
{

     int mostPopularNumber[]={4,5,6,7,2,2,4,5,4,4,4};
     int numbersTosort[]={5,6,7,3,2,9,1,4};
     int zeroOneArray[]= {0,1,1,0,1,0,0,1};
     int evenOddArray[]= {4,1,3,8,12,5,4,1};
     Most_popular_num(mostPopularNumber, 11);
     Array_sort(numbersTosort, 8, 1);
     sort_Zero_One(zeroOneArray, 8);
     sort_even_odd_numbers(evenOddArray, 8);
   

}