#include <stdio.h>
int binary_search(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;//index mai 0 bhi aata hai na toa size ke liye -1 karna padega 
    while (low <= high)//agar low he high se jyada hoa jayega toa kaise he search karenge matlab aaray mai nahi hai vo number
    {
        int mid = (high + low) / 2;
        if (arr[mid]== element)
        {
            return mid;
        }
        if (element < arr[mid])
        {
            high = mid - 1;//mid-1 because mid par toa kuch mila he nahi tha usse ek piche se lena padega na
        }
        if (element > arr[mid])
        {
            low = mid + 1;//mid+1 vahi same mid par toa kuch mila he nhi tha na toa mid se 1 aage se dhundna padega na
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int element = 1;
    int searched = binary_search(arr, size, element);
    printf("The element %d is found on index %d\n", element, searched);
     element = 4;
     searched = binary_search(arr, size, element);
     printf("The element %d is found on index %d\n", element, searched);
     element = 6;
     searched = binary_search(arr, size, element);
     printf("The element %d is found on index %d\n", element, searched);
     element = 10;
     searched = binary_search(arr, size, element);
    printf("The element %d is found on index %d\n", element, searched);
    return 0;
}