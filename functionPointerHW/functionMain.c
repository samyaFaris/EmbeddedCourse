#include<stdio.h>
#include"functionHeader.h"

int Down(int _first, int _second)
{
    return(_first<_second) ? 1 : 0;

}


int up(int _first, int _second)
{
    return(_first>_second) ? 1 : 0;
    

}


int sum_dig(int _first, int _second)
{
    int sum1=0;
    int sum2=0;
    while(_first)
    {
        sum1+=sum1%10;
        _first/=10;
    }
        while(_second)
    {
        sum2+=sum2%10;
        _first/=10;
    }
    
    if(sum1>sum2)
    {
        return 1;
    }
    else return 0;
}

int rightDigits(int _first, int _second)
{
    int d1=_first%10;
    int d2=_second%10;
    if(d1>d2)
    {
        return 1;
    }

return 0;
}

int main()
{
    int arr[]={2,4,6,7,10,15,39};
    sort(arr,7,up);
    sort(arr,7,Down); 
    sort(arr,7,sum_dig); 
    sort(arr,7,rightDigits); 
}