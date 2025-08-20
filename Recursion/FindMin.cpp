#include <stdio.h>

int findMinimum(int arr[], int n) {
    if (n == 1)
        return arr[n-1];
    int x = findMinimum(arr, n - 1);
    int y = arr[n - 1];
    return x < y ? x : y;
}

int main() {
    int arr[] = {12, 5, 7, 3, 19, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min = findMinimum(arr, n);

    printf("The minimum value in the array is: %d\n", min);

    return 0;
}
