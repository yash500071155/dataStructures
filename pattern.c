#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    
    scanf("%d", &n);
    int size = 2 * n - 1;
    int s = 0;

    int e = size - 1;
    int array[size][size];
    while (n != 0)
    {
        for (int i = s; i <= e; i++) //row
        {
            for (int j = s; j <= e; j++) //column
            {
                if (i == s || j == e || i == e || j == s)
                {
                    array[i][j] = n;
                }
            }
        }
        n--;
        s++;
        e--;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
