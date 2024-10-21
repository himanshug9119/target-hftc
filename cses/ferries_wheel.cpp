#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&a, int n, int x){
    int ans=0;
    sort(a.begin(),a.end());
    int i=0,j=n-1;
    while(i<=j){
        if(a[i]+a[j]<=x){
            i++;
            j--;
        }
        else{
            j--;
        }
        ans++;
    }
    cout<<ans<<endl;
    return;
}


int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    solve(a,n,x);

    return 0;
}