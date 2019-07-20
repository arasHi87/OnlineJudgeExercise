#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define CLR memset
using namespace std;
const int maxN=2e4+10;
const int maxM=1e5+3e4+10;
const int INF=0x7fffffff;
struct Vertex {
    int u, v, w, vis;
    bool operator < (const Vertex &rhs) const {
        return w<rhs.w;
    }
} edge[maxM<<2];
struct Edge {
    int to, val;
    Edge(int _to, int _val): to(_to), val(_val) {};
};
int t, n, m, a, b, c, idx, cnt, mst, smst;
int dis[maxN], root[maxN], _rank[maxN], fa[maxN][20], mx[maxN][20];
vector<Edge> G[maxM];
inline void init() {
    idx=cnt=mst=0, smst=INF;
    for (int i=1;i<=m;i++) G[i].clear();
    for (int i=0;i<=n;i++) {
        dis[i]=_rank[i]=0, root[i]=i;
        for (int j=0;j<35;j++)
            fa[i][j]=mx[i][j]=-1;
    }
}
int find(int x) {
    return (root[x]==x?x:root[x]=find(root[x]));
}
inline void unite(int x, int y) {
    if (_rank[x]<_rank[y]) root[x]=y;
    else {
        root[y]=x;
        if (_rank[x]==_rank[y]) _rank[x]++; 
    }
}
inline void kruskal() {
    sort(edge+1, edge+1+m);
    for (int i=1;i<=m && cnt<=n-1; i++) {
        int x=find(edge[i].u), y=find(edge[i].v);
        if (x!=y) {
            cnt++, unite(x, y),
            mst+=edge[i].w, edge[i].vis=1;
            G[edge[i].u].push_back(Edge(edge[i].v, edge[i].w));
            G[edge[i].v].push_back(Edge(edge[i].u, edge[i].w));
        }
    }
}
void dfs(int u, int p) {
    dis[u]=dis[p]+1, fa[u][0]=p;
    for (auto it:G[u]) {
        int v=it.to, w=it.val;
        if (v!=p) {
            mx[v][0]=w;
            dfs(v, u);
        }
    }
}
inline int lca(int u, int v) {
    if (dis[u]<dis[v]) swap(u, v);
    int tmp=0, d=dis[u]-dis[v];
    if (d)
        for (int i=19;i>=0;i--)
            if ((d>>i)&1)
                tmp=max(tmp, mx[u][i]), u=fa[u][i];
    if (u==v) return tmp;
    for (int i=19;i>=0;i--)
        if (fa[u][i]!=fa[v][i])
            tmp=max({tmp, mx[u][i], mx[v][i]}),
            u=fa[u][i], v=fa[v][i];
    return max({tmp, mx[u][0], mx[v][0]});
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m), init();
        for (int i=1;i<=m;i++) {
            scanf("%d%d%d", &a, &b, &c);
            edge[i].u=a+1, edge[i].v=b+1, edge[i].w=c, edge[i].vis=0;
        }
        kruskal(), dfs(1, 1);
        for (int i=1;i<20;i++)
            for (int j=1;j<=n;j++)
                if (fa[j][i])
                    fa[j][i]=fa[fa[j][i-1]][i-1],
                    mx[j][i]=max(mx[j][i-1], mx[fa[j][i-1]][i-1]);
        for (int i=1;i<=m;i++)
            if (!edge[i].vis)
                smst=min(smst, mst+edge[i].w-lca(edge[i].u, edge[i].v));
        printf("%d\n", smst-mst);
    }
}