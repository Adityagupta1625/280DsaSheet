// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


// o(n^4) time
// take four loops and check if sum is zero or not.

// hashmap solution:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
        vector<vector<int>> ans;
        set<vector<int>> us;
        
        if(nums.size()<4) return {};
        
        map<int,int> m;
        
        for(int i=0;i<nums.size();i++) m[nums[i]]=i;
        
        for(int i=0;i<nums.size()-3;i++){
            
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                
                int s=target-(nums[i]+nums[j]);
                for(int k=j+1;k<nums.size()-1;k++){
                     if(k>j+1 && nums[k]==nums[k-1]) continue;
                    
                     vector<int> ans={nums[i],nums[j],nums[k],s-nums[k]};
                     sort(ans.begin(),ans.end());
                    
                     if(m[s-nums[k]] && m[s-nums[k]]!=i && 
                        m[s-nums[k]]!=j && m[s-nums[k]]!=k)  
                         us.insert(ans);
                }
            }
        }
        for(auto i: us) ans.push_back(i);
        
        return ans;
    }
};


// o(n^2) solution:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()<4) return {};
        
        for(int i=0;i<nums.size()-3;i++){
            
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                
                int p=j+1,q=nums.size()-1;
              
                while(p<q){
                     int s=target-(nums[i]+nums[j]);
                
                    if(s<nums[p]+nums[q]) q--;
                    
                    else if(s>nums[p]+nums[q]) p++;
                     
                    else{
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        
                        while(p<q && nums[p]==nums[p+1]) p++;
                        
                        while(p<q && nums[q]==nums[q-1]) q--;
                        
                        p++;
                        q--;
                    }
                }
            }
        }
        return ans;
    }
};
