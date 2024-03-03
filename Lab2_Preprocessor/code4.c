// This Project is Prepared by Ayman Mohamed Nabil - Section 2
#include <stdio.h>

int main()
{
    printf("Enter your 8-bits number here (in Binary) : ");
    fflush(stdout);
    char s[9];
    gets(s);
    fflush(stdin);
    char *e=s;
    e+=8;
    while(s<=e)
    {
        printf("%c",*e);
        e--;
    }
}