#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "../include/array.h"


void array_init(Array* arr, size_t el_size) {
	*arr = (Array){
		.data = malloc(el_size * 2),
		.size = 0,
		.capacity = 2,
		.element_size = el_size
	};
}

void array_destroy(Array* arr) {
	free(arr->data);
	arr->data = NULL;
	arr->size = 0;
	arr->capacity = 0;
	arr->element_size = 0;
}

void* array_at(Array* arr, size_t idx) {
	assert(idx < arr->size);

	// void* arithmetic
	// typecast to char(1 byte) + idx * size of 1 element
	return (char*)arr->data + idx * arr->element_size;
}

void array_push(Array* arr, const void* element) {	
	if (arr->size >= arr->capacity) {
		size_t new_cap = arr->capacity * 2;
		void* tmp = realloc(arr->data, new_cap * arr->element_size);

		if (tmp != NULL) {
			arr->data = tmp;
			arr->capacity = new_cap;
		}
	}

	//void* arithmetic
	//same as the function array_at(...) for copying the right amount of bytes into arr->data
	void* dest = (char*)arr->data + arr->size * arr->element_size;
	memcpy(dest, element, arr->element_size);
	arr->size++;
}

void array_push_list(Array* arr, void* list, size_t list_size) {
	for (size_t i = 0; i < list_size; i++) {
		//TODO: finish this implementation
	}
}

void array_pop(Array* arr) {
	
}
