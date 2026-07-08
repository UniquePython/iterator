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

int main(void)
{
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = newArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    printAll(intIt, sizeof(int), printInt);
    IteratorDestroy(&intIt);

    float floatArr[] = {10.5f, 20.5f, 30.5f, 40.5f};
    Iterator floatIt = newArrayIterator(sizeof(float), floatArr, sizeof floatArr / sizeof *floatArr);
    printAll(floatIt, sizeof(float), printFloat);
    IteratorDestroy(&floatIt);

    char *string = "hello";
    Iterator stringIt = newStringIterator(string);
    printAll(stringIt, sizeof(char), printChar);
    IteratorDestroy(&stringIt);

    return 0;
}