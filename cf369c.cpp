#include <bits/stdc++.h>
using namespace std;
const int maxN=1e5+10;
struct Edge {
    int to, next, val;
} edge[maxN<<1];
int n, cnt, head[maxN];
vector<int> ans;
inline void addedge(int u, int v, int w) {
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
bool dfs(int u, int p) {
    int res=0;
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to, w=edge[i].val;
        if (v==p) continue;
        int tmp=dfs(v, u);
        if (!tmp && w==1)
            res++, ans.emplace_back(v);
        res+=tmp;
    }
    return res;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    memset(head, -1, sizeof head);
    for (int i=1, u, v, w;i<n;i++) {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w-1);
        addedge(v, u, w-1);
    }
    dfs(1, 0);
    printf("%d\n", (int)ans.size());
    for (auto i:ans)
        printf("%d ", i); puts("");
}