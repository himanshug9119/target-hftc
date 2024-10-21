#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void getAns(int nn, string s){
    int c = (int)sqrt(nn);
    for(int i=0; i<nn; i+=c){
        if(i==0 || i==nn-c){
            for(int j=0; j<c; j++){
                if(s[i+j] != '1'){
                    cout<<"NO\n";
                    return;
                }
            }
        }else{
            if(s[i] != '1' || s[i+c-1] != '1'){
                cout<<"NO\n";
                return;
            }
            for(int j=1; j<c-1; j++){
                if(s[i+j] != '0'){
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";
    return;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1){
        cout<<"Yes"<<endl;
        return;
    }else if(n==2){
        cout<<"No"<<endl;
        return;
    }
    int sq = (int)sqrt(n);
    if(sq*sq!=n){
        cout<<"NO\n";
        return;
    }else{
        getAns(n, s);
    }
    return ;
}


int main(){
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}