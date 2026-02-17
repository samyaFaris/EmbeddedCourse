#include <stdio.h>
#include "lut.h"

static int majority_arr[256];
static int flag = 0;
static int flag_mirror = 0;
static int flag_index = 0;
static int mirror_lut[256];
static int bites_count[256];
static int three_bites_indexes[256][3];

int count_bites(unsigned int n)
{
    int count = 0;
    while (n)
    {
        if (n & 1)
        {
            ++count;
        }
        n = n >> 1;
    }
    return count;
}
void build_majority_arr()
{

    for (int i = 0; i < 255; i++)
    {
        majority_arr[i] = count_bites(i);
    }
}

int reverse(unsigned int n)
{
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}

void build_mirror_lut()
{
    for (int i = 0; i < 256; i++)
    {
        mirror_lut[i] = reverse(i);
    }
}

int majority(unsigned int n)
{
    int count = 0;
    if (flag == 0)
    {
        build_majority_arr();
        flag = 1;
    }

    while (n)
    {
        count += majority_arr[n & 0xff];
        n = n >> 8;
    }
    if (count > ((sizeof(int) * 8) / 2))
    {
        return 1;
    }
    return 0;
}

unsigned int bitMirror(unsigned int n)
{
    int num_mirror;
    int result = 0;
    int num = sizeof(unsigned int);
    if (flag_mirror == 0)
    {
        build_mirror_lut();
        flag_mirror = 1;
    }
    while (num)
    {
        result <<= 8;
        result = result | mirror_lut[n & 0xff];
        n = n >> 8;
        num--;
    }
    return result;
}

int count_bites_index(unsigned int n)
{
    int i = 0;
    int num = n;
    int count = 0;
    while (n)
    {
        if (n & 1)
        {
            if (count < 3)
            {

                three_bites_indexes[num][count] = i;
            }
            ++count;
        }
        n = n >> 1;
        ++i;
    }
    return count;
}

void build_count_bits()
{
    for (int i = 0; i < 256; i++)
    {
        bites_count[i] = count_bites_index(i);
    }
}
unsigned int bit_three_index(unsigned int n)
{
    int numOfBites = 0;
    int itr = 1;
    if (flag_index == 0)
    {
        build_count_bits();
        flag_index = 1;
    }
    while (n)
    {
        if (numOfBites + bites_count[n & 0xff] >= 3)
        {
            if (numOfBites == 0)
            {
                return three_bites_indexes[n & 0xff][2];
            }
            else
            {
                return (three_bites_indexes[n & 0xff][3 - numOfBites - 1] + itr * 8);
            }
        }
        else
        {
            numOfBites += bites_count[n & 0xff];
        }
        n >>= 8;
        itr++;
    }
    return 0;
}

int main()
{
    // x = majority(8);
    unsigned int n = 010101101; /* 01110011 */
    unsigned int y = 0b11000001;
    int x = bit_three_index(y);
    printf("%d", x);
    // printf("mirror = 0x%08X\n", bitMirror(n));
}
