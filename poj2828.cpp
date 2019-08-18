#include <cstdio>
#include <cstring>
#include <algorithm>
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;
const int maxN=2e5+10;
int n, seg[maxN<<2], ans[maxN];
pii qs[maxN];
inline void pull(int root) { seg[root]=seg[root<<1]+seg[root<<1|1]; }
void build(int root, int L, int R) {
    if (L==R) { seg[root]=1; return; }
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
    pull(root);
}
void update(int root, int L, int R, int pos, int d) {
    if (L==R) { seg[root]=0, ans[L]=d; return; }
    int mid=(L+R)>>1;
    if (pos<=seg[root<<1]) update(root<<1, L, mid, pos, d);
    else update(root<<1|1, mid+1, R, pos-seg[root<<1], d);
    pull(root);
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        for (int i=1;i<=n;i++)
            scanf("%d%d", &qs[i].f, &qs[i].s), qs[i].f++;
        build(1, 1, n);
        for (int i=n;i>=1;i--)
            update(1, 1, n, qs[i].f, qs[i].s);
        printf("%d", ans[1]);
        for (int i=2;i<=n;i++)
            printf(" %d", ans[i]);
        puts("");
    }
}