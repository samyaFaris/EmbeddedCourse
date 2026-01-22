#define OK 1
#define SIZE_ERROR 0
#define ARRAY_ERROR -1

/*
Descreption - print the value that occur the most in this array
Input - Array and Size of the arra (Size>0)
Output - OK or Error 
Error - SIZE_ERROR or ARRAY_ERROR 
*/
int Most_popular_num(int _arr[], int _size);
/*
Descreption -  Sort the array .
Input - Array and Size of the arra (Size>0)
Output - OK or Error 
Error - SIZE_ERROR or ARRAY_ERROR 
*/
int * Array_sort(int _arr[], int _size, int flag);
/*
Descreption - even numbers appear first followed by odd numbers, preserves the original order.
Input - Array and Size of the arra (Size>0)
Output - OK or Error 
Error - SIZE_ERROR or ARRAY_ERROR 
*/
int sort_even_odd_numbers(int _arr[], int _size);
/*
Descreption - zero numbers appear first followed by one numbers, preserves the original order.
Input - Array and Size of the arra (Size>0)
Output - OK or Error 
Error - SIZE_ERROR or ARRAY_ERROR 
*/
int sort_Zero_One(int _arr[], int _size);
