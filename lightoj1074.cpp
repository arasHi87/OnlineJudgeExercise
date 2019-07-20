#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxN=200+10;
const int INF=0x3f3f3f3f;
struct Edge {
    int to, val;
    Edge(int a, int b): to(a), val(b) {};
};
int t, n, k, m, x, y, Q;
int vis[maxN], dis[maxN], cur[maxN], num[maxN], val[maxN];
vector<Edge> G[maxN];
queue<int> q;
void dfs(int u) {
    cur[u]=1;
    for (int i=0;i<(int)G[u].size();i++)
        if (!cur[G[u][i].to])
            dfs(G[u][i].to);
}
void spfa(int st) {
    for (int i=0;i<=n;i++)
        vis[i]=0, dis[i]=INF, num[i]=0;
    dis[st]=0, q.push(st);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        vis[u]=0;
        for (int i=0;i<(int)G[u].size();i++) {
            Edge *tmp=&G[u][i];
            int v=(*tmp).to, w=(*tmp).val;
            if (cur[v]) continue;
            if (dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                if (!vis[v]) {
                    vis[v]=1;
                    q.push(v);
                    if (++num[v]>n) dfs(v);
                }
            }
        }
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    for (int kase=1;kase<=t;kase++) {
        printf("Case %d:\n", kase);
        scanf("%d", &n);
        for (int i=0;i<=n;i++)
            G[i].clear(), cur[i]=0, val[i]=0;
        for (int i=1;i<=n;i++)
            scanf("%d", val+i);
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d", &x, &y);
            // G[x].push_back(Edge(y, pow(val[x]-val[y], 3)));
            G[x].push_back(Edge(y, pow(val[y]-val[x], 3)));
        }
        spfa(1);
        scanf("%d", &Q);
        while (Q--) {
            scanf("%d", &x);
            if (dis[x]<3 || dis[x]==INF || cur[x])  printf("?\n");
            else printf("%d\n", dis[x]);
        }
    }
}