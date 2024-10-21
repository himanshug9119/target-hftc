#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        sum += x;
    }
    cout << 1ll*n * (n + 1) / 2 - sum << endl;

    return 0;
}