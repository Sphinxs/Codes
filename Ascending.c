
#include <stdio.h>

#include <string.h>

void ascending(char *vt, int begin, int end)
{
    if (end >= begin)
    {
        printf("%c", vt[end]);

        ascending(vt, begin, end - 1);        
    }

    return;
}

int main()
{
    return 0;
}