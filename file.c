#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int write_array(const char *filename, const int *array, int size)
{
    if (filename == NULL || (array == NULL && size > 0) || size < 0)
    {
        return 0;
    }
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (fprintf(file, "%d ", array[i]) < 0)
        {
            fclose(file);
            return 0;
        }
    }
    if (fclose(file) != 0)
    {
        return 0;
    }
    return 1;
}
int *read_array(const char *filename, int *size)
{
    if (filename == NULL || size == NULL)
    {
        return NULL;
    }
    *size = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return NULL;
    }
    int capacity = 8;
    int count = 0;
    int *array = malloc(capacity * sizeof(int));
    if (array == NULL)
    {
        fclose(file);
        return NULL;
    }
    int value;
    while (fscanf(file, "%d", &value) == 1)
    {
        if (count == capacity)
        {
            capacity *= 2;
            int *temp = realloc(array, capacity * sizeof(int));
            if (temp == NULL)
            {
                free(array);
                fclose(file);
                return NULL;
            }
            array = temp;
        }
        array[count] = value;
        count++;
    }
    if (ferror(file) || !feof(file))
    {
        free(array);
        fclose(file);
        return NULL;
    }

    fclose(file);

    *size = count;

    return array;
}
