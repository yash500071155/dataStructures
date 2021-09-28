#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void insertionSort(int *array,int size)
{
    int key;
    int j;
    for(int i=1;i<= size-1;i++)
    {
        key=array[i];
        j=i-1;
        while(j>=0 && array[j] >key)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;//last mai jo key mai value stire kari hai usse put karna hoga na

    }

}
int main()
{
    //DRY RUN FOR INSERTION SORT

   //  -1   0    1   2   3   4   5
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   int array[]={12,54,65,7,23,9};
   int size = sizeof(array) / sizeof(int);
   print_array(array,size);
   insertionSort(array,size);
   print_array(array,size);

    return 0;
}