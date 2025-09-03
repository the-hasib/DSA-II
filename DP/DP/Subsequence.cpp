#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0; 
    int j = 0; 

    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++; 
    }

   
    return i == s.length();
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    if (isSubsequence(s, t)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
