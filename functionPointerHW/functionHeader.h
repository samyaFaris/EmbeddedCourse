#ifndef SORT_H
#define SORT_H

typedef int (*SortCriteria)(int _first, int _second);


/*
Descreption - Sort the array acording to  specific Criteria 
Input - Array and Size of the arra (Size>0), function pointer 
Output - OK or Error 
Error - SIZE_ERROR or ARRAY_ERROR 
*/
int sort (int * arr, int size, SortCriteria c );

#endif