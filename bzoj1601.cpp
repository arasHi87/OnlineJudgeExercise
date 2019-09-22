#include <bits/stdc++.h>
using namespace std;
const int maxN=500+10;
struct Node {
    int u, v, w;
    bool operator < (const Node &rhs) const {
        return w<rhs.w;
    }
} node[maxN];
int n, idx, cnt, ans;
int w[maxN], root[maxN], _rank[maxN];
inline int find(int x) { return root[x]==x ? x : root[x]=find(root[x]); }
inline void unite(int x, int y) {
    if (_rank[x]<_rank[y]) root[x]=y;
    else {
        root[y]=x;
        if (_rank[x]==_rank[y]) _rank[x]++;
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i=0;i<=n;i++)
        root[i]=i, _rank[i]=0;
    for (int i=1;i<=n;i++)
        scanf("%d", w+i);
    for (int i=1;i<=n;i++)
        node[++idx]={0, i, w[i]};
    for (int i=1;i<=n;i++) {
        for (int j=1, k;j<=n;j++) {
            scanf("%d", &k);
            if (j>=i) continue;
            node[++idx]={i, j, k};
        }
    }
    sort(node+1, node+1+idx);
    for (int i=1, x, y;i<=idx;i++) {
        x=find(node[i].u), y=find(node[i].v);
        if (x!=y) unite(x, y), cnt++, ans+=node[i].w;
        if (cnt==n) break;
    }
    printf("%d\n", ans);
}