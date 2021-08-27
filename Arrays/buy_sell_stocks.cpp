// Find maximum Profit by choosing one day to buy and one day to sell the stock

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int maxProfit(vector<int>& prices);

// Main Function 
int main(){
    int days;
    cin >> days;

    vector<int> prices_of_stocks;
    for(int i=0;i<days;i++){
        int a;
        cin >> a;

        prices_of_stocks.push_back(a);
    }

    cout << maxProfit(prices_of_stocks) << endl;

    return 0;
}

// Time Complexity - O(n), Space Complexity - O(1)
int maxProfit(vector<int>& prices) {
    int min_so_far = prices.front(), max_profit = 0;
        
    for(int i=1;i<prices.size();i++){
        if(min_so_far > prices[i]){
            min_so_far = prices[i];
        }
        
        if(max_profit < prices[i]-min_so_far){
           max_profit = prices[i]-min_so_far;
        }
    }
        
    return max_profit;
}