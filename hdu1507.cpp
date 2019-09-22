#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=110;
int n, m, k, idx, ans;
int vis[maxN*maxN], mth[maxN*maxN], mp[maxN][maxN], G[maxN][maxN];
int d[4][2]={1, 0, 0, 1, -1, 0, 0, -1};
inline int xy2d(int x, int y) { return (x-1)*m+y-1; }
int dfs(int x, int y) {
    int u=xy2d(x, y);
    for (int i=0;i<4;i++) {
        int nx=x+d[i][0], ny=y+d[i][1], v=xy2d(nx, ny);
        if (!mp[nx][ny] || vis[v]==idx || nx<1 || nx>n || ny<1 || ny>m) continue;
        vis[v]=idx;
        if (mth[v]==-1 || dfs(mth[v]/m+1, mth[v]%m+1))
            { mth[v]=u; return 1; }
    }
    return 0;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && n+m) {
        memset(mp, 1, sizeof mp), ans=0;
        memset(mth, -1, sizeof mth);
        scanf("%d", &k);
        for (int i=1, x, y;i<=k;i++)
            scanf("%d%d", &x, &y), mp[x][y]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (mp[i][j] && (i+j)%2)
                    idx++, ans+=dfs(i, j);
        printf("%d\n", ans);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (~mth[xy2d(i, j)])
                    printf("(%d,%d)--(%d,%d)\n", i, j, mth[xy2d(i, j)]/m+1, mth[xy2d(i, j)]%m+1);
    }
}