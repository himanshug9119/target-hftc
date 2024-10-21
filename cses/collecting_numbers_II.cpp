#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1),pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    int ans=1;
    // Counting the number of inversions
    for(int i=1;i<n;i++){
        if(pos[i]>pos[i+1]){
            ans++;
        }
    }
    int l,r;
    set<pair<int,int>> s;
    // Query processing
    while(q--){
        cin>>l>>r;
        int num1 = a[l];
        int num2 = a[r];
        // Insert nums in the set
        if(num1>1){
            s.insert({num1-1, num1});
        }
        if(num1<=n-1){
            s.insert({num1, num1+1});
        }
        if(num2>1){
            s.insert({num2-1, num2});
        }
        if(num2<=n-1){
            s.insert({num2, num2+1});
        }
        for(auto x: s){
            if(pos[x.first]>pos[x.second]){
                ans--;
            }
        }
        swap(a[l],a[r]);
        pos[a[l]]=l;
        pos[a[r]]=r;
        for(auto x: s){
            if(pos[x.first]>pos[x.second]){
                ans++;
            }
        }
        cout<<ans<<endl;
        s.clear();
    }
    return 0;
}