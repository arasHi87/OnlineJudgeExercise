#include <cstdio>
typedef long long LL;
const int maxN=1e6+10;
const long long MOD=1e9+7;
LL t, n, k, p, ans, a[maxN];
bool chk(LL x) { return (x+x+k-1)*k/2<=n; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &k);
        if ((k*(k+1))/2>n) { puts("-1"); continue; }
        LL L=1, R=n, mid, tmp;
        while (L<=R) {
            mid=(L+R)>>1;
            if (chk(mid)) tmp=mid, L=mid+1;
            else R=mid-1;
        }
        p=n-(tmp+tmp+k-1)*k/2, ans=1;
        for (LL i=1;i<=k;i++) a[i]=tmp+i-1;
        for (LL i=k;i>k-p;i--) a[i]++;
        for (LL i=1;i<=k;i++) ans*=a[i], ans%=MOD;
        printf("%lld\n", ans);
    }
}