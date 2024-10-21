#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int n){
    sort(a.begin(), a.end());
    // this sum is the smallest non-constructible sum from the subset of numbers
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > sum + 1)
        {
            cout << sum + 1 << endl;
            return;
        }
        sum += a[i];
    }
    cout << sum + 1 << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(a, n);

    return 0;
}