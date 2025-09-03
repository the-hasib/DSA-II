#include <iostream>
using namespace std;

long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long a = 0; 
    long long b = 1; 
    long long c;

    for (int i = 2; i <= n; i++) {
        c = a + b; 
        a = b;     
        b = c;     
    }

    return c;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "F(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
