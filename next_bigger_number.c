// https://www.codewars.com/kata/55983863da40caa2c900004e/train/c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

uint64_t get_now_time() {
  struct timespec spec;
  if (clock_gettime(1, &spec) == -1) { /* 1 is CLOCK_MONOTONIC */
    abort();
  }

  return spec.tv_sec * 1000 + spec.tv_nsec / 1e6;
}

void swap(char* addr1, char* addr2)
{
	char temp = *addr1;
	*addr1 = *addr2;
	*addr2 = temp;
}

char* findMin(char* str)
{
	char min = '9' + 1;
	char* index = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < min)
		{
			min = str[i];
			index = &str[i];
		}
	}

	return index;
}

char* minGreater(char* str)
{
	char base = *str;
	char min = '9' + 1;
	char* index = 0;

	for (int i = 1; str[i]; i++)
	{
		if (base < str[i] && min > str[i])
		{
			min = str[i];
			index = &str[i];
		}
	}

	return index;
}

long long next_bigger_number(long long n)
{
	char* temp = calloc(100, 1);
	sprintf(temp, "%lld", n);
	int len = strlen(temp);

	int i;
	for (i = len - 1; i >= 0; i--)
	{
		char* test = minGreater(&temp[i]);
		if (test)
		{
			swap(&temp[i], test);
			break;
		}
	}

	if (atol(temp) == n)
		return -1;

	for (int j = i + 1; j < len; j++)
	{
		char* minIndex = findMin(&temp[j]);
		if (minIndex)
		{
			swap(&temp[j], minIndex);
		}
	}

	return atol(temp);
}
#include <unistd.h>

int main()
{
	uint64_t start = get_now_time();
	clock_t first = clock();
	long long num = next_bigger_number(19999999999999);
	clock_t sec = clock();
	uint64_t current = get_now_time();
	printf("time %d\n", current - start);
	return 0;
}