#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN=5e4+10;
struct segment {
	int val, tag;
	segment(): val(-1), tag(-1) {};
} seg[maxN<<2];
int t, n, m, x, y, a, b, idx=0;
int pre[maxN], in[maxN], out[maxN];
char opt[1];
vector<int> G[maxN];
void init() {
	idx=0;
	memset(pre, 0, sizeof pre);	
	memset(out, 0, sizeof out);
	memset(in, 0, sizeof in);
	for (int i=1;i<=maxN;i++)
		G[i].clear();
}
void dfs(int root) {
	in[root]=++idx;
	for (auto it:G[root])
		dfs(it);
	out[root]=idx;
}
inline void push(int root) {
	if (seg[root].tag!=-1) {
		seg[root<<1].val=seg[root<<1|1].val=seg[root].tag;
		seg[root<<1].tag=seg[root<<1|1].tag=seg[root].tag;
		seg[root].tag=-1;
	}
}
void build(int root, int L, int R) {
	seg[root].val=seg[root].tag=-1;
	if (L==R) return;
	int mid=(L+R)>>1;
	build(root<<1, L, mid);
	build(root<<1|1, mid+1, R);
}
void update(int root, int L, int R, int ql, int qr, int d) {
	if (ql>R || qr<L) return;
	if (ql<=L && qr>=R) {
		seg[root].val=d;
		seg[root].tag=d;
		return;
	}
	int mid=(L+R)>>1;
	push(root);
	update(root<<1, L, mid, ql, qr, d);
	update(root<<1|1, mid+1, R, ql, qr, d);
}
int query(int root, int L, int R, int pos) {
	if (L==R) return seg[root].val;
	int mid=(L+R)>>1;
	push(root);
	if (pos<=mid) return query(root<<1, L, mid, pos);
	else return query(root<<1|1, mid+1, R, pos);
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d", &t);
	for (int kase=1;kase<=t;kase++) {
		init();
		scanf("%d", &n);
		for (int i=1;i<n;i++) {
			scanf("%d%d", &x, &y);
			G[y].emplace_back(x);
			pre[x]++; 
		}
		for (int i=1;i<=n;i++) {
			if (!pre[i]) {
				dfs(i);
				break;
			}
		}
		scanf("%d", &m);
		printf("Case #%d:\n", kase);
		build(1, 1, idx);
		while (m--) {
			scanf("%s%d", opt, &a);
			if (opt[0]=='C') printf("%d\n", query(1, 1, idx, in[a]));
			else {
				scanf("%d", &b);
				update(1, 1, idx, in[a], out[a], b);
			}
		}
	}
}