#include <iostream>
#include <string>
using namespace std;

string reverseString(const string& str, int start, int end) {
    // Base case
    if (start >= end) {
        if (start == end) {
            return string(1, str[start]);
        }
        return "";
    }
    
    // Recursive case
    return str[end] + reverseString(str, start, end - 1);
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string reversed = reverseString(input, 0, input.size() - 1);

    cout << "Original: " << input << endl;
    cout << "Reversed: " << reversed << endl;

    return 0;
}
