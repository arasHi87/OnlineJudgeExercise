#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1010;
struct Edge {
    int to, next;
} edge[maxN];
int n, m, k, idx, cnt, ans;
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
    while (~scanf("%d", &n) && n) {
        scanf("%d%d", &m, &k);
        memset(mth, -1, sizeof mth), cnt=ans=0;
        memset(head, -1, sizeof head);
        for (int i=0, t, u, v;i<k;i++) {
            scanf("%d%d%d", &t, &u, &v);
            if (u && v) addedge(u, v);
        }
        for (int i=0;i<n;i++)
            idx++, ans+=dfs(i);
        printf("%d\n", ans);
    }
}