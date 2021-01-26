#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

/*
credits to https://www.codewars.com/users/user5036852

https://www.codewars.com/kata/57ea70aa5500adfe8a000110
*/

std::vector<int> foldArray(std::vector<int> array, int runs){

    std::vector<int> newarray = array;
    for (int j = 0; j < runs; j++){
        std::vector<int> temp;
        for (int i = 0; i < newarray.size() / 2; i++){
            int one = newarray[i];
            int two = newarray[newarray.size() - 1];
            temp.push_back(newarray[i] + newarray[newarray.size() - 1 - i]);
        }
        if (newarray.size() % 2 == 1){
            temp.push_back(newarray[newarray.size() / 2]);
        }
        newarray.clear();
        for (int i = 0; i < temp.size(); i++){
            newarray.push_back(temp[i]);
        }
    }

    return newarray;

}