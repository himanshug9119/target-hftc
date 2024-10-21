#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    unordered_map<char, int> m;
    int i=0;
    int j=0;
    int n = s.size();
    while(i<n){
        m[s[i]]++;
        if(m.size()>4){
            m[s[j]]--;
            if(m[s[j]]==0){
                m.erase(s[j]);
            }
            j++;
        }
        i++;
    }

}


int main(){
    solve();

    return 0;
}