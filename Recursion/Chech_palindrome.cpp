#include <iostream>
using namespace std;
bool checkPalindrome(string s, int start, int end) {
    if (start == end or start > end)
        return true;
    return s[start] == s[end] and checkPalindrome(s, start+1, end-1);
}


int main (){
   
    //input from user.
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (checkPalindrome(s, 0, s.length() - 1))
        cout << s << " is a palindrome." << endl;
    else
        cout << s << " is not a palindrome." << endl;

    return 0;
}