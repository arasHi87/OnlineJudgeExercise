#include <cstdio>
#include <cstring>
#define mem memset
using namespace std;
const int maxN=8e3+10;
int n, a, b, c, last;
int seg[maxN<<2], ans[maxN];
inline void PushDown(int root) {
    if (seg[root]!=-1) {
        seg[root<<1]=seg[root<<1|1]=seg[root];
        seg[root]=-1;
    }
}
void update(int root, int L, int R, int ql, int qr, int x) {
    if (ql>R || qr<L) return;
    if (ql<=L && qr>=R) {
        seg[root]=x;
        return;
    }
    PushDown(root);
    int mid=(L+R)>>1;
    update(root<<1, L, mid, ql, qr, x);
    update(root<<1|1, mid+1, R, ql, qr, x);
}
void query(int root, int L, int R) {
    if (L==R) {
        if (seg[root]!=last) {
            ans[seg[root]]++;
            last=seg[root];
        }
        return;
    }
    PushDown(root);
    int mid=(L+R)>>1;
    query(root<<1, L, mid);
    query(root<<1|1, mid+1, R);
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        mem(seg, -1, sizeof seg);
        mem(ans, 0, sizeof ans), last=-1;
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d", &a, &b, &c);
            update(1, 1, 8000, a+1, b, c);
        }
        query(1, 1, 8000);
        for (int i=0;i<=8000;i++)
            if (ans[i])
                printf("%d %d\n", i, ans[i]);
        puts("");
    }
}