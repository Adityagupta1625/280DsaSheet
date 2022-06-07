#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2

// O(n^2) Solution:
// Take two loops and check if condition is satisfied or not take count.

// O(nlogn) Solution:
class Solution {
public:
    int merge(vector<int>& nums,int l,int m,int h){
        int j=m+1;
        int cnt=0;
        for(int i=l;i<=m;i++){
            while(j<=h && nums[i]>(long long) 2*nums[j]) j++;
            cnt+=(j-(m+1));
        }
        
        int i=l;
        j=m+1;
        vector<int> tmp;
        while(i<=m && j<=h){
            if(nums[i]<=nums[j]){
                tmp.push_back(nums[i]);
                i++;
            }
            else{
                tmp.push_back(nums[j]);
                j++;
            }
        }
        
        while(i<=m){
            tmp.push_back(nums[i]);
            i++;
        }
        
        while(j<=h){
            tmp.push_back(nums[j]);
            j++;
        }
        
        for(int i=l;i<=h;i++){
            nums[i]=tmp[i-l];
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums,int l,int h){
        if(l>=h) return 0;
        
        int inv_count=0;
        int m=(l+h)/2;
        
        inv_count+=mergeSort(nums,l,m);
        inv_count+=mergeSort(nums,m+1,h);
        inv_count+=merge(nums,l,m,h);
        
        return inv_count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};