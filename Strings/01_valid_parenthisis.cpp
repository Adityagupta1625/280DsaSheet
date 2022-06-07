#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isopen(char e){
        if(e=='(' || e=='{' || e=='[')
            return 1;
        return 0;
    }
    int ismatching(char e1,char e2){
        if(e1=='(' && e2==')')
            return 1;
        else if(e1=='{' && e2=='}')
            return 1;
        else if(e1=='[' && e2==']')
            return 1;
        else
            return 0;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(isopen(s[i]))
                st.push(s[i]);
            else{
                if(!st.empty()){
                    char exp=st.top();
                    st.pop();
                    if(!ismatching(exp,s[i]))
                        return false;
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};

