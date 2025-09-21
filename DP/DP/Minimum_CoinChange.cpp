#include <iostream>
using namespace std;

int main() {
    int n, amount;
    cout << "Enter number of coins and amount: ";
    cin >> n >> amount;

    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    vector<int> dp(amount+1, 1e9); 
    dp[0] = 0;

    for(int i=1; i<=amount; i++){
        for(int c: coins){
            if(i-c >= 0){
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }

    if(dp[amount] == 1e9) cout << "Not possible" << endl;
    else cout << "Minimum coins needed = " << dp[amount] << endl;
}
