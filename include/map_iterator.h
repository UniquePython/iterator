#ifndef MAP_ITERATOR_H_
#define MAP_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct map_iterator_t MapIterator;

bool MapIteratorNext(void *state, void *out);
void MapIteratorDestroy(void *state);
Iterator newMapIterator(size_t inElemSize, Iterator inner, void (*transform)(void *, void *));

#endif