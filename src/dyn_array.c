#include <assert.h>
#include <stdlib.h>

#include "../include/dyn_array.h"


struct DynArray {
	void* data;
	size_t size;
	size_t capacity;
	size_t element_size;
};

DynArray dyn_array_init(size_t sizeof_element) {
	return (DynArray) {
		.data = malloc(sizeof_element * 2),
		.size = 0,
		.capacity = 2,
		.element_size = sizeof_element
	};
}

void dyn_arr_free(DynArray* da) {
	free(da->data);
	da->data = NULL;
	da->size = 0;
	da->capacity = 0;
	da->element_size = 0;
}

void* dyn_array_at(DynArray* da, size_t idx) {
	assert(idx >= 0 || idx <= da->size);

	return &da->data[idx];
}

void dyn_arr_push(DynArray* da, void* element) {	
	
}

void dyn_arr_pop(DynArray* da) {
	
}
