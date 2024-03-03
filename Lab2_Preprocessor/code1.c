// This Project is Prepared by Ayman Mohamed Nabil - Section 2
#include <stdio.h>

#define GET_BIT(num,bit_index) (num & 1<<bit_index)!=0

int main()
{
    unsigned int x=0b01001100110011001100110011001100;
    int i; // ANSI C
    for(i=0;i<32;i++)
    {
        printf("bit index %d = %d\n",i,GET_BIT(x,i));
    }
}