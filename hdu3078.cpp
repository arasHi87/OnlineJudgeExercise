#include <cstdio>
#include <cstring>
#include <algorithm>
#define DE(x) printf("DE: %d\n", x)
#define mem memset
using namespace std;
const int maxN=8e4+5;
struct Edge {
    int to, next;
} edge[maxN<<1];
int n, q, a, b, k, cnt;
int dep[maxN], val[maxN], pre[maxN], tmp[maxN], head[maxN], fa[maxN][21];
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u, int p) {
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (v==p) continue;
        dep[v]=dep[u]+1, pre[v]=u;
        fa[v][0]=u, dfs(v, u);
    }
}
inline void init() {
    for (int j=1;(1<<j)<=n;j++)
        for (int i=1;i<=n;i++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
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
    for (int i=1;i<=n;i++)
        scanf("%d", val+i);
    for (int i=1;i<n;i++) {
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    dep[1]=1, pre[1]=0, dfs(1, 0), init();
    // for (int i=1;i<=n;i++)
    //     printf("%d %d\n", i, pre[i]);
    // puts("");
    while (q--) {
        scanf("%d%d%d", &k, &a, &b);
        if (k) {
            int p=lca(a, b), idx=1;
            // printf("DE: %d\n", p);
            while (a!=p) tmp[idx++]=val[a], a=pre[a];
            while (b!=p) tmp[idx++]=val[b], b=pre[b];
            tmp[idx++]=val[p];
            sort(tmp+1, tmp+idx, [](int x, int y){
                return x>y;
            });
            // for (int i=1;i<idx;i++)
            //     printf("%d ", tmp[i]);
            // puts("");
            if (k>=idx) puts("invalid request!");
            else printf("%d\n", tmp[k]);
        } else val[a]=b;
    }
}