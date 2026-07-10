#include "builtins.h"
#include "iterator.h"

#include <math.h>
#include <stdio.h>

bool DblEqual(const void *a, const void *b)
{
    double va = DEREF(const double, a);
    double vb = DEREF(const double, b);

    return fabs(va - vb) <= ITERATOR_DOUBLE_EPSILON;
}

int DblCompare(const void *a, const void *b)
{
    double va = DEREF(const double, a);
    double vb = DEREF(const double, b);

    if (DblEqual(a, b))
        return 0;
    if (va < vb)
        return -1;
    return 1;
}

void DblPrint(const void *elem)
{
    printf("%g\n", DEREF(const double, elem));
}

bool DblIsPositive(const void *elem)
{
    return DEREF(const double, elem) > 0.0;
}

bool DblIsNegative(const void *elem)
{
    return DEREF(const double, elem) < 0.0;
}

bool DblIsZero(const void *elem)
{
    return fabs(DEREF(const double, elem)) <= ITERATOR_DOUBLE_EPSILON;
}

void DblNegate(const void *restrict in, void *restrict out)
{
    DEREF(double, out) = -DEREF(const double, in);
}

void DblIncrement(const void *restrict in, void *restrict out)
{
    DEREF(double, out) = DEREF(const double, in) + 1.0;
}

void DblDecrement(const void *restrict in, void *restrict out)
{
    DEREF(double, out) = DEREF(const double, in) - 1.0;
}
