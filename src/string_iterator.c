#include "string_iterator.h"

#include <stdlib.h>
#include <string.h>

struct string_iterator_t
{
    const char *string;
    size_t currIdx;
};

bool StringIteratorNext(void *restrict state, void *restrict out)
{
    StringIterator *strIt = (StringIterator *)state;
    char *value = (char *)out;

    if (!strIt || !value)
        return false;

    char ch = strIt->string[strIt->currIdx];

    if (ch == '\0')
        return false;

    *value = ch;
    strIt->currIdx++;

    return true;
}

void StringIteratorDestroy(void *state)
{
    free(state);
}

Iterator NewStringIterator(const char *string)
{
    Iterator iterator = {0};

    if (!string)
        return iterator;

    StringIterator *stringIterator = malloc(sizeof *stringIterator);

    if (!stringIterator)
        return iterator;

    stringIterator->string = string;
    stringIterator->currIdx = 0;

    return NewIterator(stringIterator, StringIteratorNext, StringIteratorDestroy);
}