#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN=1e6+5;

struct dis {
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

struct Node {
	int st, ed, cst;
};

bool operator < (Node &a, Node &b) {
		return a.cst<b.cst;
}

vector<Node> mp;

inline void kruskal(int n, int m) {
	sort(mp.begin(), mp.end());
	dis dj; dj.init(n);
	int cnt=0;
	for (int i=0;i<m;i++) {
		int a=mp[i].st, b=mp[i].ed, cur=mp[i].cst;
		if (!dj.same(a, b)||cur<0) {
			cnt+=cur;
			dj.unite(a, b);
		}
	}
	cout<<cnt<<'\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while (t--) {
		mp.clear();
		int n, m;
		cin>>n>>m;
		for (int i=1;i<=m;i++) {
			int a, b, c, d;
			cin>>a>>b>>c>>d;
			mp.push_back(Node{a, b, c-d});
		}
		kruskal(n, m);
	}
}
