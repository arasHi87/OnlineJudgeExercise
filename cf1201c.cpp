#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxN=2e5+10;
LL n, k, qs[maxN];
inline LL min(LL a, LL b) { return a<b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%lld%lld", &n, &k);
    for (LL i=1;i<=n;i++)
        scanf("%lld", qs+i);
    sort(qs+1, qs+1+n);
    LL mid=n>>1, cnt=1, ans=qs[mid];
    while (k && mid+1<n) {
        LL tmp=min(k/cnt, qs[mid+1]-ans);
        ans+=tmp, k-=tmp*cnt;
        cnt++, mid++;
    }
    if (k) ans+=k/cnt;
    printf("%lld\n", ans);
}