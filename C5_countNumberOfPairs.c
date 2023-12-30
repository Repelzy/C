#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n, Q; 
int a[1000001]={0};

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

int binarySearch(int L, int R, int Y){
    int tmpL = L;
    int tmpR = R;
    while (tmpL <= tmpR)
    {
        int mid = tmpL + (tmpR - tmpL) / 2;
        if (a[mid] == Y)
            return 1;
        if (a[mid] < Y)
            tmpL = mid + 1;
        else
            tmpR = mid - 1;
    }
    return 0;
}


void solve(){
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        int valid = binarySearch(i+1, n, Q-a[i]);
        cnt += valid;
    }
    printf("%d", cnt);
}

int main(){
    srand(time(NULL));
    scanf("%d %d", &n, &Q);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n-1);
    solve();
}
