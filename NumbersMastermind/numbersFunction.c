#include <stdio.h>
#include <time.h>
#include <stdlib.h>   // rand, srand

#define DIGITS_ERROR -1;
#define OK 1;

int validate_num_digits(int num)
{
    int count = 0;
    while (num)
    {
        ++count;
        num /= 10;
    }
    if (count != 4)
    {
        printf("Number should be with 4 digits, Please try again.");
        return DIGITS_ERROR;
    }
    return OK;
}

int checkNumLen(int num)
{
    int digCounter = 0;
    while (num > 0)
    {
        num = num / 10;
        digCounter++;
    }
    return digCounter;
}


int get_random_number()
{
    int digits_arr[4];
    int i, j, digit, exists;
    int index = 1000;
    int returnNum = 0;

    for (i = 0; i < 4; i++)
    {
        do
        {
            digit = rand() % 10; 
            exists = 0;

            for (j = 0; j < i; j++)
            {
                if (digits_arr[j] == digit)
                {
                    exists = 1;
                    break;
                }
            }

        } while (exists);

        digits_arr[i] = digit;
    }
    for (int i = 0; i < 4; i++)
    {
        returnNum+=index*digits_arr[i];
        index/=10;

    }
    return returnNum;
}

int base_check_num(int base, int check)
{

    int samePlaceCount = 0;
    int notSamePlaceCount = 0;
    int checkCopy = 0;
    int baseLen = checkNumLen(check);
    int checkLen = checkNumLen(check);
    int returnNum = 0;

    for (int i = 0; i < baseLen; ++i)
    {
        checkCopy = check;
        for (int j = 0; j < checkLen; ++j)
        {
            if (base % 10 == checkCopy % 10)
            {
                if (i == j)
                {
                    samePlaceCount++;
                }
                else
                {
                    notSamePlaceCount++;
                }
            }
            checkCopy /= 10;
        }
        base /= 10;
    }
    returnNum = samePlaceCount * 10 + notSamePlaceCount;
    if (!returnNum)
    {
        return -1;
    }
    return returnNum;
}





void main()
{
    srand(time(NULL));
    int ComputerNum=get_random_number();
    int playerNum;
    int result=0;
    printf("Please Enter Number With 4 Digits: ");
    while(!result)
    {
            printf("Enter a 4-digit number: ");
            scanf("%d", &playerNum);
            printf("%d \n", ComputerNum);
            printf("%d \n", playerNum);

            //base_check_num(ComputerNum, playerNum);


    }
    
}