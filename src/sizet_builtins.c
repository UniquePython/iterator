#include "builtins.h"
#include "iterator.h"

#include <stdio.h>

bool SizeTEqual(const void *a, const void *b)
{
    return DEREF(const size_t, a) == DEREF(const size_t, b);
}

int SizeTCompare(const void *a, const void *b)
{
    size_t va = DEREF(const size_t, a);
    size_t vb = DEREF(const size_t, b);

    if (va < vb)
        return -1;
    if (va > vb)
        return 1;
    return 0;
}

void SizeTPrint(const void *elem)
{
    printf("%zu\n", DEREF(const size_t, elem));
}

bool SizeTIsZero(const void *elem)
{
    return DEREF(const size_t, elem) == 0;
}

bool SizeTIsEven(const void *elem)
{
    return DEREF(const size_t, elem) % 2 == 0;
}

bool SizeTIsOdd(const void *elem)
{
    return DEREF(const size_t, elem) % 2 != 0;
}

void SizeTIncrement(const void *restrict in, void *restrict out)
{
    DEREF(size_t, out) = DEREF(const size_t, in) + 1;
}
