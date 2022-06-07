// Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. Solve it without division operator in O(n) time.

// Example :

// Input: arr[]  = {10, 3, 5, 6, 2}
// Output: prod[]  = {180, 600, 360, 300, 900}
// 3 * 5 * 6 * 2 product of other array
// elements except 10 is 180
// 10 * 5 * 6 * 2 product of other array
// elements except 3 is 600
// 10 * 3 * 6 * 2 product of other array
// elements except 5 is 360
// 10 * 3 * 5 * 2 product of other array
// elements except 6 is 300
// 10 * 3 * 6 * 5 product of other array
// elements except 2 is 900

#include <bits/stdc++.h>
using namespace std;

// Brute Force:
// Find product for each element by going through its left and right.

// Two arrays left and right.
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    // code here
    vector<long long int> left, right, v;
    long long int prod = 1;
    left.push_back(1);
    for (int i = 1; i < nums.size(); i++)
    {
        left.push_back(left[i - 1] * nums[i - 1]);
    }
    int k = 0;
    right.push_back(1);
    for (int i = n - 2; i >= 0; i--)
    {
        right.push_back(right[k] * nums[i + 1]);
        k++;
    }
    reverse(right.begin(), right.end());

    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back(left[i] * right[i]);
    }

    return v;
}

// Single array

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long int> v;
       vector<long long int> left;
       
       left.push_back(1);
       for(int i=1;i<n;i++)
           left.push_back(left[i-1]*nums[i-1]);
       
       v.push_back(left[n-1]);
       for(int i=n-2;i>=0;i--){
           v.push_back(nums[i+1]*left[i]);
           nums[i]=nums[i+1]*nums[i];
       }
       reverse(v.begin(),v.end());
       return v;
        //code here        
    }

// O(1) Space:
 vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long int> v;
       
       int flag=0;
       long long int prod=1;
       
       for(int i=0;i<nums.size();i++){
           if(nums[i]==0){
               flag++;
           }else{
               prod=prod*nums[i];
           }
       }
       
       for(int i=0;i<n;i++){
           if(flag>1){
               v.push_back(0);
           }
           else if(flag==1){
               if(nums[i]==0) v.push_back(prod);
               
               else v.push_back(0);
           }
           else{
               v.push_back(prod/nums[i]);
           }
       }
       return v;
        //code here        
    }