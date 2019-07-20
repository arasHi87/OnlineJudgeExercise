#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxN=50+10;
const int INF=0x3f3f3f3f;
struct Edge {
    int to, val;
    Edge(int a, int b): to(a), val(b) {};
    bool operator < (const Edge &rhs) const {
        return val>rhs.val;
    }
};
int p, r, x, y, z, ans;
int G[maxN][maxN], vis[maxN];
priority_queue<Edge> pq;
int prim(int st) {
    for (int i=0;i<=p;i++) vis[i]=0;
    while (!pq.empty()) pq.pop();
    ans=0, vis[st]=1;
    for (int i=0;i<p-1;i++) {
        for (int j=1;j<=p;j++)
            if (!vis[j])
                pq.push(Edge(j, G[st][j]));
        while (!pq.empty() && vis[pq.top().to]) pq.pop();
        if (pq.empty()) break;
        vis[pq.top().to]=1, ans+=pq.top().val, st=pq.top().to, pq.pop();
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &p) && p) {
        scanf("%d", &r);
        for (int i=0;i<=p;i++)
            for (int j=0;j<=p;j++)
                G[i][j]=INF;
        while (r--) {
            scanf("%d%d%d", &x, &y, &z);
            if (G[x][y]>z || G[y][x]>z)
                G[x][y]=G[y][x]=z;
        }
        printf("%d\n", prim(1));
    }
}