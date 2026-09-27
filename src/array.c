#include <assert.h>
#include <cstddef>
#include <stdlib.h>

#include "../include/array.h"


struct Array {
	void* data;
	size_t size;
	size_t capacity;
	size_t element_size;
};

Array array_init(size_t el_size) {
	return (Array) {
		.data = malloc(el_size * 2),
		.size = 0,
		.capacity = 2,
		.element_size = el_size
	};
}

void array_free(Array* arr) {
	free(arr->data);
	arr->data = NULL;
	arr->size = 0;
	arr->capacity = 0;
	arr->element_size = 0;
}

void* array_at(Array* arr, size_t idx) {
	assert(idx >= 0 || idx <= arr->size);

	return &arr->data[idx];
}

void array_push(Array* arr, void* element) {	
	if (arr->size >= arr->capacity) {
		size_t new_cap = arr->capacity * 2;
		void* tmp = realloc(arr->data, new_cap);

		if (tmp != NULL) {
			arr->data = tmp;
			arr->capacity = new_cap;
		}
	}

	arr->data[arr->size] = element;
	arr->size += 1;
}

void array_pop(Array* arr) {
	
}
