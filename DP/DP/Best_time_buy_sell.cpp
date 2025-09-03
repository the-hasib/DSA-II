#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& stockPrices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < stockPrices.size(); i++) {
        int todayPrice = stockPrices[i];

        if (todayPrice < minPrice) {
            minPrice = todayPrice;  
        } else {
            int currentProfit = todayPrice - minPrice;
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;  
            }
        }
    }

    return maxProfit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> stockPrices(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> stockPrices[i];
    }

    int answer = maxProfit(stockPrices);
    cout << "Maximum Profit: " << answer << endl;

    return 0;
}
