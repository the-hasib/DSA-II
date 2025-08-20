#include <iostream>
using namespace std;

int findSumDC(int arr[], int i, int j) {
    if (i == j)
        return arr[i];
    int mid = (i + j) / 2;
    int leftSum = findSumDC(arr, i, mid);
    int rightSum = findSumDC(arr, mid + 1, j);
    return leftSum + rightSum;
}

int main() {
    int n;
    cout<< "Enter input element size:";
    cin >> n;
    cout <<"Enter your "<<n<<" number's :" ;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << findSumDC(arr, 0, n - 1) << endl;
}
