#ifndef DEQUE_H
#define DEQUE_H

typedef struct {
    int *data;
    int capacity;
    int front;
    int size;
} Deque;
Deque *create_deque(int initial_capacity);
void free_deque(Deque *deque);
int resize_deque(Deque *deque);
int push_back(Deque *deque, int value);
int push_front(Deque *deque, int value);
int pop_front(Deque *deque);
int pop_back(Deque *deque);
int deque_to_array(const Deque *deque, int *array);
#endif