
#include <stdio.h>

#include <string.h>

void descending(char *vt, int begin, int end)
{
    if (begin <= end)
    {
        descending(vt, begin + 1, end);

        printf("%c", vt[begin]);
    }

    return;
}

int main()
{
    return 0;
}