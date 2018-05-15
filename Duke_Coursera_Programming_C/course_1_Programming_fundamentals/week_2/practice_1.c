#include <stdio.h>


int f(int n)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < n/2)
        {
            ans -=i;
        }
        else
        {
            ans += i;
        }
    }
    return ans;
}


int main(void)
{
    int answer = f(7);
    printf("%i\n", answer);
}
