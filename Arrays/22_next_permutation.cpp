#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach:
// Find out all permutations store it in array return next permutations.

// o(n) solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int idx=-1;
        int n=nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int prev=-1;
        for(int i=idx;i<n;i++){
            if(nums[i]>nums[idx-1] ){
                if(prev!=-1){
                    if(nums[prev]>=nums[i]) prev=i;
                }
                else prev=i;
            }
        }
        
        swap(nums[idx-1],nums[prev]);
        reverse(nums.begin()+idx,nums.end());
    }
};
