#include <iostream>
#include <vector>
using namespace std;

int D(const vector<int>& arr, int i, int j) {
    if (i == j) {
        if (arr[i] % 3 == 0) return arr[i]; 
        return 0;
    }
    int mid = (i + j) / 2;
    int leftSum = D(arr, i, mid);
    int rightSum = D(arr, mid + 1, j);
    return leftSum + rightSum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << D(arr, 0, n - 1) << endl;
    return 0;
}
