// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// DFS Approach:
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool safe(vector<vector<char>>& grid,int i,int j){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()
           && grid[i][j]=='1') return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='0';
        
        if(safe(grid,i+1,j)) dfs(grid,i+1,j);
        
        if(safe(grid,i-1,j)) dfs(grid,i-1,j);
        
        if(safe(grid,i,j+1)) dfs(grid,i,j+1);
        
        if(safe(grid,i,j-1)) dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};

// BFS Approach:
class Solution {
public:
    int ans=0;
    int DC[4]={0, 1, 0, -1};
    int DR[4]={1, 0, -1, 0};
    int find(vector<int>& parent,int i){
        if(parent[i]==i)
            return i;
        return parent[i]=find(parent,parent[i]);
    }
    
    void Union(vector<int>& parent,int x,int y){
        int a=find(parent,x);
        int b=find(parent,y);
        
        if(a==b) return;
        
        parent[a]=b;
        ans--;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> par(n*m);
        
        
        for(int i=0;i<n*m;i++) par[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    int spot=(i*m)+j;
                    for(int k=0;k<4;k++){
                        int x=i+DR[k];
                        int y=j+DC[k];
                        
                         if(x<0 || y<0 || x>=n || y>=m)
                             continue;
                         if(grid[x][y]=='1'){
                             Union(par,spot,(x*m)+y);
                         } 
                         
                    }
                }  
            }
        }
        
        return ans;
    }
};