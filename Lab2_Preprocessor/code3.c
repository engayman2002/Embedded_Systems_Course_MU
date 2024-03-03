// This Project is Prepared by Ayman Mohamed Nabil - Section 2
#include <stdio.h>

int main()
{
    int num,count=0;
    printf("Enter the number that you want to check = ");
    fflush(stdout);
    scanf("%d",&num);
    while(num!=0)
    {
        if(num&1)
        {
            count++;
        }
        num>>=1;
    }
    printf("no. of ones = %d",count);
}