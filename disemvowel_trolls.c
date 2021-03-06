// https://www.codewars.com/kata/52fba66badcd10859f00097e

#include <stdlib.h>

char *disemvowel(const char *str)
{
	char* buffer = calloc(1024, 1);
	int buffercounter = 0;
	char restricted[5] = {'a', 'e', 'i', 'o', 'u'};
	for (int i = 0; str[i] != '\0'; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (str[i] == restricted[j] || str[i] + 32 == restricted[j])
			{
				break;
			}
			if (j == 4)
			{
				buffer[buffercounter] = str[i];
				buffercounter++;
			}	
		}
	}
	return buffer;
}