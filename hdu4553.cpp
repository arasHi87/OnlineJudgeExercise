#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN=1e5+10;
struct segment {
	int ls, rs, ms;
	segment(): ls(0), rs(0), ms(0) {};
} DS[maxN<<2], NS[maxN<<2];
int t, n, m, x, y, tmp, ans=-1;
char opt[5];
inline void pull(int root, int L, int R) {
	int mid=(L+R)>>1;
	// pull DS
	DS[root].ls=DS[root<<1].ls;
	DS[root].rs=DS[root<<1|1].rs;
	if (DS[root<<1].ls==mid-L+1) DS[root].ls+=DS[root<<1|1].ls;
	if (DS[root<<1|1].rs==R-mid) DS[root].rs+=DS[root<<1].rs;
	DS[root].ms=max(max(DS[root<<1].ms, DS[root<<1|1].ms), DS[root<<1].rs+DS[root<<1|1].ls);
	// pull NS
	NS[root].ls=NS[root<<1].ls;
	NS[root].rs=NS[root<<1|1].rs;
	if (NS[root<<1].ls==mid-L+1) NS[root].ls+=NS[root<<1|1].ls;
	if (NS[root<<1|1].rs==R-mid) NS[root].rs+=NS[root<<1].rs;
	NS[root].ms=max(max(NS[root<<1].ms, NS[root<<1|1].ms), NS[root<<1].rs+NS[root<<1|1].ls);
}
inline void push(int root, int L, int R) {
	int mid=(L+R)>>1;
	// push DS
	if (DS[root].ms==0) {
		DS[root<<1].ls=DS[root<<1].rs=DS[root<<1].ms=0;
		DS[root<<1|1].ls=DS[root<<1|1].rs=DS[root<<1|1].ms=0;
	}
	if (DS[root].ms==R-L+1) {
		DS[root<<1].ls=DS[root<<1].rs=DS[root<<1].ms=mid-L+1;
		DS[root<<1|1].ls=DS[root<<1|1].rs=DS[root<<1|1].ms=R-mid;
	}
	// push NS
	if (NS[root].ms==0) {
		NS[root<<1].ls=NS[root<<1].rs=NS[root<<1].ms=0;
		NS[root<<1|1].ls=NS[root<<1|1].rs=NS[root<<1|1].ms=0;
	}
	if (NS[root].ms==R-L+1) {
		NS[root<<1].ls=NS[root<<1].rs=NS[root<<1].ms=mid-L+1;
		NS[root<<1|1].ls=NS[root<<1|1].rs=NS[root<<1|1].ms=R-mid;
	}
}
void build(int root, int L, int R) {
	DS[root].ls=DS[root].rs=DS[root].ms=R-L+1;
	NS[root].ls=NS[root].rs=NS[root].ms=R-L+1;
	if (L==R) return;
	int mid=(L+R)>>1;
	build(root<<1, L, mid);
	build(root<<1|1, mid+1, R);
}
void update(int root, int L, int R, int ql, int qr, int op) {
	// op -> 1 DS
	// op -> 2 NS
	// op -> 3 clean
	if (ql>R || qr<L) return;
	if (ql<=L && qr>=R) {
		if (op==1) {
			DS[root].ls=DS[root].rs=DS[root].ms=0;
		} else if (op==2) {
			DS[root].ls=DS[root].rs=DS[root].ms=0;
			NS[root].ls=NS[root].rs=NS[root].ms=0;
		} else {
			DS[root].ls=DS[root].rs=DS[root].ms=R-L+1;
			NS[root].ls=NS[root].rs=NS[root].ms=R-L+1;
		}
		return;
	}
	int mid=(L+R)>>1;
	push(root, L, R);
	update(root<<1, L, mid, ql, qr, op);
	update(root<<1|1, mid+1, R, ql, qr, op);
	pull(root, L, R);
}
void DSquery(int root, int L, int R) {
	if (ans!=-1) return;
	if (DS[root].ls>=x) ans=L;
	else if (DS[root].ms>=x) {
		int mid=(L+R)>>1;
		push(root, L, R);
		DSquery(root<<1, L, mid);
		if (DS[root<<1].rs+DS[root<<1|1].ls>=x && ans==-1)
			ans=(DS[root<<1].rs==0?mid+1:mid-DS[root<<1].rs+1);
		DSquery(root<<1|1, mid+1, R);
	} else if (DS[root].rs>=x) ans=R-DS[root].rs+1;
}
void NSquery(int root, int L, int R) {
	if (ans!=-1) return;
	if (NS[root].ls>=x) ans=L;
	else if (NS[root].ms>=x) {
		int mid=(L+R)>>1;
		push(root, L, R);
		NSquery(root<<1, L, mid);
		if (NS[root<<1].rs+NS[root<<1|1].ls>=x && ans==-1)
			ans=(NS[root<<1].rs==0?mid+1:mid-NS[root<<1].rs+1);
		NSquery(root<<1|1, mid+1, R);
	} else if (NS[root].rs>=x) ans=R-NS[root].rs+1;
}
int main() {
	#ifdef local
		freopen("in", "r", stdin);
	#endif
	scanf("%d", &t);
	for (int kase=1;kase<=t;kase++) {
		printf("Case %d:\n", kase);
		scanf("%d%d", &n, &m);
		build(1, 1, n);
		while (m--) {
			scanf("%s%d", opt, &x); ans=-1;
			if (opt[0]=='D') {
				DSquery(1, 1, n);
				if (ans==-1) printf("fly with yourself\n");
				else {
					printf("%d,let's fly\n", ans);
					update(1, 1, n, ans, ans+x-1, 1);
				}
			} else if (opt[0]=='N') {
				DSquery(1, 1, n);
				if (ans==-1) {
					NSquery(1, 1, n);
					if (ans==-1) printf("wait for me\n");
					else {
						printf("%d,don't put my gezi\n", ans);
						update(1, 1, n, ans, ans+x-1, 2);
					}
				} else {
					printf("%d,don't put my gezi\n", ans);
					update(1, 1, n, ans, ans+x-1, 2);
				}
			} else {
				scanf("%d", &y);
				printf("I am the hope of chinese chengxuyuan!!\n");
				update(1, 1, n, x, y, 3);
			}
		}
	}
}