#include <stdio.h>
#include <stddef.h>

#include "../include/array.h"


int main() {
	Array arr;
	array_init(&arr, sizeof(int));
	int n = 42;
	array_push(&arr, &n);
	//Deep Copy of Array's values make you able to do this
	n = 69;
	array_push(&arr, &n);

	int list[5] = { 1, 2, 3, 4, 5 };
	for (size_t i = 0; i < 5; i++) {
		array_push(&arr, &list[i]);
	}

	printf("Size of Array: %zu\n", arr.size);
	for (size_t i = 0; i < arr.size; i++) {
		int* n = array_at(&arr, i);
		printf("Element: %d\n", *n);
	}

	array_destroy(&arr);

	return 0;
}
