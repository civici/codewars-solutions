// https://www.codewars.com/kata/525f4206b73515bffb000b21/train/c

#include <stdlib.h>
#include <string.h>

#define MAX_OUTPUT_LEN	500

char* reverse(char* str)
{
	int len = strlen(str);
	char* newstr = calloc(len + 1, 1);
	for (int i = 0; i < len; i++)
	{
		newstr[i] = str[len - i - 1];
	}

	return newstr;
}

char *add(char* a, char *b) 
{
	char* first = reverse(a);
	char* sec = reverse(b);

	char* newnum = calloc(MAX_OUTPUT_LEN, 1);
	int indexer = 0;

	int lenF = strlen(first);
	int lenS = strlen(sec);

	char condF = 0;
	char condS = 0;

	for (int i = 0; condF == 0 || condS == 0 ; i++)
	{
		char current = 0;
		if (i < lenF)
			current += first[i] - '0';
		else
			if (!condF)
				condF++;
		if (i < lenS)
			current += sec[i] - '0';
		else
			if (!condS)
				condS++;

		newnum[indexer] += current;
		indexer++;
	}
	newnum[indexer] = 30;

	for (int j = 0; newnum[j] != 30; j++)
	{
		if (newnum[j] > 9)
		{
			if (newnum[j + 1] == 30)
			{
				newnum[j + 1] = 0;
				newnum[j + 2] = 19;
			}
			newnum[j + 1] += 1;
		}
		newnum[j] %= 10;
	}

	int j;
	for (j = 0; newnum[j] != 30; j++)
	{
		if (newnum[j + 1] == 30 && newnum[j] == 0)
			continue;
		newnum[j] += '0';
	}

	newnum[j] = 0;
	char* temp = reverse(newnum);
	free(newnum);
	return temp;
}

void tester(char* a, char* b, char* expected)
{
	puts(add(a, b));
}


int main()
{
	//tester("1", "1", "2");
    //tester("123", "456", "579");  // 123 + 456 == 579
    //tester("888", "222", "1110");
    //tester("1372", "69", "1441");
    //tester("12", "456", "468");
    //tester("101", "100", "201");
    tester(	   "63829983432984289347293874", 
    		"90938498237058927340892374089", 
		"91002328220491911630239667963");
}