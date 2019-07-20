#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=1e5+10;
const long long INF=1e18+10;
typedef long long LL;
struct segment {
	LL mx, tag;
	segment(): mx(0), tag(0) {};
} seg[maxN<<2];
int n, m, a, b, c, x, y, t, idx=0;
int vis[maxN], in[maxN], out[maxN];
LL val[maxN], qs[maxN];
vector<int> G[maxN];
void init() {
	idx=0;
	for (int i=1;i<=maxN;i++) {
		in[i]=out[i]=vis[i]=0;
		val[i]=qs[i]=0;
		seg[i].mx=seg[i].tag=0;
		G[i].clear();
	}
	for (int i=maxN+1;i<=maxN<<2;i++) {
		seg[i].mx=seg[i].tag=0;
	}
}
void dfs(int root, LL d) {
	in[root]=++idx, val[idx]=d, vis[root]=1;
	for (auto it:G[root]) {
		if (!vis[it]) {
			dfs(it, d+qs[it]);
		}
	}
	out[root]=idx;
}
inline void pull(int root) {
	seg[root].mx=max(seg[root<<1].mx, seg[root<<1|1].mx);
}
inline void push(int root) {
	if (seg[root].tag) {
		seg[root<<1].mx+=seg[root].tag;
		seg[root<<1|1].mx+=seg[root].tag;
		seg[root<<1].tag+=seg[root].tag;
		seg[root<<1|1].tag+=seg[root].tag;
		seg[root].tag=0;
	}
}
void build(int root, int L, int R) {
	if (L==R) {
		seg[root].mx=val[L];
		return;
	}
	int mid=(L+R)>>1;
	build(root<<1, L, mid);
	build(root<<1|1, mid+1, R);
	pull(root);
}
void update(int root, int L, int R, int ql, int qr, LL d) {
	if (ql>R || qr<L) return;
	if (ql<=L && qr>=R) {
		seg[root].mx+=d;
		seg[root].tag+=d;
		return;
	}
	int mid=(L+R)>>1;
	push(root);
	update(root<<1, L, mid, ql, qr, d);
	update(root<<1|1, mid+1, R, ql ,qr, d);
	pull(root);
}
LL query(int root, int L, int R, int ql, int qr) {
	if (ql>R || qr<L) return -INF;
	if (ql<=L && qr>=R) return seg[root].mx;
	int mid=(L+R)>>1;
	push(root);
	return max(query(root<<1, L, mid, ql, qr), query(root<<1|1, mid+1, R, ql, qr));
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d", &t);
	for (int kase=1;kase<=t;kase++) {
		init();
		scanf("%d%d", &n, &m);
		for (int i=1;i<n;i++) {
			scanf("%d%d", &x, &y);
			G[x+1].emplace_back(y+1);
			G[y+1].emplace_back(x+1);
		}
		for (int i=1;i<=n;i++)
			scanf("%lld", qs+i);
		dfs(1, qs[1]);
		build(1, 1, idx);
		printf("Case #%d:\n", kase);
		while (m--) {
			scanf("%d%d", &a, &b);
			if (a) printf("%lld\n", query(1, 1, idx, in[b+1], out[b+1]));
			else {
				scanf("%d", &c);
				update(1, 1, idx, in[b+1], out[b+1], c-qs[b+1]);
				qs[b+1]=c;
			}
		}
	}
}