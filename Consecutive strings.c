// https://www.codewars.com/kata/56a5d994ac971f1ac500003e

#include <stdlib.h>
#include <string.h>

char* longestConsec(char* strarr[], int n, int k)
{
    if (n == 0 || k <= 0 || k > n)
        return "";
    int max = 0;
    char* output = NULL;
    for (int i = 0; i < n - (k - 1); i++)
    {
        char* tempstr = calloc(4096, 1);
        strcat(tempstr, strarr[i]);
        int temp = strlen(strarr[i]);
        for (int j = i + 1; j < k + i; j++)
        {
            temp += strlen(strarr[j]);
            strcat(tempstr, strarr[j]);
        }
        if (temp > max)
        {
            max = temp;
            if (output != NULL)
                free(output);
            output = tempstr;
        }else {
            free(tempstr);
        }
    }
    return output;
}