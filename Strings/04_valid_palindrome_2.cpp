// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        
        while(i<j){
            if(s[i]!=s[j]){
                return check(s,i+1,j) || check(s,i,j-1);
            }
            else{
                i++;
                j--;
            }
            
        }
        return true;
    }
};