#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=2e5+10;
int n, q;
int seg[maxN<<2], lzy[maxN<<2], qs[maxN];
inline int max(int a, int b) { return a>b?a:b; }
inline void PushDown(int root) {
    if (lzy[root]!=-1) {
        lzy[root<<1]=max(lzy[root<<1], lzy[root]);
        lzy[root<<1|1]=max(lzy[root<<1|1], lzy[root]);
        lzy[root]=-1;
    }
}
void build(int root, int L, int R) {
    if (L==R) { seg[root]=qs[L]; return; }
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
}
void update(int root, int L, int R, int pos, int d) {
    if (L==R) { seg[root]=d, lzy[root]=0; return; }
    PushDown(root);
    int mid=(L+R)>>1;
    if (pos<=mid) update(root<<1, L, mid, pos, d);
    else update(root<<1|1, mid+1, R, pos, d);
}
int query(int root, int L, int R, int pos) {
    if (L==R) return seg[root]=max(seg[root], lzy[root]);
    PushDown(root);
    int mid=(L+R)>>1;
    if (pos<=mid) return query(root<<1, L, mid, pos);
    else return query(root<<1|1, mid+1, R, pos);
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    memset(lzy, -1, sizeof lzy);
    for (int i=1;i<=n;i++)
        scanf("%d", qs+i);
    build(1, 1, n);
    scanf("%d", &q);
    while (q--) {
        int op, x, y;
        scanf("%d", &op);
        if (op==1) {
            scanf("%d%d", &x, &y);
            update(1, 1, n, x, y);
        } else {
            scanf("%d", &x);
            lzy[1]=max(lzy[1], x);
        }
    }
    for (int i=1;i<=n;i++)
        printf("%d ", query(1, 1, n, i));
    puts("");
}