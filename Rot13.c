// https://www.codewars.com/kata/530e15517bc88ac656000716

#include <stdlib.h>
#include <string.h>

char *rot13(const char *src)
{
	char* buf = calloc(1, strlen(src));
	char* temp = buf;
	while (*src)
	{
		unsigned char c = *src + 13;
		if (*src >= 'a' && *src <= 'z')
		{
			if (c > 'z')
			{
				c = (c - 122) + 97 - 1;
			}
		} else if (*src >= 'A' && *src <= 'Z' )
		{
			if (c > 'Z')
			{
				c = (c - 'Z') + 'A' - 1;
			}
		} else 
		{
			c = *src;
		}
		*temp++ = c;
		src++;
	}
	return buf;
}