#include <cstdio>
#define DE(x) printf("DE: %d\n", x);
using namespace std;
const int maxN=5e4+10;
struct segment {
    int ls, rs, ms, lz;
    // -1->unused 0->full 1->empty
} seg[maxN<<2];
int n, q, op, x, y;
inline int max(int a, int b) { return a>b?a:b; }
inline void PushUp(int rt, int L, int R) {
    int mid=(L+R)>>1;
    seg[rt].ls=seg[rt<<1].ls;
    seg[rt].rs=seg[rt<<1|1].rs;
    if (seg[rt].ls==mid-L+1) seg[rt].ls+=seg[rt<<1|1].ls;
    if (seg[rt].rs==R-mid) seg[rt].rs+=seg[rt<<1].rs;
    seg[rt].ms=max(seg[rt<<1].rs+seg[rt<<1|1].ls, max(seg[rt<<1].ms, seg[rt<<1|1].ms));
}
inline void PushDown(int rt, int L, int R) {
    if (seg[rt].lz!=-1) {
        int mid=(L+R)>>1;
        seg[rt<<1].lz=seg[rt<<1|1].lz=seg[rt].lz;
        seg[rt<<1].ls=seg[rt<<1].rs=seg[rt<<1].ms=seg[rt].lz?mid-L+1:0;
        seg[rt<<1|1].ls=seg[rt<<1|1].rs=seg[rt<<1|1].ms=seg[rt].lz?R-mid:0;
        seg[rt].lz=-1;
    }
}
void build(int rt, int L, int R) {
    seg[rt].ls=seg[rt].rs=seg[rt].ms=R-L+1, seg[rt].lz=-1;
    if (L==R) return;
    int mid=(L+R)>>1;
    build(rt<<1, L, mid);
    build(rt<<1|1, mid+1, R);
    // PushUp(rt, L, R);
}
void update(int rt, int L, int R, int ql, int qr, int op) {
    if (ql==L && qr==R) {
        // 0->full 1->empty
        seg[rt].ls=seg[rt].rs=seg[rt].ms=op?R-L+1:0, seg[rt].lz=op;
        return;
    }
    PushDown(rt, L, R);
    int mid=(L+R)>>1;
    if (qr<=mid) update(rt<<1, L, mid, ql, qr, op);
    else if (ql>mid) update(rt<<1|1, mid+1, R, ql, qr, op);
    else update(rt<<1, L, mid, ql, mid, op), update(rt<<1|1, mid+1, R, mid+1, qr, op);
    PushUp(rt, L, R);
}
int query(int rt, int L, int R, int d) {
    if (L==R) return L;
    PushDown(rt, L, R);
    int mid=(L+R)>>1;
    if (d<=seg[rt<<1].ms) return query(rt<<1, L, mid, d);
    else if (d<=seg[rt<<1].rs+seg[rt<<1|1].ls) return mid-seg[rt<<1].rs+1;
    else return query(rt<<1|1, mid+1, R, d);
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &q)) {
        build(1, 1, n);
        // DE(seg[1].ms);
        while (q--) {
            // DE(seg[1].ms)
            scanf("%d", &op);
            if (op==1) {
                scanf("%d", &x);
                if (x>seg[1].ms) puts("0");
                else {
                    int pos=query(1, 1, n, x);
                    printf("%d\n", pos);
                    update(1, 1, n, pos, pos+x-1, 0);
                }
            } else {
                scanf("%d%d", &x, &y);
                update(1, 1, n, x, x+y-1, 1);
            }
        }
    }
}