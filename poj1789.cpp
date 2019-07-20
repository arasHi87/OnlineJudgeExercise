#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxN=2e3+10;
const int INF=0x3f3f3f3f;
// struct Edge {
//     int to, val;
//     Edge(int a, int b): to(a), val(b) {};
//     bool operator < (const Edge &rhs) const {
//         return val>rhs.val;
//     }
// };
int n, k, ans, res;
int vis[maxN], dis[maxN], G[maxN][maxN];
char opt[maxN][10];
// priority_queue<Edge> pq;
// int prim(int st) {
//     for (int i=1;i<=n;i++) vis[i]=0;
//     while (!pq.empty()) pq.pop();
//     ans=0, vis[st]=1;
//     for (int i=1;i<=n-1;i++) {
//         for (int j=1;j<=n;j++)
//             if (!vis[j])
//                 pq.push(Edge(j, G[st][j]));
//         while (!pq.empty() && vis[pq.top().to]) pq.pop();
//         if (pq.empty()) break;
//         ans+=pq.top().val, st=pq.top().to, vis[pq.top().to]=1, pq.pop();
//     }
//     return ans;
// }
int prim(int st) {
    for (int i=1;i<=n;i++)
        dis[i]=INF, vis[i]=0;
    dis[st]=0, ans=0;
    for (int i=1;i<=n;i++) {
        int x, mn=INF;
        for (int j=1;j<=n;j++) 
            if(!vis[j] && dis[j]<=mn)
                mn=dis[x=j];
        vis[x]=1, ans+=dis[x];
        for (int j=1;j<=n;j++)
            dis[j]=min(dis[j], G[x][j]);
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                G[i][j]=0;
        for (int i=1;i<=n;i++) scanf("%s", opt[i]);
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (i>j) continue;
                for (int k=0;k<7;k++) {
                    if (opt[i][k]!=opt[j][k]) G[i][j]++, G[j][i]++;
                }
            }
        }
        printf("The highest possible quality is 1/%d.\n", prim(1));
    }
}