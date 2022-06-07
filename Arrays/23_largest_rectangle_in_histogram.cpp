// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

#include <bits/stdc++.h>
using namespace std;

// Brute force:
// Pick an element go towards its left and right for first smaller than this and do (right-left+1)*v[i]

// Auxilary vector for left and right min indexes.
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack<int> st;
        int n=v.size();
        vector<int> ps,ns(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && v[st.top()]>=v[i]) st.pop();
            
            if(st.empty()){
                ps.push_back(-1);
            }
            else{
                ps.push_back(st.top());
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && v[st.top()]>=v[i]) st.pop();
            
            if(st.empty()){
                ns[i]=n;
            }
            else{
                ns[i]=st.top();
            }
            st.push(i);
        }
        
        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,(ns[i]-ps[i]-1)*v[i]);
        }
        
        return maxarea;
    }
};

// using stack only:
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack<int> st;
        int n=v.size();
        int maxarea=0;
        int i=0;
        while(i<n){
           if(st.empty() || v[st.top()]<=v[i]){
               st.push(i);
               i++;
           }
            else{
               int height=v[st.top()];
                st.pop();
                int width=st.empty() ? i : i-st.top()-1;
                maxarea=max(maxarea,height*width);
            }
          
        }
        
        while(!st.empty()){
             int height=v[st.top()];
             st.pop();
             int width=st.empty() ? i : i-st.top()-1;
             maxarea=max(maxarea,height*width);
        }
        return maxarea;
    }
};

