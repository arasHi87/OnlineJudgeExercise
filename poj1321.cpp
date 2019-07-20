// #include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxN=10;
typedef long long LL;
int n, k, vis[maxN], mp[maxN][maxN];
LL ans;
char opt;
void dfs(int cur, int x) {
    if (cur==k) {
        ans++;
        return;
    }
    for (int i=x+1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (!vis[j] && mp[i][j]==1) {
                vis[j]=1;
                dfs(cur+1, i);
                vis[j]=0;
            }
        }
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (cin>>n>>k && n!=-1 && k!=-1) {
        memset(vis, 0, sizeof vis); ans=0;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cin>>opt;
                mp[i][j]=(opt=='#'?1:0);
            }
        }
        dfs(0, 0);
        cout<<ans<<'\n';
    }
}