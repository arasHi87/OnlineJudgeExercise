#include <cstdio>
#include <cstring>
#define mem memset
using namespace std;
const int maxN=1e5+10;
struct Edge {
    int to, next;
} edge[maxN*10];
int n, m, a, b, cnt;
int val[maxN], head[maxN];
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
bool dfs(int u) {
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (val[u]==val[v]) return false;
        if (val[v]) continue;
        val[v]=3-val[u];
        if (!dfs(v)) return false;
    }
    return true;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m)) {
        mem(val, 0, sizeof val), cnt=0;
        mem(head, -1, sizeof head);
        for (int i=1;i<=m;i++) {
            scanf("%d%d", &a, &b);
            addedge(a+1 ,b+1);
            addedge(b+1, a+1);
        }
        val[1]=1;
        if (dfs(1)) puts("YES");
        else puts("NO");
    }
}