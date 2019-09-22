#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int maxN=1e5+10;
struct Node {
    int val, id;
    bool operator < (const Node &rhs) const {
        return val==rhs.val ? id<rhs.id : val>rhs.val;
    }
} qs[maxN];
int t, n, ans, tmp;
signed main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n), ans=tmp=0;
        for (int i=1;i<=n;i++)
            scanf("%lld", &qs[i].val), qs[i].id=i, tmp+=qs[i].val;
        sort(qs+1, qs+1+n);
        for (int i=1;i<=n;i++)
            printf("%lld%c", qs[i].id, (i==n ? '\n' : ' ')), ans+=tmp, tmp-=qs[i].val;
        printf("%lld\n", ans);
    }
}