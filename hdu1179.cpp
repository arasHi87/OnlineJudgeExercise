#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=110;
struct {
    int to, next;
} edge[maxN*maxN];
int n, m, ans, cnt, idx;
int vis[maxN], mth[maxN], head[maxN];
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int dfs(int u) {
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (vis[v]!=idx) {
            vis[v]=idx;
            if (mth[v]==-1 || dfs(mth[v]))
                { mth[v]=u; return 1; }
        }
    }
    return 0;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m)) {
        memset(mth, -1, sizeof mth), ans=cnt=0;
        memset(head, -1, sizeof head);
        for (int i=1, k, v;i<=m;i++) {
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &v);
                addedge(i, v);
            }
        }
        for (int i=1;i<=m;i++)
            idx++, ans+=dfs(i);
        printf("%d\n", ans);
    }
}