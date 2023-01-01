#include <stdio.h>
#define SIZE 50
void shift_element(int* arr, int i)
{
    int tmp = *(arr + i);
for(int j = 0 ; j < i ; j++)
{
    *(arr + i - j) = *(arr + i - j - 1);
}
*(arr) = tmp;
}
void insertion_sort(int* arr , int len)
{
    int k,j;
for (int i = 1; i < len; i++)
{
    int count=0;
     k = *(arr+i);
     j = i-1;
    while (j >= 0 && *(arr+j) > k)
    {
        // *(arr + j + 1) = *(arr + j);
        j -= 1;
        count++;
    }
    // if (j<0)
    // {
    //     j=0;
    // }
    shift_element((arr+j+1), count);     
}
}
void printarr(int* arr,int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i==(len-1))
        {
           printf("%d",*(arr+i));
        }
        else
        {
           printf("%d,",*(arr+i)); 
        }        
    }   
}
int main()
{
    // int arr[10]={10,9,2,11,4,31,7,8,3,6};
    // insertion_sort(arr,10);
    // for(int j=0 ; j<10;j++)
    // {
    //     printf("%d,",arr[j]);
    // }
    int arr [SIZE] = {0};
    for(int i = 0; i<SIZE; i++)
    {
        scanf("%d", (arr+i));
    }
    insertion_sort(arr,SIZE);
    printarr(arr,SIZE);
return 0;
}
