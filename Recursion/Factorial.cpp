#include <iostream>
using namespace std;
int factorial(int n) {
    if (n == 0)
        return 1;
    return n*factorial(n-1);
}

int main (){
    int n;
    //input from user.
    cout<< "Enter a number ";
    cin >> n;
    int result =factorial(n);
    cout<< "Result "<<result;


}