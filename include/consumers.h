#ifndef CONSUMER_H_
#define CONSUMER_H_

#include "iterator.h"

size_t CountConsumer(Iterator iterator, size_t elemSize);
bool FindConsumer(Iterator iterator, size_t elemSize, bool (*condition)(const void *elem), void *out);

#endif