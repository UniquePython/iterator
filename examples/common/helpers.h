#ifndef EXAMPLES_HELPERS_H_
#define EXAMPLES_HELPERS_H_

#include "enumerate_iterator.h"
#include "zip_iterator.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

static inline void printInt(void *elem)
{
    printf("%d\n", *(int *)elem);
}

static inline void printI64(void *elem)
{
    printf("%" PRId64 "\n", *(int64_t *)elem);
}

static inline void printFloat(void *elem)
{
    printf("%g\n", *(float *)elem);
}

static inline void printChar(void *elem)
{
    printf("%c\n", *(char *)elem);
}

static inline void printEnumeratedItem(void *elem)
{
    EnumeratedItem *item = (EnumeratedItem *)elem;

    printf("idx=%zu, val=", (*item).index);
    printInt((*item).value);
}

static inline void printZippedItem(void *elem)
{
    ZippedItem *item = (ZippedItem *)elem;

    printf("a=");
    printChar((*item).a);

    printf("b=");
    printFloat((*item).b);
}

static inline void doubleInt(void *in, void *out)
{
    *(int *)out = 2 * (*(int *)in);
}

static inline bool isEven(void *elem)
{
    return (*(int *)elem) % 2 == 0;
}

static inline bool intEqual(const void *a, const void *b)
{
    return *(int *)a == *(int *)b;
}

#endif
