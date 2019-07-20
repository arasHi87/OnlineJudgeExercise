#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxN=1e3+10;
const int INF=0x3f3f3f3f;
struct Edge {
    int to, val;
    Edge(int a, int b): to(a), val(b) {};
    bool operator < (const Edge &rhs) const {
        return val>rhs.val;
    }
};
int t, n, k, ans;
int G[maxN][maxN], val[maxN], vis[maxN];
priority_queue<Edge> pq;
int prim(int st) {
    for (int i=0;i<=n;i++) vis[i]=0;
    while (!pq.empty()) pq.pop();
    ans=0, vis[st]=1;
    for (int i=1;i<=n-1;i++) {
        for (int j=1;j<=n;j++)
            if (!vis[j])
                pq.push(Edge(j, G[st][j]));
        while (!pq.empty() && vis[pq.top().to]) pq.pop();
        if (pq.empty()) break;
        st=pq.top().to, ans+=pq.top().val, vis[pq.top().to]=1, pq.pop();
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0;i<=n;i++) {
            val[i]=0;
            for (int j=0;j<=n;j++)
                G[i][j]=INF;
        }
        for (int i=1;i<=n;i++)
            scanf("%d", val+i);
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                scanf("%d", &k);
                G[i][j]=G[j][i]=k+val[i]+val[j];
            }
        }
        printf("%d\n", prim(1));
    }
}