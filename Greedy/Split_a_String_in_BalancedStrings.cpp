#include <iostream>
using namespace std;

int balancedStringSplit(string s) {
    int balance = 0, count = 0;

    for (char c : s) {
        if (c == 'R') balance++;
        else balance--;

        if (balance == 0) {
            count++; // found a balanced substring
        }
    }
    return count;
}

int main() {
    string s = "RLRRRLLRLL";
    cout << "Maximum balanced substrings = " << balancedStringSplit(s) << endl;
    return 0;
}
