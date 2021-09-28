#include<stdio.h>
int linear_search(int arr[],int size, int element)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
       
    }
    return -1;
}
int main()
{
    int arr[]={10,24,161,15,34,65,37,78,345,455,56,36,92};
    int size=sizeof(arr)/sizeof(int);
    int element=345;
    int searched=linear_search(arr,size,element);
    printf("The element %d is found on index %d\n",element,searched);
    return 0;
}