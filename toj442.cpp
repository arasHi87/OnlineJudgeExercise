// #include <iostream>
// #include <queue>
// #include <algorithm>
// #include <cmath>
// #define IO ios::sync_with_stdio(false); cin.tie(0);
// using namespace std;
// const int maxN=1e7+10;

// int mp[maxN]={};
// priority_queue<int> q;
// vector<int> v;

// void build(int n) {
//     mp[1]=1;
//     for (int i=2;i<=n;i++) {
//         if (mp[i]==0) {
//             for (int j=i+i;j<=n;j+=i) {
//                 mp[j]=i;
//             }
//         }
//     }
// }

// int main() {
//     IO
//     int T; cin>>T;
//     for (int i=1;i<=T;i++) {
//         int x; cin>>x;
//         q.push(x);
//         v.emplace_back(x);
//     }
//     build(q.top());
//     for (auto it:v) {
//         int f, s;
//         if (mp[it]==0) {
//             cout<<"1 "<<it<<'\n';
//         } else {
//             f=mp[it];
//             while (it%f==0) {
//                 it/=f;
//             }
//             s=mp[it];
//             if (s==0) s=it;
//             cout<<s<<" "<<f<<'\n';
//         }
//     }
// }
#include <bits/stdc++.h>
using namespace std;
const int maxN=1e7+10;
int t, n, mx=-1, mp[maxN];
vector<int> qs;
inline int max(int a, int b) { return a>b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--)
        scanf("%d", &n), mx=max(mx, n), qs.emplace_back(n);
    mp[1]=1;
    for (int i=2;i<=mx;i++) if (!mp[i])
        for (int j=i+i;j<=mx;j++) mp[j]=i;
    for (int i=0, f, s, v;i<(int)qs.size();i++) {
        v=qs[i];
        if (!mp[v]) printf("%d %d\n", 1, v);
        else {
            f=mp[v];
            while (v%f==0) v/=f;
            s=mp[v];
            printf("%d %d\n", (s ? s : v), f);
        }
    }
} 