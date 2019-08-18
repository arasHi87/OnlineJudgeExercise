#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e2+10;
int n, m, dp[maxN][maxN], mp[maxN][maxN];
int d[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int max(int a, int b) { return a>b?a:b; }
int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    int ans=0, dx, dy;
    for (int i=1;i<=m;i++) {
        for (int j=0;j<4;j++) {
            dx=x+i*d[j][0], dy=y+i*d[j][1];
            if (dx>=1 && dx<=n && dy>=1 && dy<=n && mp[dx][dy]>mp[x][y])
                ans=max(ans, dfs(dx, dy));
        }
    }
    return dp[x][y]=mp[x][y]+ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && n!=-1 && m!=-1) {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d", &mp[i][j]);
        memset(dp, 0, sizeof dp);
        printf("%d\n", dfs(1, 1));
    }
}