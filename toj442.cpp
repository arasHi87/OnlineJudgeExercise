#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#define IO ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int maxN=1e7+10;

int mp[maxN]={};
priority_queue<int> q;
vector<int> v;

void build(int n) {
    mp[1]=1;
    for (int i=2;i<=n;i++) {
        if (mp[i]==0) {
            for (int j=i+i;j<=n;j+=i) {
                mp[j]=i;
            }
        }
    }
}

int main() {
    IO
    int T; cin>>T;
    for (int i=1;i<=T;i++) {
        int x; cin>>x;
        q.push(x);
        v.emplace_back(x);
    }
    build(q.top());
    for (auto it:v) {
        int f, s;
        if (mp[it]==0) {
            cout<<"1 "<<it<<'\n';
        } else {
            f=mp[it];
            while (it%f==0) {
                it/=f;
            }
            s=mp[it];
            if (s==0) s=it;
            cout<<s<<" "<<f<<'\n';
        }
    }
}