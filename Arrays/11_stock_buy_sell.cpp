// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// O(n) && O(n) solution:

// Take a dp table with max from right and then take price accordingly.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 int maxProfit(vector<int> &prices)
    {
    vector<int> sub;
    int maxprof = 0;
        int n = prices.size();
        int min_so_far = prices[0];
        for (int i = 0; i < n; i++)
        {
            /* code */
            min_so_far=min(min_so_far,prices[i]);
            int sell = prices[i] - min_so_far;
            maxprof = max(sell, maxprof);
        }
        return maxprof;
 }
};