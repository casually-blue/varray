#include<stdlib.h>

#include"varray.h"

struct varray_t {
  int length;
  int count;

  void** elements;
};

Varray varray_new(unsigned int initial_storage_length) {
  Varray v = malloc(sizeof(struct varray_t));

  if(!v)
    return NULL;

  v->elements = malloc(sizeof(void*) * initial_storage_length);

  if(!v->elements) {
    free(v);
    return NULL;
  }

  v->length = initial_storage_length;

  v->count = 0;

  return v;
}

Varray varray_delete(Varray v) {
  if(v) {
    if(v->elements)
      free(v->elements);
    free(v);
  }

  return NULL;
}

int varray_count(Varray v) {
  if(v)
    return v->count;
  else
    return 0;
}

void* varray_get(Varray v, unsigned int index) {
  if(v && index < v->count)
    return v->elements[index];
  else 
    return NULL;
}

int varray_append(Varray v, void *val) {
  if(!v)
    return -1;

  if(v->count + 1 >= v->length) 
  {
    v->length = (v->length + 1) * 2;
    v->length *= 2;
    v->elements = realloc(v->elements, v->length);
  }
  v->elements[(v->count)++] = val;

  return 0;
}
