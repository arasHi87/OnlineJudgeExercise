#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef double db;
const int maxN=1e3+10;
const int INF=0x3f3f3f3f;
struct Node {
    db x, y, w;
    Node(): x(0), y(0), w(0) {};
    Node(db _x, db _y, db _w): x(_x), y(_y), w(_w) {};
} node[maxN];
int t, n, vis[maxN], pre[maxN], used[maxN][maxN];
db a, b, c, mst, ans, dis[maxN], mx[maxN][maxN], G[maxN][maxN];
void prim(int st) {
    for (int i=1;i<=n;i++)
        vis[i]=0, dis[i]=G[st][i], pre[i]=st;
    vis[st]=1, dis[st]=0, mst=0;
    for (int k=1;k<=n-1;k++) {
        int x; db mn=INF;
        for (int i=1;i<=n;i++)
            if (!vis[i] && dis[i]<mn)
                mn=dis[x=i];
        vis[x]=1, mst+=dis[x], used[x][pre[x]]=used[pre[x]][x]=1;
        for (int i=1;i<=n;i++) {
            if (vis[i] && i!=x)
                mx[x][i]=mx[i][x]=max(mx[i][pre[x]], mn);
            if (!vis[i] && dis[i]>G[x][i])
                dis[i]=G[i][x], pre[i]=x;
        }
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        memset(used, 0, sizeof used);
        memset(mx, 0, sizeof mx);
        scanf("%d", &n);
        for (int i=1;i<=n;i++) {
            scanf("%lf%lf%lf", &a, &b, &c);
            node[i]=Node(a, b, c);
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (i!=j)
                    G[i][j]=sqrt(pow(node[i].x-node[j].x, 2)+pow(node[i].y-node[j].y, 2));
        prim(1), ans=-1;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (i==j) continue;
                if (used[i][j]) ans=max(ans, (node[i].w+node[j].w)/(mst-G[i][j]));
                else ans=max(ans, (node[i].w+node[j].w)/(mst-mx[i][j]));
            }
        }
        printf("%0.2lf\n", ans);
    }
}