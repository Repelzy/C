#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandom(int low, int high) {
    return low + rand() % (high - low + 1);
}

void swap(int arr[], int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int partition(int arr[], int left, int right) {
    int randomIndex = getRandom(left, right);
    swap(arr, randomIndex, right);

    int pivot = arr[right];
    int lo = left - 1;
    int ro = right;

    while (1) {
        while (arr[++lo] < pivot);
        while (arr[--ro] > pivot && ro > 0);
        if (lo >= ro) break;
        else {
            swap(arr, lo, ro);
        }
    }

    swap(arr, lo, right);
    return lo;
}

void quickSort(int arr[], int left, int right) {
    if (right - left <= 0) return;
    else {
        int par = partition(arr, left, right);
        quickSort(arr, left, par - 1);
        quickSort(arr, par + 1, right);
    }
}

int main() {
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d ", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
