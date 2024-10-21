#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin>>a>>b;
    if(a%2==0 && b%2==0){
        cout<<"YES\n";
        return;
    }else if(a%2!=0 && b%2!=0){
        cout<<"No\n";
        return;
    }else if(a != 0 && a%2==0 && b%2==1){
        cout<<"YES\n";
        return;
    }else{
        cout<<"NO\n";
        return;
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}