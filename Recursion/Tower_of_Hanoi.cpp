#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }

    // Step 1: Move n-1 disks from 'from' to 'aux'
    towerOfHanoi(n-1, from, aux, to);

    // Step 2: Move nth disk from 'from' to 'to'
    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    // Step 3: Move n-1 disks from 'aux' to 'to'
    towerOfHanoi(n-1, aux, to, from);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\nSteps to solve Tower of Hanoi with " << n << " disks:\n";
    towerOfHanoi(n, 'A', 'C', 'B'); // From A → C using B
    return 0;
}
