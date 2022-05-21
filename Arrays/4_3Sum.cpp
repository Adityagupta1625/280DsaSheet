// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]


// Brute Force o(n^3):
// Take three loops and check if sum is equal to 0 or not and push to vector if zero.

// o(n^2) time and o(n) space:
// Take a hashmap and perform 2 sum such that 3rd term is obtained from the hashmap.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++) m[nums[i]]=i;
        
        for(int i=0;i<n-2;i++){
            if(nums[i]>0) break;
            
            if(i>0 && nums[i-1]==nums[i]) continue;
            
            for(int j=i+1;j<n;j++){
               
                int sum=-(nums[i]+nums[j]);
             
                if(m.find(sum)!=m.end() && m[sum]>j)                           
                    ans.push_back({nums[i],nums[j],sum}); 
                
                j=m[nums[j]];
            }
        }
        
        return ans;
    }
};

// o(n^2) and o(1):

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        vector<vector<int>> ans;
        
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n;
            
            if(i>0 && nums[i]==nums[i-1]) i++;
            
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                   
                    while(j<k && nums[j+1]==nums[j]) j++;
                    
                    while(j<k && nums[k]==nums[k-1]) k--;
                    
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0) k--;
                
                else j++;
               
            }
        }
        return ans;
    }
};

