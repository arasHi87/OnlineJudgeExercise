#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
const int maxN=5e4;
const int INF=0x3f3f3f3f;
struct Node{
    int sum, tag;
    Node():sum(0), tag(0){};
}tree[maxN<<2];
int t, n, qs[maxN];
void pull(int root) {
    tree[root].sum=tree[root<<1].sum+tree[(root<<1)+1].sum;
}
void build(int root, int L, int R) {
    if (L==R) {
        tree[root].sum=qs[L];
        return;
    }
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build((root<<1)+1, mid+1, R);
    pull(root);
}
void update(int root, int L, int R, int pos, int d) {
    if (L==R) {
        tree[root].sum+=d;
        return;
    }
    int mid=(L+R)>>1;
    if (pos<=mid) update(root<<1, L, mid, pos, d);
    else update((root<<1)+1, mid+1, R, pos, d);
    pull(root);
}
int query(int root, int L, int R, int ql, int qr) {
    if (qr<L || ql>R) return 0;
    if (ql==L && qr==R) return tree[root].sum;
    int mid=(L+R)>>1, ans=0;
    if (qr<=mid) ans+=query(root<<1, L, mid, ql, qr);
    else if (ql>mid) ans+=query((root<<1)+1, mid+1, R, ql, qr);
    else ans+=query(root<<1, L, mid, ql, mid)+query((root<<1)+1, mid+1, R, mid+1, qr);
    return ans;
}
signed main() {
    scanf("%lld", &t);
    for (int i=1;i<=t;i++) {
        memset(qs, 0, sizeof qs);
        scanf("%lld", &n);
        for (int j=1;j<=n;j++) scanf("%lld", qs+j);
        build(1, 1, n);
        char s[5];
        int x, y;
        printf("Case %lld:\n", i);
        while (scanf("%s", s) && s[0]!='E') {
            scanf("%lld%lld", &x, &y);
            if (s[0]=='Q') printf("%lld\n", query(1, 1, n, x, y));
            else if (s[0]=='A') update(1, 1, n, x, y);
            else update(1, 1, n, x, -y);
        }
    }
}