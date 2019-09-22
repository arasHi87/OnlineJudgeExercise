#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxN=1e7+10;
struct Node {
    LL val;
    Node *lc, *rc;
    // Node(): val(0), lc(NULL), rc(NULL) {};
    void pull() { val=max(lc->val, rc->val); }
};
int n, q, a, b;
LL qs[maxN];
inline LL max(LL a, LL b) { return a>b?a:b; }
Node *build(int L, int R) {
    Node *root=new Node();
    if (L==R) { root->val=qs[L]; return root; }
    int mid=(L+R)>>1;
    root->lc=build(L, mid);
    root->rc=build(mid+1, R);
    root->pull();
    return root;
}
LL query(Node *root, int L, int R, int ql, int qr) {
    if (ql>R || qr<L) return -1;
    if (ql<=L && qr>=R) return root->val;
    int mid=(L+R)>>1;
    return max(query(root->lc, L, mid, ql, qr), query(root->rc, mid+1, R, ql, qr));
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d", &n, &q);
    for (int i=1;i<=n;i++)
        scanf("%lld", qs+i);
    Node *root=build(1, n);
    while (q--) {
        scanf("%d%d", &a, &b);
        if (a>b) swap(a, b);
        printf("%lld\n", query(root, 1, n, a, b));
    }
}