#include <stdio.h>
#include <stdlib.h>


int findLargestIndex(int * array, int n)
{
    if (n <= 0)
    {
        return -1;
    }
    int largestIndex = 0;
    for (int i = 0; i <= n; i++)
    {
        if (array[i] > array[largestIndex])
        {
            largestIndex = i;
        }
    }
    return largestIndex;
}


int main(void)
{
    int array[7] = {3, 55, 23, 193, 4, 56, 3};
    int largestIndex = findLargestIndex(array, 7);
    printf("Largest index is %d\n.", largestIndex);
}
