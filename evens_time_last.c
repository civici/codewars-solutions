#include <stddef.h>

/* https://www.codewars.com/kata/5a1a9e5032b8b98477000004/train/c */

int even_last(const int array[], size_t z) 
{
	int sum = 0;
	for (int i = 0; i < z; i++)
	{
		sum += i % 2 == 0 ? array[i] * array[z - 1] : 0;
	}
	return sum;

}