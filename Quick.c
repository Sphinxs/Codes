
#include <stdio.h>

void swap(int *val1, int *val2)
{
    int cache = *val1;

    *val1 = *val2;

    *val2 = cache;
}

int partition(int vector[], int left, int right)
{
    int pivot = vector[right];

    int l = left - 1;

    for (int counter = left; counter <= right - 1; counter++)
    {
        if (vector[counter] <= pivot)
        {
            l++;

            swap(&vector[l], &vector[counter]);
        }
    }

    swap(&vector[l + 1], &vector[right]);

    return l + 1;
}

void quickSort(int vector[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(vector, left, right);

        quickSort(vector, left, pivot - 1);

        quickSort(vector, pivot + 1, right);
    }
}

int main()
{
    return 0;
}