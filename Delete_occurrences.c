// https://www.codewars.com/kata/554ca54ffa7d91b236000023/solutions/c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nullptr NULL
int* search(int val, int* data, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (data[i * 2] == val)
		{
			return &data[i * 2 + 1];
		}
	}

	return nullptr;
}

int* delete_nth(size_t szin, int order[szin], int max_e, size_t *szout) 
{
	int* data = malloc(sizeof(int) * 1000);
	int count = 0;
	int* temp = malloc(sizeof(int) * 1000);
	int index = 0;
	for (int i = 0; i < szin; i++)
	{
		int* res = search(order[i], data, count); 
		if (res == nullptr)
		{
			data[count * 2] = order[i];
			data[count * 2 + 1] = 1;
			count++;
			temp[index] = order[i];
			index++;
			continue;
		}
		*res += 1;
		if (*res > max_e)
		{
			continue;
		}

		temp[index] = order[i];
		index++;
		
	}
	*szout = index;
	return temp;
}