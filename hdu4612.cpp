#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define CLR memset
using namespace std;
const int maxN=2e5+10;
struct Edge {
    int to, next, id;
} edge[maxN*20];
int n, m, x, y, scc, top, idx, cnt;
int dfn[maxN], dis[maxN], low[maxN], stk[maxN], blo[maxN], vis[maxN], head[maxN], instk[maxN];
vector<int> G[maxN];
inline void init() {
    scc=top=idx=cnt=0;
    CLR(dfn, 0, sizeof dfn);
    CLR(dis, 0, sizeof dis);
    CLR(low, 0, sizeof low);
    CLR(stk, 0, sizeof stk);
    CLR(blo, 0, sizeof blo);
    CLR(vis, 0, sizeof vis);
    CLR(head, -1, sizeof head);
    CLR(instk, 0, sizeof instk);
    for (int i=1;i<=n;i++)
        G[i].clear();
}
inline void addedge(int u, int v, int d) {
    edge[cnt].to=v;
    edge[cnt].id=d;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u, int id) {
    int v;
    dfn[u]=low[u]=++idx;
    stk[++top]=u;
    instk[u]=1;
    for (int i=head[u];~i;i=edge[i].next) {
        if (edge[i].id==id) continue;
        v=edge[i].to;
        if (!dfn[v]) {
            tarjan(v, edge[i].id);
            low[u]=min(low[u], low[v]);
        } else if (instk[v] && low[u]>dfn[v]) low[u]=dfn[v];
    }
    if (dfn[u]==low[u]) {
        scc++;
        do {
            v=stk[top--];
            instk[v]=0;
            blo[v]=scc;
        } while(u!=v);
    }
}
int bfs(int u) {
    queue<int> q;
    CLR(vis, 0, sizeof vis);
    q.push(u), vis[u]=1, dis[u]=0;
    int v;
    while (!q.empty()) {
        v=q.front(); q.pop();
        vis[v]=1;
        for (int i=0;i<(int)G[v].size();i++) {
            int k=G[v][i];
            if (!vis[k]) {
                vis[k]=1, dis[k]=dis[v]+1;
                q.push(k);
            }
        }
    }
    return v;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && n && m) {
        init();
        for (int i=1;i<=m;i++) {
            scanf("%d%d", &x, &y);
            addedge(x, y, i);
            addedge(y, x, i);
        }
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i, -1);
        for (int i=1;i<=n;i++) {
            for (int j=head[i];~j;j=edge[j].next) {
                int v=edge[j].to;
                if (blo[i]!=blo[v]) {
                    G[blo[i]].push_back(blo[v]);
                }
            }
        }
        printf("%d\n", scc-dis[bfs(bfs(1))]-1);
    }
}