#include <iostream>
using namespace std;

int longestPalindrome(string s) {
   
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    int length = 0;     
    bool hasOdd = false;

    
    for (auto &entry : freq) {
        int count = entry.second;

        if (count % 2 == 0) {
           
            length += count;
        } else {
            
            length += count - 1;
            hasOdd = true;
        }
    }

  
    if (hasOdd) length += 1;

    return length;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int ans = longestPalindrome(s);

    cout << "Longest Palindrome Length = " << ans << endl;

    return 0;
}
