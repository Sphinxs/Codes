
#include <stdio.h>

void selectionSort(int vector[], const int size)
{
    int cache = 0;

    for (int counter = 0; counter < size - 1; counter++)
    {
        int min = counter;

        for (int c = counter + 1; c < size; c++)
        {
            if (vector[c] < vector[min])
                min = c;
        }

        if (min != counter)
        {
            cache = vector[counter];

            vector[counter] = vector[min];

            vector[min] = cache;
        }
    }
}

int main()
{
    return 0;
}