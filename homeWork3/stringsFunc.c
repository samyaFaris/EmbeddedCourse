#include <stdio.h>
#include<string.h>
#include "StringsHeader.h"

int validate_int(int value)
{
if (value ==0 )
{
    return NUMBER_ERROR;
}
return OK;
}
int validate_int_ptr(int *ptr)
{
if (ptr == NULL )
{
    return POINTER_ERROR;
}
return OK;
}
int validate_string(char *str)
{
if (str == NULL)
{
    return POINTER_ERROR;
}
return OK;

}
int validate_string_ofNumbers(char *str)
{
    while (*str != '\0' )
    {
        if(*str < 48 || *str > 57)
        {
            return CHAR_NUMBER_ERROR;
        }
    str++;
    }
    return OK;
}
int Swap_function(char *str1, char *str2)
{
    char swap= *str1;
    *str1=*str2;
    *str2=swap;
    return 1;
}

int calculateDigitValue(int dig, int value)
{

    int num=value;
    for (int i=0; i<dig; i++)
    {
        num*=10;
        
    }
    return num;
}

int checkNumLen(int num)
{
    int digCounter=0;
    while(num>0)
    {
        num=num/10;
        digCounter++;
    }
    return digCounter;
}

int ReverseStr( char * _str)
{
    if ( validate_string(_str) == 0)
    {
        return 0;
    }
    int strLen= strlen(_str);
    int i=0;
    int j=strLen -1;
    if (strLen % 2 ==0 )
    {
        while ( i+1 != j)
        {
         Swap_function(&_str[i], &_str[j]);
         i++;
         j--;
        }
    }
    if (strLen % 2 ==1 )
    {
        while (i != j)
        {
         Swap_function(&_str[i], &_str[j]);
         i++;
         j--; 
        }
    }

}

int IsPalindrome( char *_str) 
{
    if ( validate_string(_str) == 0)
    {
        return 0;
    }
    int strLen= strlen(_str);
    int i=0;
    int j=strLen -1;
    if (strLen % 2 ==0 )
    {
        while ( i+1 != j && _str[i] == _str[j])
        {
         i++;
         j--;
        }
        if(_str[i] == _str[j])
        {
            printf("The String is IsPalindrome: %s", _str);
            return 1;
        }
    }
    if (strLen % 2 ==1 )
    {
        while (i != j && _str[i] == _str[j])
        {
         i++;
         j--; 
        }
        if(_str[i] == _str[j] )
        {
            printf("The String is IsPalindrome: %s", _str);
            return 1;

        }
    }
            printf("The String is not IsPalindrome: %s", _str);

   
}

int MyAToI( char *_str, int *_num)
{
    if ( validate_string(_str) == 0)
    {
        return 0;
    }
    if(validate_int_ptr(_num) == 0)
    {
        return 0;
    }
    int lenStr=strlen(_str);
    int j=lenStr-1;
    int digCounter=0;
    int value=0;
    int totalNum=0;
    int digitValue=0;
    while(j>=0)
    {
        value=_str[j]-48;
        digitValue=value*calculateDigitValue(digCounter, value);
        j--;
        digCounter++;
        totalNum+=digitValue;

    }
   *_num=totalNum;
}


int MyIToA( int _num, char *_buffer) 
{
    if ( validate_string(_buffer) == 0)
    {
        return POINTER_ERROR;
    }
    if (validate_int(_num) < 0)
    {
        return NUMBER_ERROR;
    }
    if( validate_string_ofNumbers(_buffer) < 0)
    {
        return CHAR_NUMBER_ERROR;
    }
    int j=0;
    int dig=0;
    if(_num<0)
    {
        _buffer[0]='-';
        j++;
        _num=_num*-1;
       
    }
    int numberLen=checkNumLen(_num);
    j+=numberLen;
    _buffer[j]='\0';
    j--;
    while(_num>0)
    {
       dig=_num%10; 
       _buffer[j]=dig+48;
       j--;
       _num=_num/10;
    }

}


// void main( )
// {
// char str1[ ]="aaaaaaa";
// char str2 [ ]= "345";
// char str3[12];
// int myItoANum=-6789;
// int StrtoInt=0;
//     //ReverseStr(str1);
//     //IsPalindrome(str1);
//     //MyAToI(str2,&StrtoInt);
//     //MyIToA(myItoANum, str3);   
// }