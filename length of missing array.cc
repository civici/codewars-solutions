#include <iostream>
#include <vector>

/*

credits to https://www.codewars.com/users/user5036852

kata: https://www.codewars.com/kata/57b6f5aadb5b3d0ae3000611

You get an array of arrays.
If you sort the arrays by their length, you will see, that their length-values are consecutive.
But one array is missing!


You have to write a method, that return the length of the missing array.

If the array of arrays is null/nil or empty, the method should return 0.

When an array in the array is null or empty, the method should return 0 too!
There will always be a missing element and its length will be always between the given arrays. 

*/

using namespace std;

template<class TYPE>
int test(std::vector<std::vector<TYPE>> arrayOfArrays)
{
  
    int size = (int) arrayOfArrays.size();
    if (size == 0){
        return 0;
    }
    int arrays[size];
  
    for (int i = 0; i < size; i++){
        if (arrayOfArrays[i].size() == 0){
            return 0;
        }
        arrays[i] = (int) arrayOfArrays[i].size();
    }
    for (int j = 0; j < size; j++){
        int min_index = -1;
        bool t = false;
        for (int i = 0 + j; i < size; i++){
            if (min_index == -1){
                min_index = i;
            }
            int current = arrays[i];
            int min = arrays[min_index];
            if (current < min){
                min_index = i;
                t = true;
            }
        }
        if (t == true){
            int temp = arrays[j];
            arrays[j] = arrays[min_index];
            arrays[min_index] = temp;
        }

    }

    for (int i = 0; i < size - 1; i++){
        if (arrays[i] + 1 != arrays[i + 1]){
            return arrays[i] + 1;
        }
    }
  
  return 0;
  
}
