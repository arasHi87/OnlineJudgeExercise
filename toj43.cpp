// #include <cstdio>
// #include <queue>
// using namespace std;
// const int maxN=1e4+10;
// const int INF=0x3f3f3f3f;
// struct Edge {
//     int to, next, w;
// } edge[maxN*2];
// int n, m, a, b, c, cnt=0;
// int head[maxN], dis[maxN], vis[maxN];
// queue<int> q;
// inline void addedge(int u, int v, int w) {
//     edge[cnt].to=v;
//     edge[cnt].w=w;
//     edge[cnt].next=head[u];
//     head[u]=cnt++;
// }
// int spfa(int st, int ed) {
//     for (int i=1;i<=n;i++)
//         dis[i]=INF, vis[i]=0;
//     dis[st]=0, q.push(st);
//     while (!q.empty()) {
//         int u=q.front(); q.pop();
//         vis[u]=0;
//         for (int i=head[u];~i;i=edge[i].next) {
//             int v=edge[i].to, w=edge[i].w;
//             if (dis[v]>dis[u]+w) {
//                 dis[v]=dis[u]+w;
//                 if (!vis[v]) {
//                     vis[v]=1, q.push(v);
//                 }
//             }
//         }
//     }
//     return dis[ed];
// }
// int main() {
//     #ifdef local
//         freopen("in", "r", stdin);
//     #endif
//     scanf("%d%d", &n, &m);
//     for(int i=1;i<=n;i++)
//         head[i]=-1;
//     while (m--) {
//         scanf("%d%d%d", &a, &b, &c);
//         addedge(a+1, b+1, c);
//         addedge(b+1, a+1, c);
//     }
//     scanf("%d%d", &a, &b);
//     printf("%d\n", spfa(a+1, b+1));
// }
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=1e4+10;
const int INF=0x3f3f3f3f;
struct Edge {
    int to, val;
    Edge(int _to, int _val): to(_to), val(_val) {};
    bool operator < (const Edge &rhs) const {
        return val>rhs.val;
    }
};
int n, m, a, b, c;
int dis[maxN], vis[maxN];
vector<Edge> G[maxN];
priority_queue<Edge> pq;
int dijks(int st, int ed) {
    for (int i=1;i<=n;i++)
        dis[i]=INF, vis[i]=0;
    dis[st]=0;
    pq.push(Edge(st, 0));
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
    return dis[ed];
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        G[a+1].push_back(Edge(b+1, c));
        G[b+1].push_back(Edge(a+1, c));
    }
    scanf("%d%d", &a, &b);
    printf("%d\n", dijks(a+1, b+1));
}