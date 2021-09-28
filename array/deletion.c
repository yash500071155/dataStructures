#include<stdio.h>
int display_array(int array[],int usable_size)
{
    for(int i=0;i<usable_size;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
int deletion_in_array(int array[], int size, int index,int value)
{
    array[index]=0;
    for (int i=index;i<=size-1;i++)
    {
        array[i]=array[i+1];
    }
    
}
int main()
{
    int array[100]={1,2,3,9,4,5,6,7};
    int usable_size=8;
    int value=5;
    int index=3;
    int index2=4;
    display_array(array,usable_size);
    deletion_in_array(array,usable_size,index,value);
    usable_size--;
    // display_array(array,usable_size);
    // deletion_in_array(array,usable_size,index2,value);
    // usable_size--;
    display_array(array,usable_size);

    
    return 0;
}