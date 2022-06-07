// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

// You may return the answer in any order.

// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// Take leave approach

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& ans,vector<int> res,int n,int k,int start){
        if(res.size()==k){
            ans.push_back(res);
            return;
        }
        
        if(start>n) return;
        
        res.push_back(start);
        dfs(ans,res,n,k,start+1);
        res.pop_back();
        
        dfs(ans,res,n,k,start+1);
    }

// backtracking solution:
 void dfs(vector<vector<int>>& ans,vector<int> res,int n,int k,
             int start){
        if(res.size()==k) ans.push_back(res);
        
        for(int i=start;i<=n;i++){
            res.push_back(i);
            dfs(ans,res,n,k,i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        
        dfs(ans,res,n,k,1);
        return ans;
    }