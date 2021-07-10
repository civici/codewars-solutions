// https://www.codewars.com/kata/52190daefe9c702a460003dd/train/c

#include <string.h>

int search_substr(char* full_text, char* search_text, char allow_overleap)
{
	for (int val = 0; *search_text != 0; val++)
	{
		char* substr = strstr(full_text, search_text);
		if (substr == NULL)
			return val;
		full_text = substr + (allow_overleap ? 1 : strlen(search_text));
	}
	return 0;
}