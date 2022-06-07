// Given an m x n matrix, return all elements of the matrix in spiral order.

#include <bits/stdc++.h>
using namespace std;

//Approach 1:
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int di=0;
        
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        
        int r=matrix.size();
        int c=matrix[0].size();
        
        vector<int> res;
        
        int row=0,col=0;
        
        for(int i=0;i<r*c;i++){
            res.push_back(matrix[row][col]);
            
            matrix[row][col]=INT_MIN;
            
            int nr=row+dr[di];
            int nc=col+dc[di];
            
            if(nr>=0 && nr<r && nc>=0 && nc<c && matrix[nr][nc]!=INT_MIN){
                row=nr;
                col=nc;
            }
            else{
                di=(di+1)%4;
                row=row+dr[di];
                col=col+dc[di];
            }
        }
        return res;
    }
};

// Approach 2:
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int i=0,j=0;
        
        int n=matrix.size()-1;
        int m=matrix[0].size()-1;
        int c=0;
        int total=(n+1)*(m+1);
        while(i<=n && j<=m){
            
           for(int k=j;c<total&& k<=m;k++){
               ans.push_back(matrix[i][k]);
               c++;
           }
           i++;
            
           for(int k=i;c<total && k<=n;k++){
               ans.push_back(matrix[k][m]);
               c++;
           }
           m--;
           
            for(int k=m;c<total && k>=j;k--){
                c++;
                ans.push_back(matrix[n][k]);
            }
             n--;
            
            for(int k=n;c<total && k>=i;k--){
                ans.push_back(matrix[k][j]);
                c++;
            }   
            j++; 
        }
        return ans;
    }
    
};

// DFS Approach:
class Solution {
public:
    bool vis[11][11];
    void solve(vector<vector<int>>& matrix,vector<int>& ans,
              int i,int j){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size()
           || vis[i][j]==true)
           return;
        
        vis[i][j]=true;
        ans.push_back(matrix[i][j]);
        solve(matrix,ans,i,j+1);
        
        solve(matrix,ans,i+1,j);
        
        solve(matrix,ans,i,j-1);
        
        while(i>0 && vis[i-1][j]==false){
            ans.push_back(matrix[i-1][j]);
            vis[i-1][j]=true;
            i--;
        }
        solve(matrix,ans,i,j+1);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        memset(vis,false,sizeof(vis));
        solve(matrix,ans,0,0);
        return ans;
    }
    
};