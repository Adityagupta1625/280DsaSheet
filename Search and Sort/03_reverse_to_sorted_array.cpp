#include<bits/stdc++.h>
using namespace std;
 
bool checkReverse(int arr[], int n)
{
    if(n==1) return true;

    int start=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]) start=i-1;
    }

    int end=0;
    for(int i=start+1;i<n;i++){
        if(arr[i]>arr[i-1]) end=i-1;
    }

    
}
 
// Driven Program
int main()
{
    int arr[] = {1, 3, 4, 10, 9, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    checkReverse(arr, n)? cout << "Yes" : cout << "No";
    return 0;
}