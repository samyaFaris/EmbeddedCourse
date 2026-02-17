#include <stdio.h>
#include"lut.h"

int main()
{
 // majority
    int majorityResult = majority(8);
    printf("majority(8) = %d\n", majorityResult);

    // bitMirror
    unsigned int value = 0b010101101;
    unsigned int mirrored = bitMirror(value);
    printf("bitMirror(0b010101101) = 0x%08X\n", mirrored);

    // bit_three_index
    unsigned int bits = 0b11000001;
    int thirdBit = bit_three_index(bits);
    printf("Index of 3rd set bit in 0b11000001 = %d\n", thirdBit);

    return 0;
}