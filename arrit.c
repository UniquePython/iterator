#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct ArrayIterator_t
{
    int *arr;
    size_t len;
    size_t currIdx;

} ArrIt;

ArrIt newArrIt(int *arr, size_t arrLen)
{
    ArrIt arrIt = {0};

    arrIt.arr = arr;
    arrIt.len = arrLen;
    arrIt.currIdx = 0;

    return arrIt;
}

bool arrItNext(ArrIt *arrIt, int *out)
{
    if (!arrIt || !out || arrIt->currIdx >= arrIt->len)
        return false;

    *out = arrIt->arr[arrIt->currIdx++];
    return true;
}

int main(void)
{
    int arr[] = {10, 20, 30, 40};

    ArrIt arrIt = newArrIt(arr, 4);

    for (;;)
    {
        int out;

        if (!arrItNext(&arrIt, &out))
            break;

        printf("%d\n", out);
    }

    return 0;
}