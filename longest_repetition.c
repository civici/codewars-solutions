/*
    credits to https://www.codewars.com/users/suic
    https://www.codewars.com/kata/586d6cefbcc21eed7a001155

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char longest_repetition(char* s, size_t* n){

    size_t len = strlen(s);

    if (len == 0){
        return 0;
    }

    char max = 0;
    int rep = 0;

    char temp = 0;
    int temprep = 0;

    for (size_t i = 0; i < len; i++){
        char currentchar = s[i];
        if (currentchar != temp){
            temp = currentchar;
        }
        temprep++;

        if (i < len - 1){
            if (s[i + 1] != currentchar){
                if (temprep > rep){
                    max = temp;
                    rep = temprep;
                    temprep = 0;
                } else {
                    temprep = 0;
                }
            }
        } else {
            if (temprep > rep){
                max = temp;
                rep = temprep;
                temprep = 0;
            }
        }

    }

    *n = (size_t) rep;
    return max;

}