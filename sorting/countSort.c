#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int maxElement(int *array)
{
    int max=0;
    for(int i=0;i<9;i++)
    {
        //2, 4, 3, 0, 4, 9, 5, 8, 1
        if(array[i]>array[i+1])
        {

            if(array[i]>max)max=array[i];
        }

    }
    return max;
}
int countSort(int *array,int size)
{
    int i,j;
    i=j=0;
    int max=maxElement(array);
    int *array2=(int *)malloc(max*sizeof(int));
    for(int i=0;i<max+1;i++)
    {
        array2[i]=0;
    }
    while(i<size)
    {
        array2[array[i]]++;
        i++;
    }
    i=0;
    j=0;
    while(j<=max)
    {
        if(array2[j]>0)
        {
            array[i]=j;
            array2[j]--;
            i++;


        }
        else{
            j++;

        }
    }
   
}
int main()
{
    int array[] = {2, 4, 3, 0, 14, 9, 5, 8, 1};
    int size=9;
    printArray(array, size);
    countSort(array,size);
    printArray(array, size);
    return 0;
}