#include <iostream>
using namespace std;

int combination(int n, int r) {
    if (r == 0 or r == n)
        return 1;
    return combination(n-1, r-1) + combination(n-1, r);
}

int main() {
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;

    if (r > n || n < 0 || r < 0) {
        cout << "Invalid input. Make sure 0 <= r <= n." << endl;
        return 1;
    }

    int result = combination(n, r);
    cout << "Combination C(" << n << ", " << r << ") = " << result << endl;

    return 0;
}
