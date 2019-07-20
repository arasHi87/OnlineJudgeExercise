#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxN=1e5+10;
const LL INF=0x7fffffffffffffffLL;
LL n, k, qs[maxN];
bool chk(LL x) {
    LL sum=0;
    for (LL i=0;i<n;i++) {
        if (qs[i]>x) sum+=(qs[i]-x+k-2)/(k-1);
        if (sum>x) return 0;
    }
    return 1;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%lld", &n);
    for (LL i=0;i<n;i++)
        scanf("%lld", qs+i);
    scanf("%lld", &k);
    LL L=0, R=*max_element(qs, qs+n), mid, ans;
    if (k==1)
        return printf("%lld\n", R), 0;
    while (L<=R) {
        mid=(L+R)>>1;
        if (chk(mid)) ans=mid, R=mid-1;
        else L=mid+1;
    }
    printf("%lld\n", ans);
}