#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxN=2e5+10;
const int INF=0x3f3f3f3f;
struct Node{
    int mx;
    Node(): mx(0){};
} tree[maxN<<2];
int n, m, x, y, qs[maxN];
char c[1];
inline void pull(int root) {
    tree[root].mx=max(tree[root<<1].mx, tree[(root<<1)+1].mx);
}
void build (int root, int L, int R) {
    if (R==L) {
        tree[root].mx=qs[L];
        return;
    }
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build((root<<1)+1, mid+1, R);
    pull(root);
}
void modify(int root, int L, int R, int pos, int val) {
    if (L==R) {
        tree[root].mx=val;
        return;
    }
    int mid=(L+R)>>1;
    if (pos<=mid) modify(root<<1, L, mid, pos, val);
    else modify((root<<1)+1, mid+1, R, pos, val);
    pull(root);
}
int query(int root, int L, int R, int ql, int qr) {
    if (ql<=L && qr>=R) return tree[root].mx;
    else if (qr<L || ql>R) return -INF;
    int mid=(L+R)>>1;
    // if (qr<=mid) mx=max(mx, query(root<<1, L, mid, ql, qr));
    // else if (ql>mid) mx=max(mx, query((root<<1)+1, mid+1, R, ql, qr));
    // else mx=max(query(root<<1, L, mid, ql, qr), query((root<<1)+1, mid+1, R, ql, qr));
    // return mx;
    return max(query(root<<1, L, mid, ql, qr), query((root<<1)+1, mid+1, R, ql, qr));
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(qs, 0, sizeof qs);
        for (int i=1;i<=n;i++)
            scanf("%d", qs+i);
        build(1, 1, n);
        for (int i=1;i<=m;i++) {
            scanf("%s%d%d", c, &x, &y);
            if (c[0]=='Q') printf("%d\n", query(1, 1, n, x, y));
            else modify(1, 1, n, x, y);
        }
    }
}