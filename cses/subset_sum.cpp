#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&a, int n){
    long long total_sum = accumulate(a.begin(), a.end(), 0);
    vector<vector<bool>> dp(n+1, vector<bool>(total_sum+1, false));
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=n;i++){
        for (long long j = 1; j <= total_sum; j++)
        {
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for (long long i = 1; i <= total_sum; i++)
    {
        if(!dp[n][i]){
            cout<<i<<endl;
            return ;
        }
    }
    cout<<total_sum+1<<endl;
    return;
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    solve(a,n);

    return 0;
}