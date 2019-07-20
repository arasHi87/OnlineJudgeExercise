#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
using namespace std;
const int maxN=100+10;
const int maxM=1e3+10;
int n, m, k, t, a, b, ans;
int vis[maxN], mth[maxN];
vector<int> G[maxN];
int find(int x) {
    for (int i=0;i<(int)G[x].size();i++) {
        if (!vis[G[x][i]]) {
            vis[G[x][i]] = 1;
            if (mth[G[x][i]]==-1 || find(mth[G[x][i]])) {
                mth[G[x][i]] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        scanf("%d%d", &m, &k);
        ans=0;
        for (int i=0;i<=n;i++) G[i].clear();
        mem(vis, 0, sizeof vis);
        mem(mth, -1, sizeof mth);
        while (k--) {
            scanf("%d%d%d", &t, &a, &b);
            G[a].push_back(b);
        }
        for (int i=0;i<n;i++) {
            mem(vis, 0, sizeof vis);
            if (mth[i]==-1)
                ans+=find(i);
        }
        printf("%d\n", ans);
    }
}