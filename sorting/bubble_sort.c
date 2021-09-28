#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void bubbleSort(int *array, int size)
{
    int temp;
    int isSorted = 0;// to make our bubble sort adaptable (is the array is sorted of else array is sort in middle of passes our fuction cannot check for further and return our sorted array in O(N) time otherwise it takes O(N^2) time.)
    for (int i = 0; i < size - 1; i++) //passes
    {
        printf("Number of passesd is %d \n", i + 1);
        isSorted = 1;

        for (int j = 0; j < size - 1 - i; j++) //comparision
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}
int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9};
    // int array[] = {2, 1, 98, 5, 3, 7, 4, 6, 45, 889, 33};
    int size = sizeof(array) / sizeof(int);
    printf("size : %d\n", size);
    print_array(array, size); //before shorting
    bubbleSort(array, size);
    print_array(array, size); //after shorting

    return 0;
}