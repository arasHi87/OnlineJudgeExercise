#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=100+10;
const int INF=0x3f3f3f3f;
int t, n, m, a, b, c, mst, smst;
int dis[maxN], vis[maxN], pre[maxN], G[maxN][maxN], mx[maxN][maxN], used[maxN][maxN];
void prim(int st) {
    for (int i=1;i<=n;i++)
        vis[i]=0, dis[i]=G[st][i], pre[i]=st;
    vis[st]=1, mst=0;
    for (int k=1;k<=n-1;k++) {
        int x, mn=INF;
        for (int i=1;i<=n;i++)
            if (!vis[i] && dis[i]<mn)
                mn=dis[x=i];
        vis[x]=1, mst+=dis[x], used[pre[x]][x]=used[x][pre[x]]=1;
        for (int i=1;i<=n;i++) {
            if (vis[i] && i!=x)
                mx[i][x]=mx[x][i]=max(mx[pre[x]][i], mn);
            if (!vis[i] && dis[i]>G[x][i])
                dis[i]=G[x][i], pre[i]=x;
        }
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                used[i][j]=mx[i][j]=0, G[i][j]=INF;
        while (m--) {
            scanf("%d%d%d", &a, &b, &c);
            G[a][b]=G[b][a]=c;
        }
        prim(1), smst=INF;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (!used[i][j] && i!=j)
                    smst=min(smst, mst-mx[i][j]+G[i][j]);
            }
        }
        printf("%d %d\n", mst, smst);
    }
}