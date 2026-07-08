#include "map_iterator.h"
#include "string_iterator.h"
#include "array_iterator.h"
#include "iterator.h"

#include <stdio.h>

void printInt(void *elem)
{
    printf("%d\n", *(int *)elem);
}

void printFloat(void *elem)
{
    printf("%g\n", *(float *)elem);
}

void printChar(void *elem)
{
    printf("%c\n", *(char *)elem);
}

void doubleInt(void *in, void *out)
{
    *(int *)out = 2 * (*(int *)in);
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

    return 0;
}