// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3


// Sort:

// o(nlogn) time
// Simply sort and check the adjacent elements if equal return true.

// Hasmap/Set:

// o(n) time + o(n) space
// Store values in hasmap and check count if count>1 return val
// In set approach insert and search simuntenously.

// optimised:

// mark negative the index if already negative then return nums[i] see constraints for this solution

// o(n) time solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0) return abs(nums[i]);
            
            else nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return -1;
        
    }
};

// using slow and fast pointer approach

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow=nums[0],fast=nums[0];
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return slow;
    }
};