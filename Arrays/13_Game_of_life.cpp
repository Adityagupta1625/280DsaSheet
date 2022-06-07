#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    bool isSafe(int i,int j,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m) return true;
        return false;
    }
    int solve(vector<vector<int>>& board,int i,int j){
        int cnt=0;
        int n=board.size();
        int m=board[0].size();
        
        for(int k=0;k<8;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            
            if(isSafe(x,y,n,m) && (board[x][y]==1 || board[x][y]==2)) cnt++;
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int cnt=0;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                cnt=0;
                cnt=solve(board,i,j);
                
                if(cnt<2 && board[i][j]==1) board[i][j]=2;
                
                else if(board[i][j]==0 && cnt==3) board[i][j]=3;
                
                else if(board[i][j]==1 && cnt>3) board[i][j]=2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) board[i][j]=board[i][j]%2;
        }
    }
};