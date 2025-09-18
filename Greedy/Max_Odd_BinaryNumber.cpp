/*You are given a binary string s that contains at least one '1'.
You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
Return a string representing the maximum odd binary number that can be created from the given combination.*/

#include <iostream>
#include <string>
using namespace std;

string maximumOddBinaryNumber(string s) {
    int ones = 0, zeros = 0;
    for (char c : s) {
        if (c == '1') ones++;
        else zeros++;
    }
    return string(ones - 1, '1') + string(zeros, '0') + "1";
}

int main() {
    string s;
    cout<<"Enter Number :";
    cin >> s;
    cout << maximumOddBinaryNumber(s);
    return 0;
}
