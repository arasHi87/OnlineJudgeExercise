#include <cstdio>
#include <cmath>
using namespace std;
const int maxN=1e5+10;
const long long mod=1e4+7;
typedef long long LL;
struct segment {
	LL val; bool dif;
	segment(): val(0), dif(true) {};
} seg[maxN<<2];
int n, m, k, x, y, z;
LL ans=0;
inline void  push(int root, int L, int R) {
	if (L==R || !seg[root].dif) return;
	seg[root].dif=false;
	seg[root<<1].val=seg[root<<1|1].val=seg[root].val;
	seg[root].dif=seg[root<<1].dif=true;
}
void build(int root, int L, int R) {
	seg[root].val=0, seg[root].dif=true;
	if (L==R) return;
	int mid=(L+R)>>1;
	build(root<<1, L, mid);
	build(root<<1|1, mid+1, R);
}
void update(int root, int L, int R, int ql, int qr, int op, LL d) {
	if (ql>R || qr<L) return;
	if (ql<=L && qr>=R && seg[root].dif) {
		if (op==1) seg[root].val=(seg[root].val+d)%mod;
		else if (op==2) seg[root].val=(seg[root].val*d)%mod;
		else seg[root].val=d%mod;
		return;
	}
	int mid=(L+R)>>1;
	push(root, L, R);
	update(root<<1, L, mid, ql ,qr, op, d);
	update(root<<1|1, mid+1, R, ql, qr, op, d);
	if (!seg[root<<1].dif || !seg[root<<1|1].dif) seg[root].dif=false;
	else {
		if (seg[root<<1].val!=seg[root<<1|1].val) seg[root].dif=false;
		else {
			seg[root].dif=true;
			seg[root].val=seg[root<<1].val;
		}
	}
}
void query(int root, int L, int R, int ql, int qr, int p) {
	if (ql>R || qr<L) return;
	if (ql<=L && qr>=R && seg[root].dif) {
		LL tmp=pow(seg[root].val, p)*(R-L+1);
		ans=(ans+tmp)%mod;
		// ans+=qpow(seg[root].val, p)*(R-L+1)%mod;
		return;
	}
	int mid=(L+R)>>1;
	push(root, L, R);
	query(root<<1, L, mid, ql , qr, p);
	query(root<<1|1, mid+1, R, ql , qr, p);
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	while (~scanf("%d%d", &n, &m) && n && m) {
		build(1, 1, n);
		while (m--) {
			scanf("%d%d%d%d", &k, &x, &y, &z);
			if (k<=3) update(1, 1, n, x, y, k, z);
			else {
				ans=0;
				query(1, 1, n, x, y, z);
				printf("%lld\n", ans);
			}
		}
	}
}