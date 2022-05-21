// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Brute Force:
// Pick every element and check using an inner loop.

// Sorting
// n/2 position of  array will always have majority element

// hashmap 
// maintain an hashmap if count becomes > n/2 then return element.

// Booyer Moore Voting Element
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=-1;
        
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            if(count==0) candidate=nums[i];
            
            if(candidate==nums[i]) count++;
            
            else count--;
        }
    
        return candidate;
    }
};