// https://www.codewars.com/kata/54c27a33fb7da0db0100040e

#include <math.h>

int is_square(int n) { return fmod(sqrtf(n), 1.0f) == 0.0f ? 1 : 0; }