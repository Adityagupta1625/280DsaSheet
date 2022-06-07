// You are given N number of books. Every ith book has Ai number of pages.

// You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

// Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in 
// following ways:{12} and {34, 67, 90} 
// Maximum Pages = 191{12, 34} and {67, 90} 
// Maximum Pages = 157{12, 34, 67} and {90} 
// Maximum Pages =113. Therefore, the minimum 
// of these cases is 113, which is selected 
// as the output.


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool check(int a[], int m, int n,int ans){
        int s=0,cnt=1;
        
        for(int i=0;i<n;i++){
            if(a[i]>ans) return false;
            
            if(a[i]+s>ans){
                s=a[i];
                cnt++;
                
                if(cnt>m) return false;
            }
            else s+=a[i];
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        
        long long int sum=0;
        
        for(int i=0;i<N;i++) sum+=A[i];
        
        long long int l=1,h=sum;
        long long int ans=1;
        
        while(l<=h){
            long long int m=(l+h)/2;
            
            if(check(A,M,N,m)){
                h=m-1;
                ans=m;
            }
            else l=m+1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}