#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
using namespace std;
const int maxN=4e4+10;
struct Edge {
    int to, next, val;
} edge[maxN<<1];
char opt[5];
int n, m, q, a, b, c, cnt;
int dis[maxN], dep[maxN], head[maxN], fa[maxN][25];
inline void addedge(int u, int v, int w) {
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u, int p) {
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to, w=edge[i].val;
        if (v==p) continue;
        if (!dis[v]) {
            dis[v]=dis[u]+w;
            dep[v]=dep[u]+1;
            fa[v][0]=u, dfs(v, u);
        }
    }
}
void init() {
    for (int j=1;(1<<j)<=n;j++)
        for (int i=1;i<=n;i++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
}
int lca(int u, int v) {
    if (dep[u]>dep[v]) swap(u, v);
    int d=dep[v]-dep[u];
    for (int i=0;d>>i;i++)
        if ((d>>i)&1) v=fa[v][i];
    if (v==u) return v;
    for (int i=20;i>=0;i--)
        if (fa[u][i]!=fa[v][i])
            u=fa[u][i], v=fa[v][i];
    return fa[v][0];
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m)) {
        mem(head, -1, sizeof head), cnt=0;
        memset(dis, 0, sizeof dis);
        memset(dep, 0, sizeof dep);
        for (int i=1;i<=m;i++) {
            scanf("%d%d%d%s", &a, &b, &c, opt);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        dep[1]=1, dis[1]=0, dfs(1, 0), init();
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", dis[a]+dis[b]-2*dis[lca(a, b)]);
        }
    }
}