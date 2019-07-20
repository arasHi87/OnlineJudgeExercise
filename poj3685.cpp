#include <cstdio>
#include <cstring>
#include <algorithm>
#define get(x, y) x*x+100000*x+y*y-100000*y+x*y
using namespace std;
typedef long long LL;
const LL INF=0x3f3f3f3f3f3f3f3f;
LL t, n, m;
bool chk(LL x) {
    LL L, R, mid, ans, sum=0;
    for (LL i=1;i<=n;i++) {
        L=1, R=n, ans=0;
        while (L<=R) {
            mid=(L+R)>>1;
            if (get(mid, i)<=x) ans=mid, L=mid+1;
            else R=mid-1;
        }
        sum+=ans;
    }
    return sum>=m;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        LL L=-INF, R=INF, mid, ans;
        while (L<=R) {
            mid=(L+R)>>1;
            if (chk(mid)) ans=mid, R=mid-1;
            else L=mid+1;
        }
        printf("%lld\n", ans);
    }
}