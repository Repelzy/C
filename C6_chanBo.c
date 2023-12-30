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

int canPlaceCows(int x){
    int pos = a[0];
    int cow = 1;
    for(int i = 1; i < n; i++){
        if(a[i]-pos >= x){
            cow++;
            pos = a[i];
            if(cow == c){
                return 1;
            }
        }
    }
    return 0;
}

int binarySearch(){
    int lo = 0;
    int hi = a[n-1] - a[0];
    int res = -1;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(canPlaceCows(mid)){
            res = mid;
            lo = mid + 1;
        }
        else{
            hi = mid -1;
        }
    }
    return res;
}

int main() {
    srand(time(NULL));
    scanf("%d %d", &n, &c);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    int result = binarySearch();
    printf("%d\n", result);
    return 0;
}
