#include <string.h>
#include <stdlib.h>

// https://www.codewars.com/kata/5583d268479559400d000064
// misunderstood and coded string_to_binary but second one is the right solution :)

char *string_to_binary(const char *string) {
    
	char* binarystr = calloc(8 * strlen(string) + 1 , 1);
	unsigned int binaryindex = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		char currentchar = string[i];
		for (int j = 128; j >= 1; j /= 2)
		{
			binarystr[binaryindex] = currentchar / j + '0';
			binaryindex++;
			currentchar %= j;
		}
	}
	puts(binarystr);
	return binarystr;
}

char* binary_to_string(const char* binary)
{
	char* str = calloc(strlen(binary) / 8 + 1, 1);
	int strindex = 0;
	for (int i = 0; binary[i] != '\0'; )
	{
		char currentChar = 0;
		for (int j = 128 ; j >= 1; i++)
		{
			currentChar += (binary[i] - '0') * j;
			j /= 2;
		}
		str[strindex] = currentChar;
		strindex++;
	}
	return str;
}
