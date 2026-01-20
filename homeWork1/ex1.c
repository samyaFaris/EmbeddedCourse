#include<stdio.h>

int main(void)
{
    int num1;
    int num2;
    printf("Please Enter 2 numbers to start :");
    scanf("%d %d" , &num1 , &num2);
    printf(" The sum of the 2 numbers : %d \n", num1+num2 );
    printf(" The The difference between the 2 numbers : %d \n", num1-num2 );
    printf(" The multiply of the 2 numbers : %d \n", num1*num2 );

    return 0;
}