#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int index;
    struct Node *next;
} Node;

Node *top = NULL;

Node *makeNode(int value, int index) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->index = index;
    p->next = NULL;
    return p;
}

void push(int i, int index) {
    Node *tmp = makeNode(i, index);
    if (top == NULL) {
        top = tmp;
    } else {
        tmp->next = top;
        top = tmp;
    }
}

void pop() {
    Node *tmp;
    if (top == NULL)
        return;
    else {
        tmp = top;
        top = top->next;
        free(tmp);
    }
}

int Top() {
    if (top != NULL) {
        return top->index;
    } else {
        return -1;
    }
}

int main() {
    int n; scanf("%d", &n);
    int a[n];
    for (int i = 0 ;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    int max_area = 0;
    int i = 0;
    while (i < n) {
        if (top == NULL || a[Top()] <= a[i]) {
            push(a[Top()], i);
            i++;
        } else {
            int r = i;
            int minHeight = a[Top()];
            pop();
            int l = top == NULL ? 0 : Top()+1;
            int area = minHeight * (r - l);
            if (area > max_area) {
                max_area = area;
            }
        }
    }
    while (top != NULL) {
        int r = n;
        int minHeight = a[Top()];
        pop();
        int l = top == NULL ? 0 : Top()+1;
        int area = minHeight * (r - l);
        if (area > max_area) {
            max_area = area;
        }
    }
    printf("%d", max_area);

    return 0;
}
