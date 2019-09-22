#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e5+10;
struct Edge {
    int to, val, next;
} edge[maxN<<1];
int n, m, a, b, c, mx, cnt, root;
int head[maxN];
inline void addedge(int u, int v, int w) {
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u, int p, int w) {
    if (w>mx) mx=w, root=u;
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (v==p) continue;
        dfs(v, u, w+edge[i].val);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    memset(head, -1, sizeof head);
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        addedge(a+1, b+1, c);
        addedge(b+1, a+1, c);
    }
    dfs(1, -1, 0);
    mx=0;
    dfs(root, -1, 0);
    printf("%d\n", mx);
}