
#include <stdio.h>

void bubbleSort(int vector[], const int size)
{
    int cache = 0;

    for (int counter = 0; counter < size; counter++)
        for (int c = 0; c < size - 1; c++)
        {
            if (vector[c] > vector[c + 1])
            {
                cache = vector[c];

                vector[c] = vector[c + 1];

                vector[c + 1] = cache;
            }
        }
}

int main()
{
    return 0;
}