#ifndef CONSUMER_H_
#define CONSUMER_H_

#include "iterator.h"

size_t CountConsumer(Iterator iterator, size_t elemSize);
bool FindConsumer(Iterator iterator, size_t elemSize, bool (*condition)(const void *elem), void *out);
bool AnyConsumer(Iterator iterator, size_t elemSize, bool (*condition)(const void *elem));
bool AllConsumer(Iterator iterator, size_t elemSize, bool (*condition)(const void *elem));
void ForEachConsumer(Iterator iterator, size_t elemSize, void (*action)(const void *elem));

#endif