#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define length 100
#define EMPTY (-1)

typedef struct 
{
    int arr[length];
    int top;
} stackArray;

bool push(stackArray *arr, int value){
    if(arr->top >= length-1) return false;
    arr->top++;
    arr->arr[arr->top] = value;
    return true;
}

int pop(stackArray *arr){
    if(arr->top == EMPTY) return INT_MIN;
    int res = arr->arr[arr->top];
    arr->top--;
    return res;
}

int main(){
    stackArray s;
    s.top = EMPTY;
    push(&s, 10);
    push(&s, 20);
    int t = pop(&s);
    printf("%d \n", t);
    return 0;
}
