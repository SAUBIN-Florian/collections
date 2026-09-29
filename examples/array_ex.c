#include <stdio.h>
#include <stddef.h>

#include "../include/array.h"


int main() {
	Array arr;
	array_init(&arr, sizeof(int));
	int src[5] = { 1, 2, 3, 4, 5 };
	array_push_list(&arr, &src, 5);

	for (size_t i = 0; i < arr.size; i++) {
		int* n = array_at(&arr, i);
		printf("Element: %d\n", *n);
	}

	array_destroy(&arr);

	return 0;
}
