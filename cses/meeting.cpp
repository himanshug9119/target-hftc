#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

void solve(vector<pii>&first, int n, vector<pii>&second, int m, int duration){
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    int i=0, j=0;
    while(i<n && j<m){
        int startFirst = first[i].first;
        int endFirst = first[i].second;
        int startSecond = second[j].first;
        int endSecond = second[j].second;
        if(endFirst < startSecond){
            i++;
        }else if(endSecond < startFirst){
            j++;
        }else{
            int start = max(startFirst, startSecond);
            int end = min(endFirst, endSecond);
            if(end-start>=duration){
                cout<<start<<" "<<start+duration<<endl;
                return;
            }
            if(endFirst < endSecond){
                i++;
            }else{
                j++;
            }
        }
    }
    cout<<"No solution"<<endl;
    return;
}


int main(){
    int n,m, duration;
    cin>>n>>m>>duration;
    vector<pii>first, second;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        first.push_back({x,y});
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        second.push_back({x,y});
    }

    solve(first, n, second , m, duration);

    return 0;
}