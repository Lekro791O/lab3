#ifndef FILE_H
#define FILE_H

int write_array(const char *filename, const int *array, int size);
int *read_array(const char *filename, int *size);

#endif