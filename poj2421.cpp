#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=1e2+10;
const int INF=0x3f3f3f3f;
struct Edge {
    int u, v, w;
    Edge(int a, int b, int c): u(a), v(b), w(c) {};
    bool operator < (const Edge &rhs) const {
        return w<rhs.w;
    }
};
int n, k, q, a, b, ans, cnt;
int root[maxN], _rank[maxN];
vector<Edge> v;
inline void init() {
    for (int i=0;i<=n;i++)
        root[i]=i, _rank[i]=0;
    ans=0, cnt=0;
}
int find(int x) {
    return (root[x]==x?x:root[x]=find(root[x]));
}
void unite(int x, int y) {
    if (_rank[x]<_rank[y]) {
        root[x]=y;
    } else {
        root[y]=x;
        if (_rank[x]==_rank[y]) _rank[x]++;
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        init();
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                scanf("%d", &k);
                v.push_back(Edge(i, j, k));
            }
        }
        sort(v.begin(), v.end());
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &a, &b);
            a=find(a), b=find(b);
            if (a!=b) cnt++, unite(a, b);
        }
        for (int i=0;i<(int)v.size() && cnt<n-1;i++) {
            a=find(v[i].u), b=find(v[i].v);
            if (a!=b) {
                unite(a, b);
                cnt++, ans+=v[i].w;
            }
        }
        printf("%d\n", ans);
    }
}