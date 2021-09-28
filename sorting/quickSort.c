
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
int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (array[i] <= pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }
        if (i < j){
            temp = array[i];
        array[i] = array[j];
        array[j] = temp;}
    } while (i<j);
    temp = array[low];
    array[low] = array[j];
    array[j] = temp;
    return j;
}
void quickSort(int array[], int low, int high)
// void quickSort(int array[], int low, int high)

{
    int partitionIndex;
    if (low < high)
    {

        partitionIndex = partition(array, low, high);

        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}
int main()
{

    //int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3
    int array[] = {12, 54, 65, 7, 23, 9};
    // int size = sizeof(array) / sizeof(int);
    int size = 6;
    
    
    print_array(array, size);
    quickSort(array, 0, 5);
    print_array(array, size);

    return 0;
}