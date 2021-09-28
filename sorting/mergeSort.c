#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void merge(int *array, int low, int mid, int high)
{
    int i, k, j;
    i = k = low;
    j = mid + 1;
    int bArray[99];

    while (i <= mid && j <= high)
    {
        if (array[i] > array[j])
        {
            bArray[k] = array[j];
            j++;
            k++;
        }
        else
        {
            bArray[k] = array[i];
            i++;
            k++;
        }
    }
    while (i <= mid)
    {
        bArray[k] = array[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        bArray[k] = array[j];
        j++;
        k++;
    }

    for (int i = 0; i <=high; i++)
    {
        array[i] = bArray[i];
    }
}
void mergeSort(int *array, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}
int main()
{
    int array[] = {2, 4, 3, 0, 4, 9, 5, 8, 1};
    int size = 9;
    printArray(array, size);
    int low = 0;
    int high = size-1;
    mergeSort(array, low, high);
    printArray(array, size);

    return 0;
}