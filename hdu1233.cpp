#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN=100+10;
const int INF=0x3f3f3f3f;
int n, m, x, y, z, ans;
int vis[maxN], dis[maxN], G[maxN][maxN];
int prim(int st) {
    for (int i=0;i<=n;i++)
        vis[i]=0, dis[i]=G[st][i];
    dis[st]=0, vis[st]=1, ans=0;
    for (int i=1;i<=n-1;i++) {
        int a, mn=INF;
        for (int j=1;j<=n;j++)
            if (!vis[j] && dis[j]<mn)
                mn=dis[a=j];
        vis[a]=1, ans+=dis[a];
        for (int j=1;j<=n;j++)
            if (!vis[j] && dis[j]>G[a][j])
                dis[j]=G[a][j];
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                G[i][j]=INF;
        m=n*(n-1)/2;
        while (m--) {
            scanf("%d%d%d", &x, &y, &z);
            G[x][y]=G[y][x]=z;
        }
        printf("%d\n", prim(1));
    }
}