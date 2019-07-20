#include <cstdio>
#include <cstring>
#include <algorithm>
#define CLR memset
using namespace std;
const int maxN=1e5+10;
struct Edge {
    int to, next;
} edge[maxN<<2];
int n, m, a, b, q, t=1, ans, idx, cnt;
int dfn[maxN], low[maxN], pre[maxN], head[maxN], bridge[maxN];
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u, int f) {
    low[u]=dfn[u]=++idx;
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (v==f) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            pre[v]=u;
            low[u]=min(low[u], low[v]);
            if (dfn[u]<low[v]) {
                ans++;
                bridge[v]=1;
            }
        } else low[u]=min(low[u], dfn[v]);
    }
}
int lca(int u, int v) {
    if (dfn[u]>dfn[v]) swap(u, v);
    while (dfn[u]<dfn[v]) {
        if (bridge[v]) {
            ans--;
            bridge[v]=0;
        }
        v=pre[v];
    }
    while (u!=v) {
        if (bridge[u]) ans--, bridge[u]=0;
        if (bridge[v]) ans--, bridge[v]=0;
        u=pre[u], v=pre[v];
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && n && m) {
        CLR(dfn, 0, sizeof dfn);
        CLR(low, 0, sizeof low);
        CLR(pre, 0, sizeof pre);
        CLR(head, -1, sizeof head);
        CLR(bridge, 0, sizeof bridge);
        ans=idx=cnt=0;
        while (m--) {
            scanf("%d%d", &a, &b);
            addedge(a, b);
            addedge(b, a);
        }
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i, -1);
        printf("Case %d:\n", t++);
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", lca(a, b));
        }
    }
}