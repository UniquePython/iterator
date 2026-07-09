#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct iterator_t Iterator;

void IteratorDestroy(Iterator *iterator);
void printAll(Iterator iterator, size_t elemSize, void (*print)(void *elem));

#endif