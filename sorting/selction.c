
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
void insertionSort(int *array, int size)
{
    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12
    int temp, minIndex;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}
int main()
{
    //DRY RUN
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    int array[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(array) / sizeof(int);
    print_array(array, size);
    selectionSort(array, size);
    print_array(array, size);

    return 0;
}