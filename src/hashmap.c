#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "../include/hashmap.h"

#define HASH_SEED_1 1
#define HASH_SEED_2 2

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

static uint64_t hash(const char* s, uint64_t seed) {
	// SRC: https://en.wikipedia.org/wiki/Horner%27s_method
	int horner_form = 31;
	uint64_t hash = seed;

	for (; *s; ++s) {
		hash = hash * horner_form + (unsigned char)*s;
	}

	// NOTE: Don't forget to modulo this output with the capacity of the map...
	return hash;
}

static int get_hash() {
	// SRC: https://en.wikipedia.org/wiki/Double_hashing
	//TODO: implement this mathematical mess...
	
}

// ---------- PUBLIC API ----------

void hashmap_init(HashMap* map, size_t value_size) {
	map->capacity = 8;
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


