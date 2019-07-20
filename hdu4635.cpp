#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define CLR memset
using namespace std;
typedef long long LL;
const int maxN=1e5+10;
struct Edge {
    int next, to;
} edge[maxN<<2];
int n, m, a, b, t, mn, cnt, idx, top, scc;
int in[maxN], out[maxN], dfn[maxN], low[maxN], stk[maxN], blo[maxN], num[maxN], head[maxN], instk[maxN];
inline void init () {
    cnt=idx=top=scc=0, mn=n;
    CLR(in, 0, sizeof in);
    CLR(out, 0, sizeof out);
    CLR(dfn, 0, sizeof dfn);
    CLR(low, 0, sizeof low);
    CLR(stk, 0, sizeof stk);
    CLR(blo, 0, sizeof blo);
    CLR(num, 0, sizeof num);
    CLR(head, -1, sizeof head);
    CLR(instk, 0, sizeof instk);
}
inline void addedge (int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u) {
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
            num[scc]++;
        } while (u!=v);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    for (int kase=1;kase<=t;kase++) {
        scanf("%d%d", &n, &m);
        init();
        for (int i=1;i<=m;i++) {
            scanf("%d%d", &a, &b);
            addedge(a, b);
        }
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i);
        if (scc==1) {
            printf("Case %d: -1\n", kase);
            continue;
        }
        for (int i=1;i<=n;i++) {
            for (int j=head[i];~j;j=edge[j].next) {
                int v=edge[j].to;
                if (blo[i]!=blo[v]) {
                    out[blo[i]]++;
                    in[blo[v]]++;
                }
            }
        }
        for (int i=1;i<=scc;i++)
            if (!in[i] || !out[i])
                mn=min(mn, num[i]);
        LL np=(LL)n, mnp=(LL)mn, mp=(LL)m;
        printf("Case %d: %lld\n", kase, np*np-np-mnp*(np-mnp)-mp);
    }
}