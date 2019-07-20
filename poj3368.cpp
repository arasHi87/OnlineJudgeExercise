#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=1e5+10;
struct segment {
    int ls, rs, ms;
} seg[maxN<<2];
int n, m, x, y, qs[maxN];
inline void pushup(int root, int L, int R) {
    int mid=(L+R)>>1;
    seg[root].ls=seg[root<<1].ls;
    seg[root].rs=seg[root<<1|1].rs;
    seg[root].ms=max(seg[root<<1].ms, seg[root<<1|1].ms);
    if (qs[mid]==qs[mid+1]) {
        if (seg[root<<1].ls==mid-L+1) seg[root].ls+=seg[root<<1|1].ls;
        if (seg[root<<1|1].rs==R-mid) seg[root].rs+=seg[root<<1].rs;
        seg[root].ms=max(seg[root].ms, seg[root<<1].rs+seg[root<<1|1].ls);
    }
}
void build(int root, int L, int R) {
    if (L==R) {
        seg[root].ls=seg[root].rs=seg[root].ms=1;
        return;
    }
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
    pushup(root, L, R);
}
int query(int root, int L, int R, int ql, int qr) {
    if (ql==L && qr==R) return seg[root].ms;
    int mid=(L+R)>>1;
    if (qr<=mid) return query(root<<1, L, mid, ql, qr);
    else if (ql>mid) return query(root<<1|1, mid+1, R, ql ,qr);
    else {
        int tmp=max(query(root<<1, L, mid, ql, mid), query(root<<1|1, mid+1, R, mid+1, qr));
        if (qs[mid]==qs[mid+1])
            return max(tmp, min(seg[root<<1].rs, mid-ql+1)+min(seg[root<<1|1].ls, qr-mid));
        return tmp;
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        scanf("%d", &m);
        for (int i=1;i<=n;i++)
            scanf("%d", qs+i);
        build(1, 1, n);
        while (m--) {
            scanf("%d%d", &x, &y);
            printf("%d\n", query(1, 1, n, x, y));
        }
    }
}