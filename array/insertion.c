#include<stdio.h>
int display_array(int array[],int usable_size)
{
    for(int i=0;i<usable_size;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
int insertion_in_array(int array[], int size, int index,int value)
{
    if(size>=100)
    {
        return -1;
    }
    for (int i=size-1;i>=index;i--)
    {
        array[i+1]=array[i];

    }
    array[index]=value;
}
int main()
{
    int array[100]={1,2,3,4,6,7};
    int usable_size=6;
    int value=5;
    int index=4;
    display_array(array,usable_size);
    insertion_in_array(array,usable_size,index,value);
    usable_size++;
    display_array(array,usable_size);

    
    return 0;
}