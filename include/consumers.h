#ifndef CONSUMER_H_
#define CONSUMER_H_

#include "iterator.h"
#include "array_iterator.h"

size_t CountConsumer(Iterator iterator, size_t elemSize);
bool FindConsumer(Iterator iterator, size_t elemSize, bool (*condition)(const void *elem), void *out);
bool AnyConsumer(Iterator iterator, size_t elemSize, bool (*condition)(const void *elem));
bool AllConsumer(Iterator iterator, size_t elemSize, bool (*condition)(const void *elem));
void ForEachConsumer(Iterator iterator, size_t elemSize, void (*action)(const void *elem));
void ReduceConsumer(Iterator iterator, size_t elemSize, void (*combine)(const void *restrict elem, void *restrict acc), void *out);

/* Consume a real array directly, inferring elemSize and array length.
   `arr` must be an actual array in scope, not a decayed pointer (same
   constraint as NEW_ARRAY_ITERATOR). */
#define COUNT_ARR(arr) CountConsumer(NEW_ARRAY_ITERATOR(arr), sizeof(*(arr)))
#define FIND_ARR(arr, condition, out) FindConsumer(NEW_ARRAY_ITERATOR(arr), sizeof(*(arr)), (condition), (out))
#define ANY_ARR(arr, condition) AnyConsumer(NEW_ARRAY_ITERATOR(arr), sizeof(*(arr)), (condition))
#define ALL_ARR(arr, condition) AllConsumer(NEW_ARRAY_ITERATOR(arr), sizeof(*(arr)), (condition))
#define FOR_EACH_ARR(arr, action) ForEachConsumer(NEW_ARRAY_ITERATOR(arr), sizeof(*(arr)), (action))
#define REDUCE_ARR(arr, combine, out) ReduceConsumer(NEW_ARRAY_ITERATOR(arr), sizeof(*(arr)), (combine), (out))

#endif
