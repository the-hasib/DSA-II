#include <iostream>
using namespace std;

int findMax(vector<int>& arr, int l, int r) {
    if (l == r) return arr[l]; 

    int mid = (l + r) / 2;
    int leftMax = findMax(arr, l, mid);
    int rightMax = findMax(arr, mid + 1, r);

    return max(leftMax, rightMax);
}

int main() {
    vector<int> arr = {2, 8, 5, 1, 10, 3};
    cout << "Maximum element = " << findMax(arr, 0, arr.size() - 1) << endl;
    return 0;
}
