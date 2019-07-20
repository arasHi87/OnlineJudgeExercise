#include <cstdio>
#include <cstring>
#include <algorithm>
#define CLR memset
using namespace std;
const int maxN=1e5+10;
struct Edge {
    int to, next;
} edge[maxN*40];
int n, m, a, b, ans, cnt, idx, top, tmp=0x3f3f3f3f;
int low[maxN], dfn[maxN], val[maxN], num[maxN], stk[maxN], head[maxN], instk[maxN];
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u, int p) {
    dfn[u]=low[u]=++idx;
    stk[++top]=u;
    instk[u]=1;
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (v==p) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u]=min(low[u], low[v]);
            if (dfn[u]<=low[v]) {
                int t;
                do {
                    t=stk[top--];
                    instk[t]=0;
                    num[u]+=val[t];
                } while (t!=u);
            }
        } else if (instk[v]) low[u]=min(low[u], dfn[v]);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    CLR(head, -1, sizeof head);
    ans=cnt=top=idx=0;
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;i++)
        scanf("%d", val+i), num[i]=val[i];
    while (m--) {
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    tarjan(0, -1);
    for (int i=1;i<=n;i++)
        if (num[i] && num[i]-val[i]<tmp)
            tmp=num[i], ans=i;
    for (int i=1;i<=n;i++)
        printf("%d ", num[i]);
    puts("");
    printf("%d\n", ans);
}