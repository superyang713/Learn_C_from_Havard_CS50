#include <stdio.h>


int g(int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            x *= i + 1;
            continue;
        }
        x--;
        if (x == 0)
        {
            break;
        }
    }
    return x;
}


int main(void)
{
    int answer = g(1, 3);
    printf("%i\n", answer);
}
