#include "builtins.h"
#include "iterator.h"

#include <stdio.h>

bool CharEqual(const void *a, const void *b)
{
    return DEREF(const char, a) == DEREF(const char, b);
}

int CharCompare(const void *a, const void *b)
{
    char va = DEREF(const char, a);
    char vb = DEREF(const char, b);

    if (va < vb)
        return -1;
    if (va > vb)
        return 1;
    return 0;
}

void CharPrint(const void *elem)
{
    printf("%c\n", DEREF(const char, elem));
}

void CharIncrement(const void *restrict in, void *restrict out)
{
    DEREF(char, out) = (char)(DEREF(const char, in) + 1);
}

void CharDecrement(const void *restrict in, void *restrict out)
{
    DEREF(char, out) = (char)(DEREF(const char, in) - 1);
}
