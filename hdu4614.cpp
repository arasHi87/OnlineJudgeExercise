#include <cstdio>
using namespace std;
const int maxN=5e4+10;
struct segment {
	int sum, tag;
	segment(): sum(0), tag(-1) {};
} seg[maxN<<2];
int n, m, x, y, k, t, st, ed, ls, rs;
inline void pull(int root) {
	seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
} 
inline void push(int root, int L, int R) {
	if (seg[root].tag!=-1) {
		int mid=(L+R)>>1;
		seg[root<<1].sum=seg[root].tag*(mid-L+1);
		seg[root<<1|1].sum=seg[root].tag*(R-mid);
		seg[root<<1].tag=seg[root<<1|1].tag=seg[root].tag;
		seg[root].tag=-1;
	}
}
void build(int root, int L, int R) {
	seg[root].tag=-1;
	if (L==R) {
		seg[root].sum=1;
		return;
	}
	int mid=(L+R)>>1;
	build(root<<1, L, mid);
	build(root<<1|1, mid+1, R);
	pull(root);
}
void update(int root, int L, int R, int ql, int qr, int d) {
	if (ql>R || qr<L) return;
	if (ql<=L && qr>=R) {
		seg[root].sum=d*(R-L+1);
		seg[root].tag=d;
		return;
	}
	int mid=(L+R)>>1;
	push(root, L, R);
	update(root<<1, L, mid, ql, qr, d);
	update(root<<1|1, mid+1, R, ql, qr, d);
	pull(root);
}
int query(int root, int L, int R, int ql, int qr) {
	if (ql>R || qr<L) return 0;
	if (ql<=L && qr>=R) return seg[root].sum;
	int mid=(L+R)>>1;
	push(root, L, R);
	return query(root<<1, L, mid, ql, qr)+query(root<<1|1, mid+1, R, ql, qr);
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		build(1, 1, n);
		while (m--) {
			scanf("%d%d%d", &k, &x, &y);
			if (k==1) {
				x+=1, st=-1, ls=x, rs=n, ed=0;
				while (ls<=rs) {
					int mid=(ls+rs)>>1;
					if (query(1, 1, n, x, mid)>=1) st=mid, rs=mid-1;
					else ls=mid+1;
				}
				if (st==-1) {
					printf("Can not put any one.\n");
					continue;
				}
				if (query(1, 1, n, st, n)<y) {
					ls=st, rs=n;
					while (ls<=rs) {
						int mid=(ls+rs)>>1;
						if (query(1, 1, n, mid, n)>=1) ed=mid, ls=mid+1;
						else rs=mid-1;
					}
				} else {
					ls=st, rs=n;
					while (ls<=rs) {
						int mid=(ls+rs)>>1;
						if (query(1, 1, n, st, mid)>=y) ed=mid, rs=mid-1;
						else ls=mid+1; 
					}
				}
				printf("%d %d\n", st-1, ed-1);
				update(1, 1, n, st, ed, 0);
			} else {
				x+=1, y+=1;
				printf("%d\n", y-x+1-query(1, 1, n, x, y));
				update(1, 1, n, x, y, 1);
			}
		}
		puts("");
	}
}