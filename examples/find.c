#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Find Consumer ===\n");
    int intArr[] = {1, 3, 5, 8, 9};

    int result = 0;
    bool found = FIND_ARR(intArr, IntIsEven, &result);

    if (found)
        printf("found even element: %d\n", result);
    else
        printf("no even element found\n");

    int intArrNoEvens[] = {1, 3, 5, 7, 9};
    bool foundNone = FIND_ARR(intArrNoEvens, IntIsEven, &result);

    printf("found: %s\n", foundNone ? "true" : "false");

    return 0;
}