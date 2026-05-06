#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

typedef struct DynArray DynArray;

//Constructor, Destructor
DynArray* dyn_arr_new();
void dyn_arr_free(DynArray* ptr);

//Accessors, Mutators
void* dyn_arr_at(int idx);

void dyn_arr_push(void* element);
void dyn_arr_pop();

#endif // DYN_ARRAY_H
