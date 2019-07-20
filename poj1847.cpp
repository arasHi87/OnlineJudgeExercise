#include <cstdio>
#include <vector>
#include <queue>
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
int n, a, b, x, k;
int vis[maxN], dis[maxN];
vector<Edge> G[maxN];
priority_queue<Edge> pq;
int dijks(int st, int ed) {
    for (int i=0;i<=n;i++)
        vis[i]=0, dis[i]=INF;
    dis[st]=0, pq.push(Edge(st, 0));
    while (!pq.empty()) {
        int u=pq.top().to; pq.pop();
        vis[u]=1;
        for (int i=0;i<(int)G[u].size();i++) {
            Edge *tmp=&G[u][i];
            int v=(*tmp).to, w=(*tmp).val;
            if (!vis[v] && dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                pq.push(Edge(v, dis[v]));
            }
        }
    }
    if (dis[ed]==INF) return -1;
    else return dis[ed];
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d%d", &n, &a, &b)) {
        for (int i=0;i<=n;i++) G[i].clear();
        for (int i=1;i<=n;i++) {
            scanf("%d", &x);
            for (int j=1;j<=x;j++) {
                scanf("%d", &k);
                if (j==1) G[i].push_back(Edge(k, 0));
                else G[i].push_back(Edge(k, 1));
            }
        }
        printf("%d\n", dijks(a, b));
    }
}