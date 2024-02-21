#include <stdio.h>
#define MAX 100000

int a[MAX];
int size = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pushDown(int i, int N) {
    int min = i;
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    if (L < N && a[L] < a[min]) {
        min = L;
    }
    if (R < N && a[R] < a[min]) {
        min = R;
    }
    if (min != i) {
        swap(&a[min], &a[i]);  
        pushDown(min, N);
    }
}

void pushUp(int i) {
    int parent = (i - 1) / 2;
    while (i > 0 && a[i] < a[parent]) {
        swap(&a[i], &a[parent]);  
        i = parent;
        parent = (i - 1) / 2;
    }
}

void enqueue(int x) {
    if (size == MAX) {
        return;
    }
    a[size] = x;
    pushUp(size);
    size++;
}

int dequeue() {
    if (size == 0) {
        return -1;
    }
    int min = a[0];
    a[0] = a[size - 1];
    size--;
    pushDown(0, size);
    return min;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        enqueue(a[i]);
    }
    int cost = 0;
    while (size > 1) {  
        int a1 = dequeue();
        int a2 = dequeue();
        cost += (a1 + a2);
        enqueue(a1 + a2);
    }
    printf("%d", cost);
    return 0;
}
