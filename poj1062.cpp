#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxN=100+10;
const int INF=0x3f3f3f3f;
struct Edge {
    int to, val;
    Edge(int a, int b): to(a), val(b) {};
    bool operator < (const Edge &rhs) const {
        return val>rhs.val;
    }
};
int m, n, p, l, x, t, e, ans=INF;
int vis[maxN], dis[maxN], pre[maxN];
vector<Edge> G[maxN];
priority_queue<Edge> pq;
int dijks(int st, int ed, int lv) {
    for (int i=0;i<=n;i++)
        dis[i]=INF, vis[i]=0;
    dis[st]=0, pq.push(Edge(st, 0));
    while (!pq.empty()) {
        int u=pq.top().to; pq.pop();
        vis[u]=1;
        for (int i=0;i<(int)G[u].size();i++) {
            Edge *tmp=&G[u][i];
            int v=(*tmp).to, w=(*tmp).val;
            if (m && (pre[v]<lv || pre[v]-lv>m)) vis[v]=1;
            if (!vis[v] && dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                pq.push(Edge(v, dis[v]));
            }
        }
    }
    return dis[ed];
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &m, &n)) {
        ans=INF;
        for (int i=0;i<maxN;i++)
            G[i].clear(), pre[i]=0;
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d", &p, &l, &x);
            G[0].push_back(Edge(i, p));
            pre[i]=l;
            while (x--) {
                scanf("%d%d", &t, &e);
                G[t].push_back(Edge(i, e));
            }
        }
        for (int i=1;i<=n;i++) 
            if (pre[i]<=pre[1])
            // printf("de: %d\n", dijks(0, 1, pre[i])),
                ans=min(ans, dijks(0, 1, pre[i]));
        printf("%d\n", ans);
    }
}