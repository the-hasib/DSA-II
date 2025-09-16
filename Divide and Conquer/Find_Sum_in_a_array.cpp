#include <iostream>
using namespace std;

// Divide & Conquer sum
int findSum(int arr[], int i, int j) {
    if (i == j) 
        return arr[i];

    int mid = (i + j) / 2;

    int leftSum = findSum(arr, i, mid);    
    int rightSum = findSum(arr, mid + 1, j);

    return leftSum + rightSum; 
}

int main() {
    int n;
    cout << "Enter input element size: ";
    cin >> n;

    int arr[n];
    cout << "Enter your " << n << " numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Sum of array = " << findSum(arr, 0, n - 1) << endl;

    return 0;
}
