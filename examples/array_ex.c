#include <stdio.h>
#include <stddef.h>

#include "../include/array.h"


int main() {
	Array arr;
	array_init(&arr, sizeof(int));
	array_push(&arr, (int*)42);
	array_push(&arr, (int*)69);

	for (size_t i = 0; i < arr.size; i++) {
		printf("Element: %zu\n", array_at(&arr, i));
	}

	array_destroy(&arr);

	return 0;
}
