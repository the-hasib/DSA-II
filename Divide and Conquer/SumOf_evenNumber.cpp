#include <iostream>
using namespace std;

int D(int arr[], int i, int j) {
    if (i == j) {
        if (arr[i] % 2 == 0) return arr[i];
        return 0;
    }
    int mid = (i + j) / 2;
    int leftSum = D(arr, i, mid);
    int rightSum = D(arr, mid + 1, j);
    return leftSum + rightSum;
}

int main() {
    int n;
    cout<<"Enter array size :";
    cin >> n;
    int arr[n];
    cout << "Enter number ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout <<"Output :"<< D(arr, 0, n - 1) << endl;
    return 0;
}
