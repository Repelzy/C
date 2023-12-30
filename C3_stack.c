#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if(top == -1)
        return '\0';
    else
        return stack[top--];
}

int match(char a, char b) {
    if(a == '(' && b == ')') return 1;
    if(a == '{' && b == '}') return 1;
    if(a == '[' && b == ']') return 1;
    return 0;
}

int main() {
    char str[MAX];
    fgets(str, MAX, stdin);

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            push(str[i]);
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if(!match(pop(), str[i])) {
                printf("0\n");
                return 0;
            }
        }
    }

    if(top == -1)
        printf("1\n");
    else
        printf("0\n");

    return 0;
}
