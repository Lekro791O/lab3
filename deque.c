
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include "deque.h"

Deque *create_deque(int initial_capacity)
{
    if (initial_capacity <= 0)
    {
        return NULL;
    }

    if ((size_t)initial_capacity > SIZE_MAX / sizeof(int))
    {
        return NULL;
    }

    Deque *deque = malloc(sizeof(Deque));
    if (deque == NULL)
    {
        return NULL;
    }

    deque->data = malloc((size_t)initial_capacity * sizeof(int));
    if (deque->data == NULL)
    {
        free(deque);
        return NULL;
    }

    deque->capacity = initial_capacity;
    deque->front = 0;
    deque->size = 0;

    return deque;
}

void free_deque(Deque *deque)
{
    if (deque == NULL)
    {
        return;
    }

    free(deque->data);
    free(deque);
}

int resize_deque(Deque *deque)
{
    if (deque == NULL)
    {
        return 0;
    }

    if (deque->capacity > INT_MAX / 2)
    {
        return 0;
    }

    int new_capacity = deque->capacity * 2;

    if ((size_t)new_capacity > SIZE_MAX / sizeof(int))
    {
        return 0;
    }

    int *new_data = malloc((size_t)new_capacity * sizeof(int));
    if (new_data == NULL)
    {
        return 0;
    }

    for (int i = 0; i < deque->size; i++)
    {
        size_t old = ((size_t)deque->front + (size_t)i) % (size_t)deque->capacity;   // почитать про формулу!!!
        new_data[i] = deque->data[old];
    }

    free(deque->data);

    deque->data = new_data;
    deque->capacity = new_capacity;
    deque->front = 0;

    return 1;
}

int push_back(Deque *deque, int value)
{
    if (deque == NULL)
    {
        return 0;
    }

    if (deque->size == deque->capacity)
    {
        if (!resize_deque(deque))
        {
            return 0;
        }
    }

    size_t index = ((size_t)deque->front + (size_t)deque->size)
                   % (size_t)deque->capacity;

    deque->data[index] = value;
    deque->size++;

    return 1;
}

int push_front(Deque *deque, int value)
{
    if (deque == NULL)
    {
        return 0;
    }

    if (deque->size == deque->capacity)
    {
        if (!resize_deque(deque))
        {
            return 0;
        }
    }

    if (deque->front == 0)
    {
        deque->front = deque->capacity - 1;
    }
    else
    {
        deque->front--;
    }

    deque->data[deque->front] = value;
    deque->size++;

    return 1;
}

int pop_front(Deque *deque)
{
    if (deque == NULL || deque->size == 0)
    {
        return 0;
    }

    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;

    return 1;
}

int pop_back(Deque *deque)
{
    if (deque == NULL || deque->size == 0)
    {
        return 0;
    }

    deque->size--;

    return 1;
}

int deque_to_array(const Deque *deque, int *array)
{
    if (deque == NULL || array == NULL)
    {
        return 0;
    }

    for (int i = 0; i < deque->size; i++)
    {
        size_t index = ((size_t)deque->front + (size_t)i) % (size_t)deque->capacity; // почитать про формулу!!!
        array[i] = deque->data[index];
    }

    return 1;
}
