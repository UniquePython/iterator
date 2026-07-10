#include "builtins.h"
#include "iterator.h"

#include <inttypes.h>
#include <stdio.h>

bool I64Equal(const void *a, const void *b)
{
    return DEREF(const int64_t, a) == DEREF(const int64_t, b);
}

int I64Compare(const void *a, const void *b)
{
    int64_t va = DEREF(const int64_t, a);
    int64_t vb = DEREF(const int64_t, b);

    if (va < vb)
        return -1;
    if (va > vb)
        return 1;
    return 0;
}

void I64Print(const void *elem)
{
    printf("%" PRId64 "\n", DEREF(const int64_t, elem));
}

bool I64IsPositive(const void *elem)
{
    return DEREF(const int64_t, elem) > 0;
}

bool I64IsNegative(const void *elem)
{
    return DEREF(const int64_t, elem) < 0;
}

bool I64IsZero(const void *elem)
{
    return DEREF(const int64_t, elem) == 0;
}

bool I64IsEven(const void *elem)
{
    return DEREF(const int64_t, elem) % 2 == 0;
}

bool I64IsOdd(const void *elem)
{
    return DEREF(const int64_t, elem) % 2 != 0;
}

void I64Negate(const void *restrict in, void *restrict out)
{
    DEREF(int64_t, out) = -DEREF(const int64_t, in);
}

void I64Increment(const void *restrict in, void *restrict out)
{
    DEREF(int64_t, out) = DEREF(const int64_t, in) + 1;
}

void I64Decrement(const void *restrict in, void *restrict out)
{
    DEREF(int64_t, out) = DEREF(const int64_t, in) - 1;
}
