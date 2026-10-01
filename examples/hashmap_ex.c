#include <stdio.h>

#include "../include/hashmap.h"

int main() {
	HashMap map;
	hashmap_init(&map, sizeof(int));

	printf("Sizeof HashMap: %zu -- Capacity: %zu\n", map.size, map.capacity);

	hashmap_destroy(&map);

	return 0;
}
