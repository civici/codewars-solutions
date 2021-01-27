#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*

https://www.codewars.com/kata/55031bba8cba40ada90011c4/train/c

i got it wrong so i fcked up

*/

char* test(char* str){

    char** args;
    int argamount = 0;
    for (int i = 0; i < strlen(str) + 1; i++){
        if (str[i] == ' ' || str[i] == '\0'){
            argamount++;
        }
    }

    int args_size[argamount];
    for (int i = 0; i < argamount; i++){
        args_size[i] = 0;
    }

    int argindex = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == ' '){
            argindex++;
        } else {
            args_size[argindex]++;
        }
    }

    args = malloc(sizeof(char*) * argamount);
    for (int i = 0; i < argamount; i++){
        args[i] = calloc(args_size[i] + 1, sizeof(char));
    }
    argindex = 0;
    int strindex = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == ' '){
            argindex++;
            strindex = 0;
        } else {
            args[argindex][strindex] = str[i];
            strindex++;
        }
    }

    int* cubics;
    int cubics_size = 0;

    int buffer = 0;

    for (int i = 0; i < argamount; i++){
        int num = 0;
        for (int j = 0; j < strlen(args[i]); j++){
            if (! (args[i][j] <= '9' && args[i][j] >= '0')){
                break;
            } else if (j == strlen(args[i]) - 1) {
                num += args[i][j] - '0';
                int cubic_comp = 0;
                for (int num_index = 0; num_index < strlen(args[i]); num_index++){
                    cubic_comp += pow(args[i][num_index] - '0', strlen(args[i]));
                }
                if (num == cubic_comp){
                    buffer += strlen(args[i]);
                    if (cubics_size == 0){
                        cubics = malloc(sizeof(int));
                        cubics[0] = num;
                        cubics_size++;
                    } else {
                        int* temp = malloc(sizeof(int) * (cubics_size + 1));
                        for (int cubic_index = 0; cubic_index < cubics_size; cubic_index++){
                            temp[cubic_index] = cubics[cubic_index];
                        }
                        temp[cubics_size] = num;
                        free(cubics);
                        cubics = temp;
                        cubics_size++;
                    }
                }
                printf("num is %d cubic %d\n", num, cubic_comp);
            } else {
                num += (args[i][j] - '0') * pow(10, strlen(args[i]) - j - 1);
            }
        }
    }
    buffer += cubics_size + 2; /* spaces and null terminated */

    if (cubics_size > 0){
        int total = 0;
        for (int i = 0; i < cubics_size; i++){
            total += cubics[i];
        }
        int total_digits = 1;
        int temp = total;
        while (temp >= 10){
            total_digits++;
            temp /= 10;
        }
        buffer += total_digits;
        char* luck = "lucky";
        buffer += strlen(luck);
        char* resp = calloc(buffer, 1);
        for (int i = 4; i >= 0; i++){
            resp[buffer - 2 + (i - 4)] = luck[i]; 
        }
        for (int i = total_digits; i >= 1; i++){
            resp[buffer - 6 ] 
        }
        printf("total %d\n", total);
    } else {
        return "Unlucky";
    }

    for (int i = 0; i < cubics_size; i++){
        printf("cubic i %d %d\n", i, cubics[i]);
    }

}

int main(){

    test("aqdf& 0 1 xyz 153 777.777");
    puts("done");
    return 0;

}