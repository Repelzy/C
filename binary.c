#include <stdio.h>

int Bise(int arr[], int size, int target);

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7, 8, 16, 18, 19, 20, 23, 34, 56};
    int target = 20;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = Bise(arr, size, target);

    if (result == -1)
        printf("Target element not found.\n");
    else
        printf("Target element found at index %d.\n", result);

    return 0;
}

int Bise(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

