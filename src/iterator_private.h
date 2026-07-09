#ifndef ITERATOR_PRIVATE_H_
#define ITERATOR_PRIVATE_H_

#include "iterator.h"

struct iterator_t
{
    void *state;
    bool (*next)(void *state, void *out);
    void (*destroy)(void *state);
};

#endif