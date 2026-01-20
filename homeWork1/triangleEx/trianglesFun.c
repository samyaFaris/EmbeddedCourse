#include<stdio.h>



void firstFunction (char ch, int number)
{

  printf("The func1 will start now : \n");
    int i=0; 
    int j=0;
    for(i=1 ; i<=number;  i++)
    {
        while (j<i)
        {
            printf(" %s ", &ch);
            j++;
        }
        j=0;
        printf("\n");
    }

    return;
}

void secondFunction (char ch, int number)
{
    printf("The fun2 will start now: \n");
    int i=0; 
    int j=0;
    for(i=number ; i>=0;  i--)
    {
       
        while (j<i)
        {
            printf(" %s ", &ch);
            j++;
        }
        j=0;
        printf("\n");
    }

    return ; 
}

void thiredFunction (char ch, int number)
{

  printf("The func 3 will start now:  \n ");
    int i=0; 
    int j=0;
    for(i=1 ; i<=number;  i++)
    {
        while (j<i)
        {
            printf(" %s ", &ch);
            j++;
        }
        j=0;
        printf("\n");
    }
      j=0;
    for(i=number-1 ; i>=0;  i--)
    {
        while (j<i)
        {
            printf(" %s ", &ch);
            j++;
        }
        j=0;
        printf("\n");
    }

    return;
}

void fun4 (char ch, int number)
{

  printf("The firfourd function will start \n");
    int i=0; 
    int j=0;
    int index=0;
    for(i=1 ; i<=number;  i++)
    {
        index=number-i;
        while (index>0)
        {
            printf(" ");
            index --;
        }
        while (j<i)
        {
            printf(" %s ", &ch);
            j++;
        }
        j=0;
        printf("\n");
    }

    return;
}

void fun5 (char ch, int number)
{

  printf("The firfourd function will start \n");
    int i=0; 
    int j=0;
    int index=0;
    for(i=number ; i>0;  i--)
    {
       index = number-i;
        while (index>0)
        {
            printf(" ");
            index --;
        }
        while (j<i)
        {
            printf(" %s ", &ch);
            j++;
        }
        j=0;
        printf("\n");
    }

    return;
}

void fun6 (char ch, int number)
{

  printf("The 6 function will start \n");
    int i=0; 
    int j=0;
    int index=0;

        for(i=1 ; i<=number;  i++)
    {
        index=number-i;
        while (index>0)
        {
            printf(" ");
            index --;
        }
        while (j<i)
        {
            printf(" %s ", &ch);
            j++;
        }
        j=0;
        printf("\n");
    } 

    for(i=number-1 ; i>0;  i--)
    {
       index = number-i;
        while (index>0)
        {
            printf(" ");
            index --;
        }
        while (j<i)
        {
            printf(" %s ", &ch);
            j++;
        }
        j=0;
        printf("\n");
    }

    return;
}



// int main(void)
// {
//    firstFunction('*', 3);
//    secondFunction('*', 3);
//    thiredFunction('*', 3);
//    fun4('*', 5);
//    fun5('*', 5);
//  fun6('*', 5);

//    return 0; 
// }