#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, c;
int a[100001] = {0};

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

int binarySearch(int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == key) {
            return mid + 1; 
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low; 
}

int main() {
    srand(time(NULL));
    scanf("%d %d", &n, &c);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < c; i++) {
        int A, B;
        scanf("%d %d", &A, &B);

        int count = binarySearch(B) - binarySearch(A - 1);

        printf("%d\n", count);
    }

    return 0;
}
