// https://www.codewars.com/kata/513e08acc600c94f01000001

#include <stdio.h>
#include <stdlib.h>

int test(int dec)
{
    return dec >= 10 ? dec + '7' : dec + '0'; 
}

int rgb(int r, int g, int b, char* output)
{
    int currentint;
    for (int i = 0; i < 6; i++)
    {
        currentint = i < 4 ? ( i < 2 ? r : g ): b;
        currentint = currentint < 0 || currentint > 255 ? (currentint < 0 ? 0 : 255) : currentint;
        output[i] = test(i % 2 == 1 ? currentint % 16 : currentint / 16);
    }
    return 0;
}