#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxN=1e5+10;
typedef long long LL;
struct segment {
    LL sum, tag;
    segment(): sum(0), tag(0){};
} seg[maxN<<2];
int n, q, x, y;
LL z, qs[maxN];
char c[1];
inline void pull(int root) {
    seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
}
void build(int root, int L, int R) {
    if (L==R) {
        seg[root].sum=qs[L];
        return;
    }
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
    pull(root);
}
inline void push(int root, int L, int R) {
    if (seg[root].tag) {
        int mid=(L+R)>>1;
        seg[root<<1].sum+=seg[root].tag*(mid-L+1);
        seg[root<<1|1].sum+=seg[root].tag*(R-mid);
        seg[root<<1].tag+=seg[root].tag;
        seg[root<<1|1].tag+=seg[root].tag;
        seg[root].tag=0;
    }
}
void update(int root, int L, int R, int ql, int qr, LL d) {
    if (ql>R || qr<L) return;
    if (ql<=L && qr>=R) {
        seg[root].sum+=d*(R-L+1);
        seg[root].tag+=d;
        return;
    }
    push(root, L, R);
    int mid=(L+R)>>1;
    update(root<<1, L, mid, ql, qr, d);
    update(root<<1|1, mid+1, R, ql, qr, d);
    pull(root);
}
LL query(int root, int L, int R, int ql, int qr) {
    if (ql>R || qr<L) return 0;
    if (ql<=L && qr>=R) return seg[root].sum;
    push(root, L, R);
    int mid=(L+R)>>1;
    return query(root<<1, L, mid, ql, qr)+query(root<<1|1, mid+1, R, ql, qr);
}
int main() {
    #ifdef local
        freopen("in.txt", "r", stdin);
    #endif
    scanf("%d%d", &n, &q);
    for (int i=1;i<=n;i++)
        scanf("%lld", qs+i);
    build(1, 1, n);
    while (q--) {
        scanf("%s%d%d", c, &x, &y);
        if (c[0]=='Q') printf("%lld\n", query(1, 1, n, x, y));
        else {
            scanf("%lld", &z);
            update(1, 1, n, x, y, z);
        }
    }
}