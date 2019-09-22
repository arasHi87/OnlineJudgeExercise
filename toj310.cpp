#include <bits/stdc++.h>
using namespace std;
const int maxN=1e4+10;
struct Edge {
    int to, next;
} edge[maxN<<1];
int n, q, cnt;
int dep[maxN], fa[maxN][25], head[maxN];
inline int max(int a, int b) { return a>b?a:b; }
inline int min(int a, int b) { return a<b?a:b; }
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u, int p, int d) {
    dep[u]=d;
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (v==p) continue;
        fa[v][0]=u;
        dfs(v, u, d+1);
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
    memset(head, -1, sizeof head);
    scanf("%d%d", &n, &q);
    for (int i=1, u, v;i<n;i++) {
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    dfs(0, -1, 0);
    for (int j=1;(1<<j)<n;j++)
        for (int i=0;i<n;i++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
            // fa[i][j]=(fa[i][j-1]==-1 ? -1 : fa[fa[i][j-1]][j-1]);
    for (int k=1, u, v;k<=q;k++) {
        scanf("%d%d", &u, &v);
        if (u==v) printf("%d\n", u);
        else {
            if (dep[u]>dep[v]) swap(u, v); // v deeper
            int dis=(dep[u]+dep[v]-(dep[lca(u, v)]<<1)), d=dis>>1;
            for (int i=20;i>=0;i--)
                if ((d>>i)&1) v=fa[v][i];
            if (dis%2) printf("%d %d\n", min(v, fa[v][0]), max(v, fa[v][0]));
            else printf("%d\n", v);
        }
    }
}