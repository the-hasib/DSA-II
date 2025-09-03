#include <iostream>
#include <vector>
using namespace std;

int countOnes(int num) {
    int count = 0;
    while (num) {
        count += num & 1; 
        num >>= 1;        
    }
    return count;
}

vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++) {
        ans[i] = countOnes(i);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> result = countBits(n);

    cout << "[";
    for (int i = 0; i <= n; i++) {
        cout << result[i];
        if (i != n) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
