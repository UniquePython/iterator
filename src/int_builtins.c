#include "builtins.h"
#include "iterator.h"

#include <stdio.h>

bool IntEqual(const void *a, const void *b)
{
    return DEREF(const int, a) == DEREF(const int, b);
}

int IntCompare(const void *a, const void *b)
{
    int va = DEREF(const int, a);
    int vb = DEREF(const int, b);

    if (va < vb)
        return -1;
    if (va > vb)
        return 1;
    return 0;
}

void IntPrint(const void *elem)
{
    printf("%d\n", DEREF(const int, elem));
}

bool IntIsPositive(const void *elem)
{
    return DEREF(const int, elem) > 0;
}

bool IntIsNegative(const void *elem)
{
    return DEREF(const int, elem) < 0;
}

bool IntIsZero(const void *elem)
{
    return DEREF(const int, elem) == 0;
}

bool IntIsEven(const void *elem)
{
    return DEREF(const int, elem) % 2 == 0;
}

bool IntIsOdd(const void *elem)
{
    return DEREF(const int, elem) % 2 != 0;
}

void IntNegate(const void *restrict in, void *restrict out)
{
    DEREF(int, out) = -DEREF(const int, in);
}

void IntIncrement(const void *restrict in, void *restrict out)
{
    DEREF(int, out) = DEREF(const int, in) + 1;
}

void IntDecrement(const void *restrict in, void *restrict out)
{
    DEREF(int, out) = DEREF(const int, in) - 1;
}
