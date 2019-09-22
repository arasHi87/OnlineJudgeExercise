#include <cstdio>
#include <cstring>
#define mem memset
using namespace std;
const int maxN=1e5+10;
struct Edge {
    int to, next;
} edge[maxN<<1];
int n, m, a, b, cnt, rt, mx;
int vis[maxN], head[maxN];
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u, int d) {
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (vis[v]) continue;
        if (d+1>mx) rt=v, mx=d+1;
        vis[v]=1, dfs(v, d+1);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    mem(head, -1, sizeof head);
    scanf("%d%d", &n, &m);
    for (int i=1;i<=m;i++) {
        scanf("%d%d", &a, &b);
        addedge(a+1, b+1);
        addedge(b+1, a+1);
    }
    dfs(1, 0);
    mem(vis, 0, sizeof vis), mx=0;
    dfs(rt, 0);
    printf("%d\n", mx);
}