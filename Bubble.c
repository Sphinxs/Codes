
#include <stdio.h>

void bubbleSort(int *vt, const int size)
{
    int cache = 0;

    for (int i = 0; i < size; i++)
    {
        for (int h = i + 1; h < size; h++)
        {
            if (vt[i] > vt[h])
            {
                cache = vt[h];

                vt[h] = vt[i];

                vt[i] = cache;
            }
        }
    }
}

int main()
{
    return 0;
}