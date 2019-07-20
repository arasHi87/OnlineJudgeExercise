#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=1e4+10;
struct Edge {
    int to, next, id;
} edge[maxN*6];
int n, m, q, a, b, top, scc, idx, cnt;
int dfn[maxN], low[maxN], stk[maxN], blo[maxN], head[maxN], instk[maxN];
inline void addedge(int u, int v, int id) {
    edge[cnt].to=v;
    edge[cnt].id=id;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
inline int min(int a, int b) {
    return a<b?a:b;
}
void tarjan(int u, int id) {
    int v;
    dfn[u]=low[u]=++idx;
    instk[u]=1;
    stk[++top]=u;
    for (int i=head[u];~i;i=edge[i].next) {
        v=edge[i].to;
        if (id==edge[i].id) continue;
        if (!dfn[v]) {
            tarjan(v, edge[i].id);
            low[u]=min(low[u], low[v]);
        } else if (instk[v]) low[u]=min(low[u], dfn[v]);
    }
    if (dfn[u]==low[u]) {
        scc++;
        do {
            v=stk[top--];
            instk[v]=0;
            blo[v]=scc;
        } while (v!=u);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i=0;i<=n;i++)
        head[i]=-1;
    for (int i=1;i<=m;i++) {
        scanf("%d%d", &a, &b);
        addedge(a+1, b+1, i);
        addedge(b+1, a+1, i);
    }
    for (int i=1;i<=n;i++)
        if (!dfn[i])
            tarjan(i, -1);
    while (q--) {
        scanf("%d%d", &a, &b);
        if (blo[a+1]!=blo[b+1]) puts("N");
        else puts("Y");
    }
}