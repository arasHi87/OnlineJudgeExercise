#include <bits/stdc++.h>
using namespace std;
const int maxN=2e5+10;
int n, m, seg[maxN<<2];
inline int max(int a, int b) { return a>b?a:b; }
void build(int root, int L, int R) {
    if (L==R) {
        scanf("%d", &seg[root]);
        return;
    }
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
    seg[root]=max(seg[root<<1], seg[root<<1|1]);
}
void modify(int root, int L, int R, int pos, int x) {
    if (L==R) {
        seg[root]+=x;
        return;
    }
    int mid=(L+R)>>1;
    if (pos<=mid) modify(root<<1, L, mid, pos, x);
    else modify(root<<1|1, mid+1, R, pos, x);
    seg[root]=max(seg[root<<1], seg[root<<1|1]);
}
void update(int root, int L, int R, int ql, int qr, int x) {
    if (ql>R || qr<L || seg[root]<x) return;
    if (L==R) {
        seg[root]%=x;
        return;
    }
    int mid=(L+R)>>1;
    update(root<<1, L, mid, ql, qr, x);
    update(root<<1|1, mid+1, R, ql, qr, x);
    seg[root]=max(seg[root<<1], seg[root<<1|1]);
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    build(1, 1, n);
    scanf("%d", &m);
    for (int i=1, k, a, b, c;i<=m;i++) {
        scanf("%d", &k);
        if (k==1) {
            scanf("%d%d", &a, &b);
            modify(1, 1, n, b+1, a);
        } else if (k==2) {
            scanf("%d%d%d", &a, &b, &c);
            update(1, 1, n, a+1, b+1, c);
        } else printf("%d\n", seg[1]);
    }
}