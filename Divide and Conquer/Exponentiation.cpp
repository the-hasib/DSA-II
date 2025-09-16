#include <iostream>
using namespace std;

long long D(long long b, long long n) {
    if (n == 0) return 1;

    long long half = D(b, n / 2); 
    if (n % 2 == 0) return half * half; 
    else return b * half * half; 
}

int main() {
    long long b, n;
    cin >> b >> n;
    cout << D(b, n) << endl;
    return 0;
}
