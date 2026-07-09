#ifndef EXAMPLES_HELPERS_H_
#define EXAMPLES_HELPERS_H_

#include "enumerate_iterator.h"
#include "zip_iterator.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

static inline void printInt(const void *elem)
{
    printf("%d\n", DEREF(const int, elem));
}

static inline void printI64(const void *elem)
{
    printf("%" PRId64 "\n", DEREF(const int64_t, elem));
}

static inline void printFloat(const void *elem)
{
    printf("%g\n", DEREF(const float, elem));
}

static inline void printChar(const void *elem)
{
    printf("%c\n", DEREF(char, elem));
}

static inline void printEnumeratedItem(const void *elem)
{
    const EnumeratedItem *item = (const EnumeratedItem *)elem;

    printf("idx=%zu, val=", (*item).index);
    printInt((*item).value);
}

static inline void printZippedItem(const void *elem)
{
    const ZippedItem *item = (const ZippedItem *)elem;

    printf("a=");
    printChar((*item).a);

    printf("b=");
    printFloat((*item).b);
}

static inline void doubleInt(const void *in, void *out)
{
    DEREF(int, out) = 2 * DEREF(const int, in);
}

static inline bool isEven(const void *elem)
{
    return DEREF(const int, elem) % 2 == 0;
}

static inline bool intEqual(const void *a, const void *b)
{
    return DEREF(const int, a) == DEREF(const int, b);
}

#endif
