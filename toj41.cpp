#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
const int maxN=1e3+10;

struct disjoinset{
    int root[maxN];
    int _rank[maxN];
    int find(int x) {
        return (root[x]==x?x:root[x]=find(root[x]));
    }
    inline void init(int n) {
        for (int i=0;i<n;i++) {
            root[i]=i, _rank[i]=0;
        }
    }
    inline bool same(int x, int y) {
        return find(x)==find(y);
    }
    inline void unite(int x, int y) {
        x=find(x), y=find(y);
        if (_rank[x]<_rank[y]) {
            root[x]=y;
        } else {
            root[y]=x;
            if (_rank[x]==_rank[y]) _rank[x]++;
        }
    }
    inline bool chk(int n) {
        int rt=find(1);
        for (int i=0;i<n;i++) {
            if (find(i)!=rt) return false;
        }
        return true;
    }
};

struct Edge {
    int u, v, w;
};

bool cmp (Edge a, Edge b) {
    return a.w<b.w;
}

vector<Edge> mp;

int main() {
    int k, r, a, b ,c;
    cin>>k>>r;
    for (int i=1;i<=r;i++) {
        cin>>a>>b>>c;
        mp.emplace_back(Edge{a, b, c});
    }
    sort(mp.begin(), mp.end(), cmp);
    disjoinset ds; ds.init(k);
    int  ans=0;
    for (auto it:mp) {
        // cout<<it.u<<" "<<it.v<<endl;
        if (!ds.same(it.u, it.v)) {
            ds.unite(it.u, it.v);
            ans+=it.w;
        }
    }
    if (!ds.chk(k)) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}