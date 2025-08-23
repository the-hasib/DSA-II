#include<iostream>
using namespace std;

int countEven(int arr[], int start, int end) {
    if (start == end) {
        if (arr[start] % 2 == 0) return 1;
        return 0;
    }
    int mid = (start+end)/2;
    int leftCount = countEven(arr, start, mid);
    int rightCount = countEven(arr, mid+1, end);
    return leftCount + rightCount;
}

int main() {
    int arr[] = {1, 2, 4, 7, 8, 10};
    int n = 6;
    cout << "Even count: " << countEven(arr, 0, n-1) << endl;
    return 0;
}
