#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define length 100
#define EMPTY (-1)

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef Node *stack;

bool push(stack *numStack, int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) return false;
    new_node -> value = value;
    new_node -> next = *numStack;
    *numStack = new_node;
    return true;
}

int pop(stack *numStack){
    if(*numStack == NULL) return INT_MIN;
    int res = (*numStack) -> value;
    Node *tmp = *numStack;
    *numStack = (*numStack) -> next;
    free(tmp);
    return res;
}

int main(){
    stack s1 = NULL, s2 = NULL, s3 = NULL;
    push(&s1, 78);
    push(&s2, 23);
    push(&s3, 111);
    push(&s3, 3);
    push(&s3, 21);
    pop(&s3); 
    return 0;
}
