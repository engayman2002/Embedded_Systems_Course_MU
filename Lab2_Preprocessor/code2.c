// This Project is Prepared by Ayman Mohamed Nabil - Section 2
#include <stdio.h>

#define array_sum(variable_name,array_name,lenght);  typeof(array_name[0]) variable_name=0;\
int i=0;\
while(i!=lenght)\
{variable_name+=array_name[i];\
i++;\
}\
\

int main()
{
    int arr[]={1,2,3,4};
    array_sum(sum,arr,sizeof(arr)/sizeof(arr[0]));
    printf("Sum of arr = %d",sum);
}