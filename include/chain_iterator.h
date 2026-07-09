#ifndef CHAIN_ITERATOR_H_
#define CHAIN_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct chain_iterator_t ChainIterator;

bool ChainIteratorNext(void *state, void *out);
void ChainIteratorDestroy(void *state);
Iterator NewChainIterator(size_t inElemSize, Iterator innerA, Iterator innerB);

#endif