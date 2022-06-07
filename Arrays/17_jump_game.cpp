// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool solve(vector<int>& nums,int ind,vector<int>& dp){
        if(ind==nums.size()-1) return true;
        
        if(dp[ind]!=-1) return dp[ind];
        
        for(int i=1;i<=nums[ind];i++){
            if(solve(nums,ind+i,dp)) return dp[ind]=true;
        }
        
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,dp); 
    }
};

// o(n) solution:

class Solution {
public:
    
    bool canJump(vector<int>& nums) {
       
        int maxreach=0;
        int n=nums.size();
        int steps=nums[0];
        
        for(int i=0;i<n;i++){
            if(i>maxreach) return false;
            
            maxreach=max(i+nums[i],maxreach);
            
        }
        return true;
    }
};