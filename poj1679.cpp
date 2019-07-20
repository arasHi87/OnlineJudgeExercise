#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=100+10;
const int INF=0x3f3f3f3f;
int t, n, m, x, y, w, ans, cnt;
int vis[maxN], use[maxN][maxN], pre[maxN], 
    dis[maxN], G[maxN][maxN], mx[maxN][maxN];
int prim(int st) {
    for (int i=0;i<=n;i++)
        dis[i]=G[st][i], vis[i]=0, pre[i]=st;
    vis[st]=1, dis[st]=0, ans=0;
    for (int k=1;k<=n-1;k++) {
        int a=-1, mn=INF;
        for (int i=1;i<=n;i++)
            if(!vis[i] && dis[i]<mn)
                mn=dis[a=i];
        if (a==-1) return ans;
        vis[a]=1, ans+=dis[a];
        use[pre[a]][a]=use[a][pre[a]]=1;
        for (int i=1;i<=n;i++) {
            if (vis[i])
                mx[i][a]=max(mx[i][pre[a]], mn);
            if (!vis[i] && dis[i]>G[a][i])
                dis[i]=G[a][i], pre[i]=a;
        }
    }
    return ans;
}
int smst() {
    int mn=INF;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (!use[i][j])
                mn=min(mn, ans+G[i][j]-mx[i][j]);
    return mn;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                G[i][j]=INF, use[i][j]=0;
        while (m--) {
            scanf("%d%d%d", &x, &y, &w);
            G[x][y]=G[y][x]=w;
        }
        // printf("%d %d\n", smst(), prim(1));
        if (prim(1)==smst()) printf("Not Unique!\n");
        else printf("%d\n", ans);
    }
}