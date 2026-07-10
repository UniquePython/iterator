#include "builtins.h"
#include "iterator.h"

#include <math.h>
#include <stdio.h>

bool FloatEqual(const void *a, const void *b)
{
    float va = DEREF(const float, a);
    float vb = DEREF(const float, b);

    return fabsf(va - vb) <= ITERATOR_FLOAT_EPSILON;
}

int FloatCompare(const void *a, const void *b)
{
    float va = DEREF(const float, a);
    float vb = DEREF(const float, b);

    if (FloatEqual(a, b))
        return 0;
    if (va < vb)
        return -1;
    return 1;
}

void FloatPrint(const void *elem)
{
    printf("%g\n", DEREF(const float, elem));
}

bool FloatIsPositive(const void *elem)
{
    return DEREF(const float, elem) > 0.0f;
}

bool FloatIsNegative(const void *elem)
{
    return DEREF(const float, elem) < 0.0f;
}

bool FloatIsZero(const void *elem)
{
    return fabsf(DEREF(const float, elem)) <= ITERATOR_FLOAT_EPSILON;
}

void FloatNegate(const void *restrict in, void *restrict out)
{
    DEREF(float, out) = -DEREF(const float, in);
}

void FloatIncrement(const void *restrict in, void *restrict out)
{
    DEREF(float, out) = DEREF(const float, in) + 1.0f;
}

void FloatDecrement(const void *restrict in, void *restrict out)
{
    DEREF(float, out) = DEREF(const float, in) - 1.0f;
}
