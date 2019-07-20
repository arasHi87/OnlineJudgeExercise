#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
const int maxN=5e3+5;

int p=0;

struct disjoinset {
	int root[maxN];
	int _rank[maxN];
	inline void init(int n) {
		for (int i=1;i<=n;i++) root[i]=i, _rank[i]=0;
	}
	int find(int x) {
		if (root[x]==x) return x;
		else return root[x]=find(root[x]);
	}
	inline bool same(int x, int y) {
		return find(x)==find(y);
	}
	inline void unite(int x, int y) {
		x=find(x), y=find(y);
		// if (x==y) return ;
		if (_rank[x]<_rank[y]) {
			root[x]=y;
		} else {
			root[y]=x;
			if (_rank[x]==_rank[y]) _rank[x]++;
		}
	}
};

struct Edge {
    int u, v, w;
}; vector<Edge> mp;

bool operator < (Edge &a, Edge &b) {
        return a.w<b.w;
}

inline void kruskal(int n, int m, int k) {
    if (k==-1) {cout<<p<<endl; return;}
    disjoinset ds; ds.init(n);
    sort(mp.begin(), mp.end());
    long long ans=0, cnt=0;
    bool ok=false;
    for (int i=0;i<m;i++) {
        int a=mp[i].u;
        int b=mp[i].v;
        int cst=mp[i].w;
        if (n-cnt<=k) {
            ok=true;
            break;
        }
        if (ds.same(a, b)) continue;
        ds.unite(a, b);
        if (cst>=0) ans+=cst;
        cnt++;
    } 
    int root=ds.find(1);
    for (int i=1;i<=n && !ok;i++) {
        if (ds.find(i)!=root) {
            cout<<"-1"<<endl;
            return;
        }
    }
    cout<<ans+p<<endl;
}

int main() {
    int n, m, k; cin>>n>>m>>k;
    for (int o=1;o<=m;o++) {
        int i, j, w;
        cin>>i>>j>>w;
        mp.push_back(Edge{i, j, w});
        if (w<0) p+=w;
    }
    kruskal(n, m, k);
}