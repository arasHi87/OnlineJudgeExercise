#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxN=1e5+10;
struct segment {
    int sum, tag;
    segment(): sum(1), tag(0) {};
} seg[maxN<<2];
int t, n, q, x, y, z;
inline void pull(int root) {
    seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
}
void build(int root, int L, int R) {
    if (L==R) return;
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
    pull(root);
}
inline void push(int root, int L, int R) {
    if (seg[root].tag) {
        int mid=(L+R)>>1;
        seg[root<<1].sum=seg[root].tag*(mid-L+1);
        seg[root<<1|1].sum=seg[root].tag*(R-mid);
        seg[root<<1].tag=seg[root<<1|1].tag=seg[root].tag;
        seg[root].tag=0;
    }
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
        freopen("in.txt", "r", stdin);
    #endif
    scanf("%d", &t);
    for (int i=1;i<=t;i++) {
        scanf("%d\n%d", &n, &q);
        for (int i=1;i<=n;i++)
            seg[i].sum=1, seg[i].tag=0;
        build(1, 1, n);
        while (q--) {
            scanf("%d%d%d", &x, &y, &z);
            update(1, 1, n, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n", i, query(1, 1, n, 1, n));
    }
}