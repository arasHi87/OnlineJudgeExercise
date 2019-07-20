#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxN=2e4+10;
int n;
LL a[maxN], b[maxN], c[maxN];
LL chk(LL x) {
    LL sum=0, k;
    for (int i=1;i<=n;i++) {
        k=min(x, b[i]);
        if (k>=a[i]) sum+=(k-a[i])/c[i]+1;
    }
    return sum;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        for (int i=1;i<=n;i++)
            scanf("%lld%lld%lld", a+i, b+i, c+i);
        LL L=0, R=1LL<<31, mid;
        while (L<R) {
            mid=(L+R)>>1;
            if (chk(mid)%2) R=mid;
            else L=mid+1;
        }
        if (L==1LL<<31) puts("DC Qiang is unhappy.");
        else {
            while (!chk(L)%2) L--;
            printf("%lld %lld\n", L, chk(L)-chk(L-1));
        }
    }
}