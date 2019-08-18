#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
using namespace std;
const int maxN=1e4+10;
struct Edge {
    int to, next, val;
} edge[maxN<<1];
int n, m, q, a, b, c, cnt;
int dep[maxN], dis[maxN], root[maxN], _rank[maxN], head[maxN], fa[maxN][25];
inline void addedge(int u, int v, int w) {
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
inline void init() {
    cnt=0;
    mem(fa, 0, sizeof fa);
    mem(dep, 0, sizeof dep);
    mem(dis, 0, sizeof dis);
    mem(head, -1, sizeof head);
    mem(_rank, 0, sizeof _rank);
    for (int i=0;i<=n;i++) root[i]=i;
}
int find(int x) { return root[x]==x?x:root[x]=find(root[x]); }
inline void unite(int x, int y) {
    x=find(x), y=find(y);
    if (x==y) return;
    if (_rank[x]<_rank[y]) root[x]=y;
    else {
        root[y]=x;
        if (_rank[x]==_rank[y]) _rank[x]++;
    }
}
// inline void unite(int x, int y) {
//     x=find(x), y=find(y);
//     if (x==y) return;
//     x<y?root[y]=x:root[x]=y;
// }
void dfs(int u, int p) {
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to, w=edge[i].val;
        if (v==p) continue;
        dis[v]=dis[u]+w;
        dep[v]=dep[u]+1;
        fa[v][0]=u, dfs(v, u);
    }
}
inline int lca(int u, int v) {
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
    while(~scanf("%d%d%d", &n, &m, &q)) {
        init();
        while (m--) {
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c);
            addedge(b, a, c);
            unite(a, b);
        }
        for (int i=1;i<=n;i++) {
            if (root[i]==i) {
                addedge(i, 0, 0);
                addedge(0, i, 0);
            }
        }
        dep[0]=1, dis[0]=0, dfs(0, -1);
        for (int j=1;(1<<j)<=n;j++)
            for (int i=0;i<=n;i++)
                fa[i][j]=fa[fa[i][j-1]][j-1];
        // for (int i=1;i<=n;i++)
        //     printf("DE: %d %d\n", i, root[i]);
        while (q--) {
            scanf("%d%d", &a, &b);
            if (find(a)!=find(b)) printf("Not connected\n");
            else printf("%d\n", dis[a]+dis[b]-2*dis[lca(a, b)]);
        }
    }
}