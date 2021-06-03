// https://www.codewars.com/kata/51f2d1cafc9c0f745c00037d/

#include <string.h>

char solution(const char *string, const char *ending)
{
	unsigned int stringLen = strlen(string);
	unsigned int endingLen = strlen(ending);

	if (stringLen < endingLen)
		return 0;
	
	if (endingLen == 0)
		return 1;

	if (strcmp(string + (stringLen - endingLen), ending))
		return 0;
	
	return 1;
}