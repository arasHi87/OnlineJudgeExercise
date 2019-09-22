#include <set>
#include <cstdio>
#include <cstring>
using namespace std;
typedef set<int>::iterator it;
const int maxN=110;
int n, k, tmp, idx, res;
int vis[maxN], mth[maxN], G[maxN][maxN], mp[maxN][maxN];
int dfs(int u) {
    for (int i=1;i<=n;i++) {
        if (G[u][i] && vis[i]!=idx) {
            vis[i]=idx;
            if (mth[i]==-1 || dfs(mth[i]))
                { mth[i]=u; return 1; }
        }
    }
    return 0;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &k) && (n+k)) {
        set<int> cr;
        int flag=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d", &mp[i][j]), cr.insert(mp[i][j]);
        for (it tmp=cr.begin();tmp!=cr.end();tmp++) {
            memset(mth, -1, sizeof mth);
            memset(G, 0, sizeof G), res=0;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    if (mp[i][j]==*tmp) G[i][j]=1;
            for (int i=1;i<=n;i++)
                idx++, res+=dfs(i);
            if (res>k)
                !flag ? printf("%d", *tmp), flag=1 : printf(" %d", *tmp);
        }
        flag ? puts("") : puts("-1");
    }
}