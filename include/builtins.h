#ifndef BUILTINS_H_
#define BUILTINS_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef ITERATOR_FLOAT_EPSILON
#define ITERATOR_FLOAT_EPSILON 1e-6f
#endif

#ifndef ITERATOR_DOUBLE_EPSILON
#define ITERATOR_DOUBLE_EPSILON 1e-9
#endif

bool IntEqual(const void *a, const void *b);
int IntCompare(const void *a, const void *b);
void IntPrint(const void *elem);
bool IntIsPositive(const void *elem);
bool IntIsNegative(const void *elem);
bool IntIsZero(const void *elem);
bool IntIsEven(const void *elem);
bool IntIsOdd(const void *elem);
void IntNegate(const void *restrict in, void *restrict out);
void IntIncrement(const void *restrict in, void *restrict out);
void IntDecrement(const void *restrict in, void *restrict out);

bool FloatEqual(const void *a, const void *b);
int FloatCompare(const void *a, const void *b);
void FloatPrint(const void *elem);
bool FloatIsPositive(const void *elem);
bool FloatIsNegative(const void *elem);
bool FloatIsZero(const void *elem);
void FloatNegate(const void *restrict in, void *restrict out);
void FloatIncrement(const void *restrict in, void *restrict out);
void FloatDecrement(const void *restrict in, void *restrict out);

bool DblEqual(const void *a, const void *b);
int DblCompare(const void *a, const void *b);
void DblPrint(const void *elem);
bool DblIsPositive(const void *elem);
bool DblIsNegative(const void *elem);
bool DblIsZero(const void *elem);
void DblNegate(const void *restrict in, void *restrict out);
void DblIncrement(const void *restrict in, void *restrict out);
void DblDecrement(const void *restrict in, void *restrict out);

bool CharEqual(const void *a, const void *b);
int CharCompare(const void *a, const void *b);
void CharPrint(const void *elem);
void CharIncrement(const void *restrict in, void *restrict out);
void CharDecrement(const void *restrict in, void *restrict out);

bool SizeTEqual(const void *a, const void *b);
int SizeTCompare(const void *a, const void *b);
void SizeTPrint(const void *elem);
bool SizeTIsZero(const void *elem);
bool SizeTIsEven(const void *elem);
bool SizeTIsOdd(const void *elem);
void SizeTIncrement(const void *restrict in, void *restrict out);

bool I64Equal(const void *a, const void *b);
int I64Compare(const void *a, const void *b);
void I64Print(const void *elem);
bool I64IsPositive(const void *elem);
bool I64IsNegative(const void *elem);
bool I64IsZero(const void *elem);
bool I64IsEven(const void *elem);
bool I64IsOdd(const void *elem);
void I64Negate(const void *restrict in, void *restrict out);
void I64Increment(const void *restrict in, void *restrict out);
void I64Decrement(const void *restrict in, void *restrict out);

#endif
