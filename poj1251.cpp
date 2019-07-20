#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=50;
struct Edge {
    int w, u, v;
    Edge(int a, int b, int c): w(a), u(b), v(c) {};
    bool  operator < (const Edge &rhs) const {
        return w<rhs.w;
    }
};
int n, m, a, b, c, ans, cnt;
int root[maxN], _rank[maxN];
char opt[5];
vector<Edge> G;
inline void init() {
    ans=0, cnt=0;
    for (int i=0;i<=n;i++)
        root[i]=i, _rank[i]=0;
    G.clear();
}
int find(int x) {
    return (root[x]==x?x:root[x]=find(root[x]));
}
bool same(int x, int y) {
    return find(x)==find(y);
}
inline void unite(int x, int y) {
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
        for (int i=1;i<n;i++) {
            scanf("%s%d", opt, &m);
            a=opt[0]-'A'+1;
            while (m--) {
                scanf("%s%d", opt, &c);
                b=opt[0]-'A'+1;
                G.push_back(Edge(c, a, b));
            }
        }
        sort(G.begin(), G.end());
        for (int i=0;i<(int)G.size() && cnt<n-1;i++) {
            a=find(G[i].u), b=find(G[i].v);
            if (a!=b) {
                unite(a, b);
                ans+=G[i].w;
                cnt++;
            }
        }
        printf("%d\n", ans);
    }
}