// https://www.codewars.com/kata/5266876b8f4bf2da9b000362

#include <stdio.h>
#include <stdlib.h>

char* likes(int n, char** names)
{
    char* output = calloc(70, 1);
    switch (n)
    {
        case 0:
            sprintf(output, "no one likes this");
            return output;
        case 1:
            sprintf(output, "%s likes this", names[0]);
            return output;
        case 2:
            sprintf(output, "%s and %s like this", names[0], names[1]);
            return output;
        case 3:
            sprintf(output, "%s, %s and %s like this", names[0], names[1], names[2]);
            return output;
    }
    sprintf(output, "%s, %s and %d others like this", names[0], names[1], n - 2);
    return output;
}