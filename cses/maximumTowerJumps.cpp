#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dfs(int n, vector<vector<int>> &towers, vector<vector<int>> &dp, int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    int jumps = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < n && towers[x][y] > towers[i][j])
        {
            jumps = max(jumps, dfs(n, towers, dp, x, y));
        }
    }
    dp[i][j] = jumps + 1;
    return dp[i][j];
}

void printDP(vector<vector<int>>dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

void solve(int n, vector<vector<int>> &towers)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == -1)
            {
                dfs(n, towers, dp, i, j);
            }
            maxi = max(maxi, dp[i][j]);
        }
    }
    printDP(dp);
    cout << maxi << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> towers(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> towers[i][j];
        }
    }
    solve(n, towers);

    return 0;
}