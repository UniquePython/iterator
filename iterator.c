#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Actual Iterator code

typedef struct iterator_t
{
    void *state;
    bool (*next)(void *state, void *out);
    void (*destroy)(void *state);

} Iterator;

void IteratorDestroy(Iterator *iterator)
{
    if (!iterator || !iterator->destroy)
        return;

    iterator->destroy(iterator->state);

    iterator->state = NULL;
    iterator->next = NULL;
    iterator->destroy = NULL;
}

void printAll(Iterator iterator, size_t elemSize, void (*print)(void *elem))
{
    void *out = malloc(elemSize);
    if (!out)
        return;

    while (iterator.next(iterator.state, out))
        print(out);

    free(out);
}

// Example

typedef struct int_array_iterator_t
{
    int *arr;
    size_t len;
    size_t currIdx;

} IntArrayIterator;

bool IntArrayIteratorNext(void *state, void *out)
{
    IntArrayIterator *arrIt = (IntArrayIterator *)state;
    int *value = (int *)out;

    if (!arrIt || !value || arrIt->currIdx >= arrIt->len)
        return false;

    *value = arrIt->arr[arrIt->currIdx++];
    return true;
}

void IntArrayIteratorDestroy(void *state)
{
    free(state);
}

Iterator newIntArrayIterator(int *arr, size_t arrLen)
{
    Iterator iterator = {0};

    IntArrayIterator *intArrayIterator = malloc(sizeof *intArrayIterator);

    if (!intArrayIterator)
        return iterator;

    intArrayIterator->arr = arr;
    intArrayIterator->len = arrLen;
    intArrayIterator->currIdx = 0;

    iterator.state = intArrayIterator;
    iterator.next = IntArrayIteratorNext;
    iterator.destroy = IntArrayIteratorDestroy;

    return iterator;
}

void printInt(void *elem)
{
    printf("%d\n", *((int *)elem));
}

typedef struct float_array_iterator_t
{
    float *arr;
    size_t len;
    size_t currIdx;

} FloatArrayIterator;

bool FloatArrayIteratorNext(void *state, void *out)
{
    FloatArrayIterator *arrIt = (FloatArrayIterator *)state;
    float *value = (float *)out;

    if (!arrIt || !value || arrIt->currIdx >= arrIt->len)
        return false;

    *value = arrIt->arr[arrIt->currIdx++];
    return true;
}

void FloatArrayIteratorDestroy(void *state)
{
    free(state);
}

Iterator newFloatArrayIterator(float *arr, size_t arrLen)
{
    Iterator iterator = {0};

    FloatArrayIterator *floatArrayIterator = malloc(sizeof *floatArrayIterator);

    if (!floatArrayIterator)
        return iterator;

    floatArrayIterator->arr = arr;
    floatArrayIterator->len = arrLen;
    floatArrayIterator->currIdx = 0;

    iterator.state = floatArrayIterator;
    iterator.next = FloatArrayIteratorNext;
    iterator.destroy = FloatArrayIteratorDestroy;

    return iterator;
}

void printFloat(void *elem)
{
    printf("%g\n", *((float *)elem));
}

int main(void)
{
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = newIntArrayIterator(intArr, sizeof intArr / sizeof *intArr);
    printAll(intIt, sizeof(int), printInt);
    IteratorDestroy(&intIt);

    float floatArr[] = {10.5, 20.5, 30.5, 40.5};
    Iterator floatIt = newFloatArrayIterator(floatArr, sizeof floatArr / sizeof *floatArr);
    printAll(floatIt, sizeof(float), printFloat);
    IteratorDestroy(&floatIt);

    return 0;
}