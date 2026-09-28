#include <stdio.h>
#include <stddef.h>

#include "../include/array.h"


int main() {
	Array arr;
	array_init(&arr, sizeof(int));

	int n1 = 42;
	int n2 = 69;
	int n3 = 102;
	array_push(&arr, &n1);
	array_push(&arr, &n2);
	array_push(&arr, &n3);

	for (size_t i = 0; i < arr.size; i++) {
		int* n = array_at(&arr, i);
		printf("Element: %d\n", *n);
	}

	array_destroy(&arr);

	return 0;
}
