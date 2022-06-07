#include <bits/stdc++.h>
using namespace std;
int find(vector<int> v,int m){
    int diff=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>m) diff+=(v[i]-m);
    }
    return diff;
}
int main(){
    int n,c;
    cin>>n>>c;

    vector<int> v;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        maxi=max(maxi,x);
        v.push_back(x);
    }

    int l=0,h=maxi;
    int ans=0;

    while(l<=h){
        int m=(l+h)/2;
        int height=find(v,m);

        if(height<c){
            h=m-1;
        }
        else{
            ans=m;
            l=m+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}