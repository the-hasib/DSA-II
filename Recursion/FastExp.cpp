#include <iostream>
using namespace std;

int fastExp(int b, int e) {
    if (e == 0)
        return 1; // Base case: b^0 = 1

    int prod = fastExp(b, e / 2);

    if (e % 2 == 0) // even power
        return prod * prod;
    else            // odd power
        return prod * prod * b;
}

int main() {
    int base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    int result = fastExp(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;

    return 0;
}
