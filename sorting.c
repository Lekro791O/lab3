#include <stddef.h>
#include "sorting.h"

void bubble_sort(int *array, int size)
{
    if (array == NULL || size < 2)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swapped = 1;
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}
static void heapify(int *array, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && array[left] > array[largest])    
    {
        largest = left;
    }
    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}
void heap_sort(int *array, int size)
{
    if (array == NULL || size < 2)
    {
        return;
    }
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
    for (int i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}