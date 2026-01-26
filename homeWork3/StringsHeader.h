#define OK 1
#define NUMBER_ERROR -1
#define POINTER_ERROR -2
#define CHAR_NUMBER_ERROR -3


/*
Descreption - Reverses the characters of the input string.
Input - Pointer to the array of characters
Output - OK or Error 
Error - POINTER_ERROR  
*/
int ReverseStr( char * _str);

/*
Descreption - Check if the string is palindrome.
Input - Pointer to the array of characters
Output - OK or Error 
Error - POINTER_ERROR  
*/
int IsPalindrome( char *_str);

/*
Descreption - Convert  String to Int Number.
Input - Pointer to the array of characters, Pointer to the Number.
Output - OK or Error 
Error - POINTER_ERROR   
*/
int MyAToI( char *_str, int *_num);
/*
Descreption - Convert Int Number to String.
Input - Pointer to the array of characters, Pointer to the Number.
Output - OK or Error 
Error - POINTER_ERROR   
*/
int MyIToA( int _num, char *_buffer);
