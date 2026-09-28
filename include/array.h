#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>


typedef struct {
	void* data;
	size_t size;
	size_t capacity;
	size_t element_size;
} Array;

//Constructor, Destructor
void array_init(Array* arr, size_t element_size);
void array_destroy(Array* ptr);

//Accessors, Mutators
void* array_at(Array* arr, size_t idx);
void array_push(Array* arr, const void* element);
void array_pop(Array* arr);

#endif // ARRAY_H
