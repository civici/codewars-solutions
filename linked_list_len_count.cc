#include <stdio.h>
#include <stdlib.h>

/*

credits to https://www.codewars.com/users/JDeBolt

https://www.codewars.com/kata/55beec7dd347078289000021

*/

struct Node {
  Node * next;
  int data;
};

int Length(Node* head){

    Node* current = head;
    int len = 0;
    while (current != NULL){
        len++;
        current = current->next;
    }
    return len;
}

int Count(Node* head, int data){
    Node* current = head;
    int count = 0;
    while (current != NULL){
        if (current->data == data){
            count++;
        }
        current = current->next;
    }
    return count;
}

