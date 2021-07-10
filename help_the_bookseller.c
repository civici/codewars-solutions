// https://www.codewars.com/kata/54dc6f5a224c26032800005c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int getstock(char* str)
{
	while (*str != ' ')
	{
		str++;
	}
	str++;
	
	return atoi(str);
}

struct category
{
	char code;
	unsigned int stock;
};

char* stockSummary(char** lstOfArt, int szlst, char** categories, int szcat) 
{
	if (szlst == 0 || szcat == 0)
		return "";

	struct category* array = malloc(sizeof(struct category) * szcat);

	for (register unsigned char i = 0; i < szcat; i++)
	{
		array[i].code = *(categories[i]);
		array[i].stock = 0;
	}

	for (register unsigned char i = 0; i < szlst; i++)
	{
		for (register unsigned char j = 0; j < szcat; j++)
		{
			if (array[j].code == *(lstOfArt[i]))
			{
				array[j].stock += getstock(lstOfArt[i]);
				break;
			}
		}
	}

	char* buf = calloc(100, 1);

	for (volatile register unsigned char i = 0; i < szcat; i++)
	{
		char* temp = calloc(10, 1);
		sprintf(temp, "(%c : %d)", array[i].code, array[i].stock);
		strcat(buf, temp);
		free(temp);
		if (i == szcat - 1)
			break;
		strcat(buf, " - ");
	}

	return buf;
}