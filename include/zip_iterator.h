#ifndef ZIP_ITERATOR_H_
#define ZIP_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct zip_iterator_t ZipIterator;

typedef struct zipped_item_t
{
    void *a;
    void *b;

} ZippedItem;

bool ZipIteratorNext(void *state, void *out);
void ZipIteratorDestroy(void *state);
Iterator NewZipIterator(size_t elemSizeA, Iterator innerA, size_t elemSizeB, Iterator innerB);

#endif