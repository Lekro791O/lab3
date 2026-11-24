#include <stddef.h>
#include "sorting.h"

void bubble_sort(int *array, int size)
{
    if (array == NULL || size < 2) {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < size - 1 - i; j++){
            if(array[j]>array[j+1]){
                swapped = 1;
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j]= temp;
            }
        }
            if (swapped == 0)
            {
                break;
            }
        

    }
}