
#include <stdio.h>

void ascendingRecursive(char *vt, int begin, int end)
{
    if (end >= begin)
    {
        printf("%c", vt[end]);

        ascending(vt, begin, end - 1);
    }

    return;
}

void descendingRecursive(char *vt, int begin, int end)
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