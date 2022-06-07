// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Rotate cell approach:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0;i<(n+1)/2;i++){
            for(int j=0;j<n/2;j++){
                int temp=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=matrix[i][j];
                matrix[i][j]=temp;
            }
        }
    }
};

// Approach 2:
// Take the transpose and then reverse the rows

// Approach 3:
// Take transpose and reflect about the diagonal

// relfect code:
//   int n = matrix.length;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n / 2; j++) {
//                 int tmp = matrix[i][j];
//                 matrix[i][j] = matrix[i][n - j - 1];
//                 matrix[i][n - j - 1] = tmp;
//             }
//         }
