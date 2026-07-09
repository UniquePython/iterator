#ifndef STRING_ITERATOR_H_
#define STRING_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>

typedef struct string_iterator_t StringIterator;

bool StringIteratorNext(void *state, void *out);
void StringIteratorDestroy(void *state);
Iterator NewStringIterator(const char *string);

#endif