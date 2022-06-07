// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


// Brute Force o(n^3):
// Go for all subarrays and check if sum equals k, two loops fix i and j and then third loop compute sum from i to j and check if it is divisble by k or not.

// Better Solution:
// Store prefix sum instead take sum[j]-sum[i] and check if it is divisble by k or not.


// Optimised Solution:

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]=1;
        
        int sum=0;
        int cnt=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            int rem=sum%k;
            
            if(rem<0) rem+=k;
            
            if(m[rem]) cnt+=m[rem];
            
            m[rem]++;
        }
        return cnt;
    }
};
