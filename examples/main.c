#include "chain_iterator.h"
#include "zip_iterator.h"
#include "enumerate_iterator.h"
#include "range_iterator.h"
#include "skip_iterator.h"
#include "take_iterator.h"
#include "filter_iterator.h"
#include "map_iterator.h"
#include "string_iterator.h"
#include "array_iterator.h"
#include "iterator.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

void printInt(void *elem)
{
    printf("%d\n", *(int *)elem);
}

void printI64(void *elem)
{
    printf("%" PRId64 "\n", *(int64_t *)elem);
}

void printFloat(void *elem)
{
    printf("%g\n", *(float *)elem);
}

void printChar(void *elem)
{
    printf("%c\n", *(char *)elem);
}

void printEnumeratedItem(void *elem)
{
    EnumeratedItem *item = (EnumeratedItem *)elem;

    printf("idx=%zu, val=", (*item).index);
    printInt((*item).value);
}

void printZippedItem(void *elem)
{
    ZippedItem *item = (ZippedItem *)elem;

    printf("a=");
    printChar((*item).a);

    printf("b=");
    printFloat((*item).b);
}

void doubleInt(void *in, void *out)
{
    *(int *)out = 2 * (*(int *)in);
}

bool isEven(void *elem)
{
    return (*(int *)elem) % 2 == 0;
}

int main(void)
{
    // ARRAY ITERATOR
    printf("\n=== Array Iterator: int ===\n");
    int intArr1[] = {10, 20, 30, 40};
    Iterator intIt1 = newArrayIterator(sizeof(int), intArr1, sizeof intArr1 / sizeof *intArr1);
    printAll(intIt1, sizeof(int), printInt);
    IteratorDestroy(&intIt1);

    printf("\n=== Array Iterator: float ===\n");
    float floatArr1[] = {10.5f, 20.5f, 30.5f, 40.5f};
    Iterator floatIt1 = newArrayIterator(sizeof(float), floatArr1, sizeof floatArr1 / sizeof *floatArr1);
    printAll(floatIt1, sizeof(float), printFloat);
    IteratorDestroy(&floatIt1);

    // STRING ITERATOR
    printf("\n=== String Iterator ===\n");
    char *string1 = "hello";
    Iterator stringIt1 = newStringIterator(string1);
    printAll(stringIt1, sizeof(char), printChar);
    IteratorDestroy(&stringIt1);

    // MAP ITERATOR
    printf("\n=== Map Iterator ===\n");
    int intArr2[] = {10, 20, 30, 40};
    Iterator intIt2 = newArrayIterator(sizeof(int), intArr2, sizeof intArr2 / sizeof *intArr2);
    Iterator mapIt = newMapIterator(sizeof(int), intIt2, doubleInt);
    printAll(mapIt, sizeof(int), printInt);
    IteratorDestroy(&mapIt);
    IteratorDestroy(&intIt2);

    // FILTER ITERATOR
    printf("\n=== Filter Iterator ===\n");
    int intArr3[] = {1, 2, 3, 4};
    Iterator intIt3 = newArrayIterator(sizeof(int), intArr3, sizeof intArr3 / sizeof *intArr3);
    Iterator filterIt = newFilterIterator(sizeof(int), intIt3, isEven);
    printAll(filterIt, sizeof(int), printInt);
    IteratorDestroy(&filterIt);
    IteratorDestroy(&intIt3);

    // TAKE ITERATOR
    printf("\n=== Take Iterator ===\n");
    int intArr4[] = {10, 20, 30, 40};
    Iterator intIt4 = newArrayIterator(sizeof(int), intArr4, sizeof intArr4 / sizeof *intArr4);
    Iterator takeIt = newTakeIterator(sizeof(int), intIt4, 2);
    printAll(takeIt, sizeof(int), printInt);
    IteratorDestroy(&takeIt);
    IteratorDestroy(&intIt4);

    // SKIP ITERATOR
    printf("\n=== Skip Iterator ===\n");
    int intArr5[] = {10, 20, 30, 40};
    Iterator intIt5 = newArrayIterator(sizeof(int), intArr5, sizeof intArr5 / sizeof *intArr5);
    Iterator skipIt = newSkipIterator(sizeof(int), intIt5, 2);
    printAll(skipIt, sizeof(int), printInt);
    IteratorDestroy(&skipIt);
    IteratorDestroy(&intIt5);

    // RANGE ITERATOR
    printf("\n=== Range Iterator: inclusive ===\n");
    Iterator rangeItInc = newRangeIterator(2, 10, 2, true);
    printAll(rangeItInc, sizeof(int64_t), printI64);
    IteratorDestroy(&rangeItInc);

    printf("\n=== Range Iterator: exclusive ===\n");
    Iterator rangeItExc = newRangeIterator(2, 10, 2, false);
    printAll(rangeItExc, sizeof(int64_t), printI64);
    IteratorDestroy(&rangeItExc);

    // ENUMERATE ITERATOR
    printf("\n=== Enumerate Iterator ===\n");
    int intArr6[] = {10, 20, 30, 40};
    Iterator intIt6 = newArrayIterator(sizeof(int), intArr6, sizeof intArr6 / sizeof *intArr6);
    Iterator enumerateIt = newEnumerateIterator(sizeof(int), intIt6);
    printAll(enumerateIt, sizeof(EnumeratedItem), printEnumeratedItem);
    IteratorDestroy(&enumerateIt);
    IteratorDestroy(&intIt6);

    // ZIP ITERATOR
    printf("\n=== Zip Iterator ===\n");
    float floatArr2[] = {10.37, 20.37, 30.37, 40.37};
    Iterator floatIt2 = newArrayIterator(sizeof(float), floatArr2, sizeof floatArr2 / sizeof *floatArr2);
    char *string2 = "hello";
    Iterator stringIt2 = newStringIterator(string2);
    Iterator zipIt = newZipIterator(sizeof(char), stringIt2, sizeof(float), floatIt2);
    printAll(zipIt, sizeof(ZippedItem), printZippedItem);
    IteratorDestroy(&zipIt);
    IteratorDestroy(&stringIt2);
    IteratorDestroy(&floatIt2);

    // CHAIN ITERATOR
    printf("\n=== Chain Iterator ===\n");
    int intArr7[] = {10, 20, 30, 40};
    Iterator intIt7 = newArrayIterator(sizeof(int), intArr7, sizeof intArr7 / sizeof *intArr7);
    int intArr8[] = {60, 70, 80, 90};
    Iterator intIt8 = newArrayIterator(sizeof(int), intArr8, sizeof intArr8 / sizeof *intArr8);
    Iterator chainIt = newChainIterator(sizeof(int), intIt7, intIt8);
    printAll(chainIt, sizeof(int), printInt);
    IteratorDestroy(&chainIt);
    IteratorDestroy(&intIt8);
    IteratorDestroy(&intIt7);

    return 0;
}