#include <iostream>
using namespace std;
int exponentiation(int s, int e) {
    if (e == 0)
        return 1;
    return s * exponentiation(s, e-1);
} 

int main (){
    int n,m;
    //input from user.
    cout<< "Enter a number 2 Number ";
    cin >> n >> m;
    int result =exponentiation(n,m);
    cout<< "Result "<<result;


}