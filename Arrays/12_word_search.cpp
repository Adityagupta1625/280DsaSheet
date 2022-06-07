// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int i,int j,vector<vector<char>>& board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() 
           || board[i][j]=='0') 
            return false;
        return true;
    }
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int k){
        if(k==word.size()) return true;
        
        bool f=false;
        
        char c=board[i][j];
        board[i][j]='0';
        
        if(isSafe(i+1,j,board) && board[i+1][j]==word[k] && f==false)
            f=dfs(board,word,i+1,j,k+1);
        
         if(isSafe(i-1,j,board) && board[i-1][j]==word[k] && f==false)
            f=dfs(board,word,i-1,j,k+1);
        
         if(isSafe(i,j+1,board) && board[i][j+1]==word[k] && f==false)
            f=dfs(board,word,i,j+1,k+1);
        
         if(isSafe(i,j-1,board) && board[i][j-1]==word[k] && f==false)
            f=dfs(board,word,i,j-1,k+1);
        
        board[i][j]=c;
        return f;
    }
    bool exist(vector<vector<char>>& board, string word) {
       
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]) 
                    if(dfs(board,word,i,j,1)) return true;
            }
        }
       
        return false;
    }
};