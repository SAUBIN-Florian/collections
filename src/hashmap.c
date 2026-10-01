#include <stdlib.h>
#include <string.h>

#include "../include/hashmap.h"

static Pair* pair_init(const char* k, void* v, size_t v_size) {
	Pair* pair = (Pair*)malloc(sizeof(Pair) + v_size);
	
	size_t k_size = strlen(k);
	pair->key = malloc(k_size + 1);
	strcpy(pair->key, k);

	memcpy(pair->value, v, v_size);
	pair->value_size = v_size;

	return pair;
}

static void pair_destroy(Pair* pair) {
	free(pair->key);
	free(pair->value);
	pair->value_size = 0;
	free(pair);
}

static void hash() {
	//TODO: Hashing buckets will go here
}

// ---------- PUBLIC API ----------

void hashmap_init(HashMap* map, size_t value_size) {
	map->capacity = 4;
	map->size = 0;
	map->data = calloc(map->capacity, sizeof(Pair*));
}

void hashmap_destroy(HashMap* map) {
	for (size_t i = 0; i < map->size; i++) {
		Pair* curr_pair = map->data[i];
		if (curr_pair != NULL) {
			pair_destroy(curr_pair);
		}
	}

	free(map->data);
}


