#include<stdio.h>
#include"StringsHeader.h"




void main( )
{
char strToRevers[ ]="Samya";
char strIsPalindrome[ ]="WeoeW";
char strToInt[ ]="1234";
char intToStr[12];
int myItoANum=-6789;
int StrtoIntNum=0;

    ReverseStr(strToRevers);
    IsPalindrome(strIsPalindrome);
    MyAToI(StrtoIntNum,&StrtoInt);
    MyIToA(myItoANum, intToStr); 
}