#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxN=1e5+10;
typedef long long LL;
struct segment {
    LL sum;
    int tag;
    segment(): sum(0), tag(0) {};
} seg[maxN<<2];
int n, q, t, x, y, kase=1;
LL qs[maxN];
inline void pull(int root) {
    seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
    seg[root].tag=seg[root<<1].tag&&seg[root<<1|1].tag;
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
void update(int root, int L, int R, int ql, int qr) {
    if (ql>R || qr<L) return;
    if (L==R) {
        seg[root].sum=sqrt(seg[root].sum);
        if (seg[root].sum<=1)
            seg[root].tag=1;
        return;
    }
    int mid=(L+R)>>1;
    if (!seg[root].tag)
        update(root<<1, L, mid, ql, qr),
        update(root<<1|1, mid+1, R, ql ,qr);
    pull(root);
}
LL query(int root, int L, int R, int ql, int qr) {
    if (ql>R || qr<L) return 0;
    if (ql<=L && qr>=R) return seg[root].sum;
    int mid=(L+R)>>1;
    return query(root<<1, L, mid, ql, qr)+query(root<<1|1, mid+1, R, ql, qr);
}
int main() {
    #ifdef local
        freopen("in.txt", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        memset(qs, 0, sizeof qs);
        for (int i=1;i<=(n<<2);i++)
            seg[i].sum=0, seg[i].tag=0;
        for (int i=1;i<=n;i++)
            scanf("%lld", qs+i);
        scanf("%d", &q);
        printf("Case #%d:\n", kase++);
        build(1, 1, n);
        // printf("%lld\n", query(1, 1, n, 1, n));
        while (q--) {
            scanf("%d%d%d", &t, &x, &y);
            if (x>y) swap(x, y);
            if (t) printf("%lld\n", query(1, 1, n, x, y));
            else update(1, 1, n, x, y);
        }
        puts("");
    }
}