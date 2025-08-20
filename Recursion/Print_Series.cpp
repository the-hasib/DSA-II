#include <iostream>
using namespace std;

int series(int n) {
    if (n == 0)
        return 0;
    return n*n*n*n*n + series(n-1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum of series = " << series(n) << endl;
    return 0;
}
