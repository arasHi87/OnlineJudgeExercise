#include <bits/stdc++.h>
using namespace std;
const int maxN=5e4+10;
struct segment {
    int s, ls, rs, ms;
} seg[maxN<<2];
int n, m, qs[maxN];
inline int max(int a, int b) { return a>b?a:b; }
inline void pushup(int rt) {
    seg[rt].ls=max(seg[rt<<1].ls, seg[rt<<1].s+seg[rt<<1|1].ls);
    seg[rt].rs=max(seg[rt<<1|1].rs, seg[rt<<1|1].s+seg[rt<<1].rs);
    seg[rt].ms=max(max(seg[rt<<1].ms, seg[rt<<1|1].ms), seg[rt<<1].rs+seg[rt<<1|1].ls);
    seg[rt].s=seg[rt<<1].s+seg[rt<<1|1].s;
}
void build(int rt, int L, int R) {
    if (L==R) {
        seg[rt].ms=seg[rt].ls=seg[rt].rs=seg[rt].s=qs[L];
        return;
    }
    int mid=(L+R)>>1;
    build(rt<<1, L, mid);
    build(rt<<1|1, mid+1, R);
    pushup(rt);
}
segment query(int rt, int L, int R, int ql, int qr) {
    if (ql==L && qr==R) return seg[rt];
    int mid=(L+R)>>1;
    if (qr<=mid) return query(rt<<1, L, mid, ql, qr);
    else if (ql>mid) return query(rt<<1|1, mid+1, R, ql, qr);
    else {
        segment tmpL=query(rt<<1, L, mid, ql, mid);
        segment tmpR=query(rt<<1|1, mid+1, R, mid+1, qr);
        segment tmp;
        tmp.ls=max(tmpL.ls, tmpL.s+tmpR.ls);
        tmp.rs=max(tmpR.rs, tmpR.s+tmpL.rs);
        tmp.ms=max(max(tmpL.ms, tmpR.ms), tmpL.rs+tmpR.ls);
        tmp.s=tmpL.s+tmpR.s;
        return tmp;
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
        scanf("%d", qs+i);
    build(1, 1, n);
    scanf("%d", &m);
    for (int i=1, x, y;i<=m;i++) {
        scanf("%d%d", &x, &y);
        printf("%d\n", query(1, 1, n, x, y).ms);
    }
}