#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=1000+10;
struct Edge {
    int to, next;
} edge[maxN*maxN];
int n, m, k, t, cnt, idx;
int head[maxN], dfn[maxN], low[maxN];
vector<pair<int, int>> bcc;
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u, int p) {
    dfn[u]=low[u]=++idx;
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u]=min(low[u], low[v]);
            if (low[v]>dfn[u])
                bcc.push_back(make_pair(min(u, v), max(u, v)));
        } else if (v!=p) low[u]=min(low[u], dfn[v]);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(head, -1, sizeof head);
        idx=cnt=0, bcc.clear();
        for (int i=1;i<=n;i++) {
            scanf("%d", &k), k++;
            scanf(" (%d) ", &m);
            while (m--) {
                scanf("%d", &t), t++;
                addedge(k, t);
                addedge(t, k);
            }
        }
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i, -1);
        sort(bcc.begin(), bcc.end());
        printf("%d critical links\n", (int)bcc.size());
        for (int i=0;i<(int)bcc.size();i++)
            printf("%d - %d\n", bcc[i].first-1, bcc[i].second-1);
        puts("");
    }
}