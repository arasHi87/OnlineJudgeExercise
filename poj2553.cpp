#include <cstdio>
#include <cstring>
#define mem(x, y) memset(x, y, sizeof x)
using namespace std;
const int maxN=5e3+10;
struct Edge {
    int to, next;
} edge[maxN*maxN];
int n, m, a, b, cnt, top, idx, scc;
int out[maxN], blo[maxN], dfn[maxN], low[maxN], stk[maxN], head[maxN], instk[maxN];
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
inline void init() {
    cnt=top=idx=scc=0;
    mem(out, 0), mem(blo, 0);
    mem(dfn, 0), mem(low, 0)x;
    mem(stk, 0), mem(head, -1);
    mem(instk, 0);
}
inline int min(int a, int b) { return a<b?a:b; }
void tarjan(int u) {
    int v;
    low[u]=dfn[u]=++idx;
    instk[u]=1, stk[top++]=u;
    for (int i=head[u];~i;i=edge[i].next) {
        v=edge[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u]=min(low[v], low[u]);
        } else if (instk[v]) low[u]=min(low[u], dfn[v]);
    }
    if (dfn[u]==low[u]) {
        scc++;
        do {
            v=stk[--top];
            instk[v]=0;
            blo[v]=scc;
        } while (u!=v);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        scanf("%d", &m), init();
        for (int i=1;i<=m;i++) {
            scanf("%d%d", &a, &b);
            addedge(a, b);
        }
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i);
        for (int i=1;i<=n;i++)
            for (int u=head[i];~u;u=edge[u].next)
                if (blo[i]!=blo[edge[u].to])
                    out[blo[i]]++;
        for (int i=1;i<=n;i++) {
            if (!out[blo[i]]) {
                printf("%d ", i);
            }
        }
        puts("");
    }
}