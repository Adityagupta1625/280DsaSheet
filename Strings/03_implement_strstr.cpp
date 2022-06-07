// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
        
        if(needle.length()==haystack.length()){
            if(needle==haystack) return 0;
            
            return -1;
        }
        int n=haystack.length();
        
        for(int i=0;i<n;i++){
            if(needle[0]==haystack[i] && n-i>=needle.length()){
                string check=haystack.substr(i,needle.length());
                if(check==needle) return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx=-1;
        int n=haystack.length();
        if(needle.length()==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                idx=i;
                for(int j=0;j<needle.length();j++){
                    if(haystack[i+j]!=needle[j]){
                        idx=-1;
                        break;
                    }
                }
                if(idx!=-1)
                    return idx;
            }
        }
        return idx;
    }
};