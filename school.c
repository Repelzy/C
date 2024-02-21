#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000  

int a[MAX_SIZE];

int getRandom(int low, int high) {
    return low + rand() % (high - low + 1);
}

void swap(int x, int y) {
    if (a[x] != a[y]) {
        int tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
    }
}

int partition(int left, int right) {
    int randomIndex = getRandom(left, right);
    swap(randomIndex, right);

    int pivot = a[right];
    int lo = left - 1;
    int ro = right;

    while (1) {
        while (a[++lo] < pivot);
        while (a[--ro] > pivot && ro > 0);
        if (lo >= ro) break;
        else {
            swap(lo, ro);
        }
    }

    swap(lo, right);
    return lo;
}

void quickSort(int left, int right) {
    if (right - left <= 0) return;
    else {
        int par = partition(left, right);
        quickSort(left, par - 1);
        quickSort(par + 1, right);
    }
}

int main() {
    
    srand(time(NULL));
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quickSort(0, n - 1);

    int maxCost = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        int tmp = (n-i)*a[i];
        if(tmp > maxCost){
            maxCost = tmp;
            j = i;
        }
    }
    printf("%d %d\n", maxCost, a[j]);

    return 0;
}
