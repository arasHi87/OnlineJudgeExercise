#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
const int maxN=1e5+10;
const int maxM=1e6+10;
typedef tuple<int, int, int> tp;
typedef pair <int, int> pii;

struct Node {
    int w, id;
    vector<pii> to;
};

int root[maxN];
int _rank[maxN];
vector<tp> Edge;
Node tree[maxN];

bool find(int x) {
    return (root[x]==x ? x : root[x]=find(root[x]));
}

inline void init(int n) {
    for (int i=0;i<=n;i++) {
        root[i]=i;
        _rank[i]=0;
    }
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
    int n, m; cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int a, b, p;
        cin>>a>>b>>p;
        Edge.emplace_back(make_tuple(a, b, -p));
    }
    sort(Edge.begin(), Edge.end());
    init(n);
    for (int i=0;i<m;i++) {
        int a=find(get<0>(Edge[i]));
        int b=find(get<1>(Edge[i]));
        int w=find(get<2>(Edge[i]));
        if (a==b) continue;
        unite(a, b);
    }
}