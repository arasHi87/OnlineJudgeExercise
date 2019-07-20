#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
using namespace std;
const int maxN=1e4+10;
const int maxM=5e4+10;
struct Edge {
    int to, next;
} edge[maxM<<2];
int n, m, x, y, ans, top, scc, idx, cnt;
int dfn[maxN], low[maxN], stk[maxN], blo[maxN], out[maxN], head[maxN], instk[maxN];
inline void init() {
    ans=top=scc=idx=cnt=0;
    mem(dfn, 0, sizeof dfn);
    mem(low, 0, sizeof low);
    mem(stk, 0, sizeof stk);
    mem(blo, 0, sizeof blo);
    mem(out, 0, sizeof out);
    mem(head, -1, sizeof head);
    mem(instk, 0, sizeof instk);
}
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
inline void tarjan(int u) {
    int v;
    dfn[u]=low[u]=++idx;
    instk[u]=1;
    stk[++top]=u;
    for (int i=head[u];~i;i=edge[i].next) {
        v=edge[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u], low[v]);
        } else if (instk[v]) low[u]=min(low[u], dfn[v]); 
    }
    if (dfn[u]==low[u]) {
        scc++;
        do {
            v=stk[top--];
            instk[v]=0;
            blo[v]=scc;
        } while (u!=v);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m)) {
        init();
        while (m--) {
            scanf("%d%d", &x, &y);
            addedge(x, y);
        }
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i);
        for (int i=1;i<=n;i++)
            for (int j=head[i];~j;j=edge[j].next)
                if (blo[i]!=blo[edge[j].to])
                    out[blo[i]]++;
        for (int i=1;i<=scc;i++)
            if (!out[i])
                ans++, x=i;
        if (ans==1) {
            ans=0;
            for (int i=1;i<=n;i++)
                if(blo[i]==x)
                    ans++;
        } else ans=0;
        printf("%d\n", ans);
    }
}