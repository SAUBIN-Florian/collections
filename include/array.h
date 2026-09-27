#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include <stddef.h>


typedef struct Array Array;

//Constructor, Destructor
Array array_init(size_t element_size);
void array_destroy(Array* ptr);

//Accessors, Mutators
void* array_at(Array* arr, int idx);
void array_push(Array* arr, void* element);
void array_pop(Array* arr);

#endif // DYN_ARRAY_H
