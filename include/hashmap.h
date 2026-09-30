#ifndef HASHMAP
#define HASHMAP

#include <stddef.h>


typedef struct {
	
} HashMap;

//Constructor, Destructor
void  hashmap_init(HashMap* map);
void  hashmap_destroy(HashMap* map);

//Accessors, Mutators
void* hashmap_search(HashMap* map, const char* key);
void  hashmap_insert(HashMap* map, const char* key, void* value);
void  hashmap_delete(HashMap* map, const char* key);

#endif // HASHMAP
