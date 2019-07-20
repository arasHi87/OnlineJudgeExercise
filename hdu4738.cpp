#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define CLR memset
using namespace std;
const int maxN=1e3+10;
struct Edge {
    int to, next, w;
} edge[maxN*maxN<<2];
int n, m, a, b, c, j, top, idx, cnt, scc, mn;
int dfn[maxN], low[maxN], val[maxN], head[maxN];
inline void init() {
    j=top=idx=cnt=scc=0, mn=0x3f3f3f3f;
    CLR(dfn, 0, sizeof dfn);
    CLR(low, 0, sizeof low);
    CLR(val, 0, sizeof val);
    CLR(head, -1, sizeof head);
}
inline void addedge(int u, int v, int w) {
    edge[cnt].w=w;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u, int p) {
    int v, flag=0;
    dfn[u]=low[u]=++idx;
    for (int i=head[u];~i;i=edge[i].next) {
        v=edge[i].to;
        if (v==p && !flag)  {
            flag++;
            continue;
        }
        if (!dfn[v]) {
            tarjan(v, u);
            low[u]=min(low[u], low[v]);
            if (dfn[u]<low[v]) {
                mn=min(mn, edge[i].w);
            }
        } else low[u]=min(low[u], dfn[v]);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && n && m) {
        init();
        while (m--) {
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i, -1), j++;
        if (j>1) printf("0\n");
        else if (mn==0) printf("1\n");
        else if (mn==0x3f3f3f3f) printf("-1\n");
        else printf("%d\n", mn);
    }
}