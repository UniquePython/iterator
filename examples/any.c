#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Any Consumer ===\n");

    int withEven[] = {1, 3, 5, 8, 9};
    bool hasEven = ANY_ARR(withEven, IntIsEven);
    printf("withEven has an even element: %s\n", hasEven ? "true" : "false");

    int allOdd[] = {1, 3, 5, 7, 9};
    bool hasEven2 = ANY_ARR(allOdd, IntIsEven);
    printf("allOdd has an even element: %s\n", hasEven2 ? "true" : "false");

    return 0;
}