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
    int intArr1[] = {10, 20, 30, 40};
    Iterator intIt1 = newArrayIterator(sizeof(int), intArr1, sizeof intArr1 / sizeof *intArr1);
    printAll(intIt1, sizeof(int), printInt);
    IteratorDestroy(&intIt1);

    float floatArr[] = {10.5f, 20.5f, 30.5f, 40.5f};
    Iterator floatIt = newArrayIterator(sizeof(float), floatArr, sizeof floatArr / sizeof *floatArr);
    printAll(floatIt, sizeof(float), printFloat);
    IteratorDestroy(&floatIt);

    char *string = "hello";
    Iterator stringIt = newStringIterator(string);
    printAll(stringIt, sizeof(char), printChar);
    IteratorDestroy(&stringIt);

    int intArr2[] = {10, 20, 30, 40};
    Iterator intIt2 = newArrayIterator(sizeof(int), intArr2, sizeof intArr2 / sizeof *intArr2);
    Iterator mapIt = newMapIterator(sizeof(int), intIt2, doubleInt);
    printAll(mapIt, sizeof(int), printInt);
    IteratorDestroy(&mapIt);
    IteratorDestroy(&intIt2);

    int intArr3[] = {1, 2, 3, 4};
    Iterator intIt3 = newArrayIterator(sizeof(int), intArr3, sizeof intArr3 / sizeof *intArr3);
    Iterator filterIt = newFilterIterator(sizeof(int), intIt3, isEven);
    printAll(filterIt, sizeof(int), printInt);
    IteratorDestroy(&filterIt);
    IteratorDestroy(&intIt3);

    int intArr4[] = {10, 20, 30, 40};
    Iterator intIt4 = newArrayIterator(sizeof(int), intArr4, sizeof intArr4 / sizeof *intArr4);
    Iterator takeIt = newTakeIterator(sizeof(int), intIt4, 2);
    printAll(takeIt, sizeof(int), printInt);
    IteratorDestroy(&takeIt);
    IteratorDestroy(&intIt4);

    int intArr5[] = {10, 20, 30, 40};
    Iterator intIt5 = newArrayIterator(sizeof(int), intArr5, sizeof intArr5 / sizeof *intArr5);
    Iterator skipIt = newSkipIterator(sizeof(int), intIt5, 2);
    printAll(skipIt, sizeof(int), printInt);
    IteratorDestroy(&skipIt);
    IteratorDestroy(&intIt5);

    Iterator rangeItInc = newRangeIterator(2, 10, 2, true);
    printAll(rangeItInc, sizeof(int64_t), printI64);
    IteratorDestroy(&rangeItInc);

    Iterator rangeItExc = newRangeIterator(2, 10, 2, false);
    printAll(rangeItExc, sizeof(int64_t), printI64);
    IteratorDestroy(&rangeItExc);

    int intArr6[] = {10, 20, 30, 40};
    Iterator intIt6 = newArrayIterator(sizeof(int), intArr6, sizeof intArr6 / sizeof *intArr6);
    Iterator enumerateIt = newEnumerateIterator(sizeof(int), intIt6);
    printAll(enumerateIt, sizeof(EnumeratedItem), printEnumeratedItem);
    IteratorDestroy(&enumerateIt);
    IteratorDestroy(&intIt6);

    return 0;
}