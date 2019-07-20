#include <cstdio>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int maxN=3e5+10;
const int INF=0x3f3f3f3f;
struct Edge {
    int to, val;
    Edge(int a, int b): to(a), val(b) {};
    bool operator < (const Edge &rhs) const {
        return val>rhs.val;
    }
};
int t, n, m, c, x, y, z;
int vis[maxN], dis[maxN], lay[maxN], has[maxN];
vector<Edge> G[maxN];
// priority_queue<Edge> pq;
// int dijks(int st, int ed) {
//     for (int i=0;i<=2*n+1;i++)
//         vis[i]=0, dis[i]=INF;
//     dis[st]=0, pq.push(Edge(st, 0));
//     while (!pq.empty()) {
//         int u=pq.top().to; pq.pop();
//         vis[u]=1;
//         for (int i=0;i<(int)G[u].size();i++) {
//             Edge *tmp=&G[u][i];
//             int v=(*tmp).to, w=(*tmp).val;
//             if (!vis[v] && dis[v]>dis[u]+w) {
//                 dis[v]=dis[u]+w;
//                 pq.push(Edge(v, dis[v]));
//             }
//         }
//     }
//     return (dis[ed]==INF?-1:dis[ed]);
// }
queue<int> q;
int spfa(int st, int ed) {
    for(int i=0;i<=2*n+1;i++)
        vis[i]=0, dis[i]=INF;
    dis[st]=0, q.push(st);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        vis[u]=0;
        for (int i=0;i<(int)G[u].size();i++) {
            Edge *tmp=&G[u][i];
            int v=(*tmp).to, w=(*tmp).val;
            if (dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                if (!vis[v])
                    vis[v]=1, q.push(v);
            }
        }
    }
    // for (int i=1;i<=2*n;i++)
    //     printf("%d ", dis[i]);
    // puts("");
    return (dis[ed]==INF?-1:dis[ed]);
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    for (int kase=1;kase<=t;kase++) {
        printf("Case #%d: ", kase);
        scanf("%d%d%d", &n, &m, &c);
        for (int i=0;i<=2*n+1;i++)
            G[i].clear(), lay[i]=0, has[i]=0;
        for (int i=1;i<=n;i++) {
            scanf("%d", &x);
            lay[i]=x, has[x]=1;
        }
        for (int i=1;i<=n;i++) {
            // printf("%d %d %d\n", lay[i]+n, i, 0);
            // if (lay[i]>1) printf("%d %d %d\n", i, lay[i]+n-1, 0);
            // if (lay[i]<n) printf("%d %d %d\n", i, lay[i]+n+1, 0);
            G[lay[i]+n].push_back(Edge(i, 0));
            if (lay[i]>1) G[i].push_back(Edge(lay[i]+n-1, c));
            if (lay[i]<n) G[i].push_back(Edge(lay[i]+n+1, c));
        }
        for (int i=1;i<=n;i++) {
            if (has[i] && has[i-1]) {
                // printf("%d %d %d\n", i+n, i+n-1, c);
                // printf("%d %d %d\n", i+n-1, i+n, c);
                G[i+n].push_back(Edge(i+n-1, c));
                G[i+n-1].push_back(Edge(i+n, c));
            }
        }
        while (m--) {
            scanf("%d%d%d", &x, &y, &z);
            // printf("%d %d %d\n", x, y, z);
            // printf("%d %d %d\n", y, x, z);
            G[x].push_back(Edge(y, z));
            G[y].push_back(Edge(x, z));
        }
        printf("%d\n", spfa(1, n));
    }
}