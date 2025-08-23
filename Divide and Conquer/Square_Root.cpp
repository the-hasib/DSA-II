#include<bits/stdc++.h>
using namespace std;

double findSqrt(double n, double low, double high) {
    if (high - low < 0.0000001)
        return high;
    double mid = (low+high)/2.0;
    if (mid*mid < n)
        return findSqrt(n, mid, high);
    return findSqrt(n, low, mid);
}

int main() {
    double n = 50;
    cout << "Sqrt of " << n << " = " << findSqrt(n, 0, n) << endl;
    return 0;
}
