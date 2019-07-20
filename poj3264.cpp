#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxN=5e4;
const int INF=0x3f3f3f3f;
struct segment {
    int mx, mn;
    segment(): mx(0), mn(0) {};
} seg[maxN<<2];
int n, q, x, y, qs[maxN], mx, mn;
inline void pull(int root) {
    seg[root].mx=max(seg[root<<1].mx, seg[root<<1|1].mx);
    seg[root].mn=min(seg[root<<1].mn, seg[root<<1|1].mn);
    // seg[root].ans=seg[root].mx-seg[root].mn;
}
void build(int root, int L, int R) {
    if (L==R) {
        seg[root].mx=qs[L];
        seg[root].mn=qs[L];
        return;
    }
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
    pull(root);
}
void query(int root, int L, int R, int ql, int qr) {
    if (ql>R || qr<L) return;
    if (ql<=L && qr>=R)  {
        mx=max(mx, seg[root].mx);
        mn=min(mn, seg[root].mn);
        return;
    }
    int mid=(L+R)>>1;
    query(root<<1, L, mid, ql, qr);
    query(root<<1|1, mid+1, R, ql, qr);
}
int main() {
    #ifdef local
        freopen("in.txt", "r", stdin);
    #endif
    scanf("%d%d", &n, &q);
    for (int i=1;i<=n;i++)
        scanf("%d", qs+i);
    build(1, 1, n);
    while (q--) {
        scanf("%d%d", &x, &y);
        mx=-INF, mn=INF;
        query(1, 1, n, x, y);
        printf("%d\n", mx-mn);
    }
}