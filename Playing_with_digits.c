// https://www.codewars.com/kata/5552101f47fc5178b1000050/train/c

#include <stdio.h>
#include <stdlib.h>

int powFunc(int base, int pow)
{
	int sum = base;
	for (int i = 1; i < pow; i++)
		sum *= base;

	return sum;
}

int digPow(int num, int pow)
{
	int sum = 0;
	char* str = calloc(100, 1);
	sprintf(str, "%d", num);
	for (; *str; str++, pow++)
		sum += powFunc(*str - '0', pow);

	float res = ((float) sum) / ((float)num);
	int temp = (int)res;
	if (res - temp != 0)
		return -1;

	return sum / num;
}

int main()
{
	int a = digPow(92, 1);
	printf("%d\n", a);
}