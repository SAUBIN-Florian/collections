#ifndef HASHMAP
#define HASHMAP

#include <stddef.h>

typedef struct {
	char* key;
	void* value;
	size_t value_size;
} Pair;

typedef struct {
	Pair** data;
	size_t size;
	size_t capacity;
} HashMap;

//Constructor, Destructor
void  hashmap_init(HashMap* map, size_t value_size);
void  hashmap_destroy(HashMap* map);

//Accessors, Mutators
void* hashmap_search(HashMap* map, const char* key);
void  hashmap_insert(HashMap* map, const char* key, void* value);
void  hashmap_delete(HashMap* map, const char* key);

#endif // HASHMAP
