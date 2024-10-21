#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a, int n){
    vector<vector<int>>a_with_index;
    for(int i=0;i<n;i++){
        a_with_index.push_back({a[i],i});
    }
    sort(a_with_index.begin(), a_with_index.end());
    int count=1;
    for(int i=1;i<n;i++){
        if(a_with_index[i-1][1]>a_with_index[i][1]){
            count++;
        }
    }
    return count;
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(a,n)<<endl;

    return 0;
}