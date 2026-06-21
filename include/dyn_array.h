#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include <stddef.h>


typedef struct DynArray DynArray;

//Constructor, Destructor
DynArray dyn_arr_init(size_t element_size);
void dyn_arr_destroy(DynArray* ptr);

//Accessors, Mutators
void* dyn_arr_at(DynArray* da, int idx);
void dyn_arr_push(DynArray* da, void* element);
void dyn_arr_pop(DynArray* da);

#endif // DYN_ARRAY_H
