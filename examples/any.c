#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Any Consumer ===\n");

    int withEven[] = {1, 3, 5, 8, 9};
    bool hasEven = AnyConsumer(
        NEW_ARRAY_ITERATOR(withEven),
        sizeof(int),
        IntIsEven);
    printf("withEven has an even element: %s\n", hasEven ? "true" : "false");

    int allOdd[] = {1, 3, 5, 7, 9};
    bool hasEven2 = AnyConsumer(
        NEW_ARRAY_ITERATOR(allOdd),
        sizeof(int),
        IntIsEven);
    printf("allOdd has an even element: %s\n", hasEven2 ? "true" : "false");

    return 0;
}