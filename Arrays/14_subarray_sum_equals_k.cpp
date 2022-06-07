// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2 

// Brute Force o(n^3):
// Go for all subarrays and check if sum equals k. two loops fix i and j and then third loop compute sum from i to j.

// Better Solution:
// Store prefix sum instead take sum[j]-sum[i] and check if it is equal to k or not.


// o(n)+ o(n) solution:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        
        map<int,int> m;
        m[0]=1;
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(m[sum-k]>0) cnt+=m[sum-k];
            
            m[sum]++;
        }
        return cnt;
    }
};


