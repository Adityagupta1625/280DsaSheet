// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Brute Force:
//Store i and j of zero in vector and traverse matrix if that row or col is in vector set entire row or column zero.

// optimised:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        bool r=false,c=false;
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0) r=true;
        }
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0) c=true;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    if(i==0) r=true;
                    
                    if(j==0) c=true;
                    
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                } 
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                   matrix[i][j]=0;
                }  
            }
        }
        
        if(r){
            for(int i=0;i<m;i++)  matrix[0][i]=0;
        }
        if(c){
            for(int j=0;j<n;j++) matrix[j][0]=0;
        }
    }
};