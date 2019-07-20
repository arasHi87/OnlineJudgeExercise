#include <cstdio>
#include <cstring>
#include <algorithm>
#define CLR memset
using namespace std;
const int maxN=1e4+10;
struct Edge {
    int to, next;
} edge[maxN<<2];
int n, m, a, b, ans, cnt, top, idx, scc;
int dfn[maxN], low[maxN], stk[maxN], dth[maxN], blo[maxN], head[maxN];
inline void init() {
    ans=cnt=top=idx=scc=0;
    CLR(dfn, 0, sizeof dfn);
    CLR(low, 0, sizeof low);
    CLR(stk, 0, sizeof stk);
    CLR(dth, 0, sizeof dth);
    CLR(blo, 0, sizeof blo);
    CLR(head, -1, sizeof head);
}
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u, int p) {
    int v;
    low[u]=dfn[u]=idx++;
    stk[++top]=u;
    for (int i=head[u];~i;i=edge[i].next) {
        v=edge[i].to;
        if (i==(p^1)) continue;
        if (!dfn[v]) {
            tarjan(v, i);
            low[u]=min(low[u], low[v]);
        } else if (v!=p) low[u]=min(low[u], dfn[v]);
    }
    if (dfn[u]==low[u]) {
        scc++;
        do {
            v=stk[top--];
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
            scanf("%d%d", &a, &b);
            addedge(a, b);
            addedge(b, a);
        }
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i, -1);
        for (int i=1;i<=n;i++)
            for (int j=head[i];~j;j=edge[j].next)
                if (blo[i]!=blo[edge[j].to])
                    dth[blo[i]]++;
        for(int i=1;i<=scc;i++)
            if (dth[i]==1)
                ans++;
        printf("%d\n", (ans+1)/2);
    }
}