#include <bits/stdc++.h>
using namespace std;
int getMax(int arr[],int n){
    int ans=INT_MIN;

    for(int i=0;i<n;i++) ans=max(ans,arr[i]);

    return ans;
}
void solve(int arr[],int n,int e){
    int count[10];
    int output[n];
    memset(count,0,sizeof(count));
    
    for(int i=0;i<n;i++){
        count[(arr[i]/e)%10]++;
    }

    for(int i=1;i<=9;i++) count[i]+=count[i-1];
    
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/e)%10]-1]=arr[i];
        count[(arr[i]/e)%10]--;
    }

    for(int i=0;i<n;i++)
        arr[i]=output[i];
}
void radixsort(int arr[],int n){
    int mx=getMax(arr,n);
    int e=1;
    while(mx){
        mx=mx/e;
        solve(arr,n,e);
        e=e*10;
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
   
    radixsort(arr, n);
    print(arr, n);
    return 0;
}