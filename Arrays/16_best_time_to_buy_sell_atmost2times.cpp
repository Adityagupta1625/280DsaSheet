// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

// Brute Force:
// Take two loops find out 0 to j and j to i and take max out of it.

// o(n) + O(n) solution:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<int> profit(n,0);
        
        int maxprice=prices[n-1];
        
        for(int i=n-2;i>=0;i--){
            maxprice=max(maxprice,prices[i]);
            profit[i]=max(profit[i+1],maxprice-prices[i]);
        }
       
        int minprice=prices[0];
        
        for(int i=1;i<n;i++){
            minprice=min(minprice,prices[i]);
            profit[i]=max(profit[i-1],profit[i]+(prices[i]-minprice));
        }
        
        return profit[n-1];
    }
};

// o(n) solution:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first_buy=INT_MIN,second_buy=INT_MIN,first_sell=0,
        second_sell=0;
        
        for(int i=0;i<prices.size();i++){
              first_buy=max(first_buy,-prices[i]);
              first_sell=max(first_sell,prices[i]+first_buy);
              second_buy=max(second_buy,first_sell-prices[i]);
              second_sell=max(second_sell,prices[i]+second_buy);
        }
        return second_sell;
        
    }
};