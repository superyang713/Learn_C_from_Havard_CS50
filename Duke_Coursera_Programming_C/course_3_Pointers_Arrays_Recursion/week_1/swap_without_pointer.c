#include <stdio.h>
#include <stdlib.h>


int swap(int x, int y);
int main(void)
{
    int a = 5;
    int b = 8;
    swap(a, b);
    printf("value a: %d, value b: %d\n", a, b);
    return EXIT_SUCCESS;
}

int swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}
