#ifndef MAP_ITERATOR_H_
#define MAP_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct map_iterator_t MapIterator;

bool MapIteratorNext(void *restrict state, void *restrict out);
void MapIteratorDestroy(void *state);
Iterator NewMapIterator(size_t inElemSize, Iterator inner, void (*transform)(const void *restrict in, void *restrict out));

#endif