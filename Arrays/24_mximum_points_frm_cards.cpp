// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

// Example 1:

// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
// Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

#include <bits/stdc++.h>
using namespace std;
// Recursive

// if(k==0)
//     return 0;
// return max(arr[l]+fun(l+1,r,k-1),arr[r]+fun(l,r-1,k-1));

// Prefix Sum Approach:
class Solution
{
    public:
        int maxScore(vector<int> &cardPoints, int k)
        {
            int n = cardPoints.size();

            vector<int> forward_sum(n + 1, 0);
            vector<int> backward_sum(n + 1, 0);

            for (int i = 0; i < n; ++i)
            {
                forward_sum[i + 1] = forward_sum[i] + cardPoints[i];
            }

            for (int i = n - 1; i >= 0; --i)
            {
                backward_sum[i] = backward_sum[i + 1] + cardPoints[i];
            }
            int ans = INT_MIN;
            reverse(backward_sum.begin(), backward_sum.end());
            for (int i = 0; i <= k; ++i)
            {
                ans = max(ans, backward_sum[i] + forward_sum[k - i]);
            }
            return ans;
        }
};

// O(n) Solution Sliding Window Technique.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,ans=0;
        int n=cardPoints.size();
        
        for(int i=0;i<k;i++) sum+=cardPoints[i];
        
        ans=sum;
        int i=n-1;
        for(int j=k-1;j>=0;j--){
            sum-=cardPoints[j];
            sum+=cardPoints[i];
            i--;
            ans=max(ans,sum);
        }
        return ans;
    }
};