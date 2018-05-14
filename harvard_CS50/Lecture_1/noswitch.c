#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Answer: ");

    if (c == 'Y')
    {
        printf("yes\n");
    }
    else if (c == 'N')
    {
        printf("no\n");
    }

}
