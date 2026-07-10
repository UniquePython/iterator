#ifndef EXAMPLES_HELPERS_H_
#define EXAMPLES_HELPERS_H_

#include "builtins.h"
#include "enumerate_iterator.h"
#include "zip_iterator.h"
#include "iterator.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

static inline void printEnumeratedItem(const void *elem)
{
    const EnumeratedItem *item = (const EnumeratedItem *)elem;

    printf("idx=%zu, val=", (*item).index);
    IntPrint((*item).value);
}

static inline void printZippedItem(const void *elem)
{
    const ZippedItem *item = (const ZippedItem *)elem;

    printf("a=");
    CharPrint((*item).a);

    printf("b=");
    FloatPrint((*item).b);
}

static inline void doubleInt(const void *in, void *out)
{
    DEREF(int, out) = 2 * DEREF(const int, in);
}

static inline void sumCombine(const void *restrict elem, void *restrict acc)
{
    DEREF(int, acc) += DEREF(const int, elem);
}

static inline void countEvenCombine(const void *restrict elem, void *restrict acc)
{
    if (IntIsEven(elem))
        DEREF(size_t, acc) += 1;
}

#endif
