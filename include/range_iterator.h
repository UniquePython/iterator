#ifndef RANGE_ITERATOR_H_
#define RANGE_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct range_iterator_t RangeIterator;

bool RangeIteratorNext(void *restrict state, void *restrict out);
void RangeIteratorDestroy(void *state);
Iterator NewRangeIterator(int64_t start, int64_t stop, int64_t step, bool inclusive);

#endif