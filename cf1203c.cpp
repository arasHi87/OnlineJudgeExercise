#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
const int maxN=4e5+10;
int n;
LL qs[maxN];
inline LL __gcd(LL x, LL y) { while ((x%=y)&&(y%=x)); return x+y; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
        scanf("%lld", qs+i);
    LL x=qs[1], ans=0;
    for (int i=2;i<=n;i++)
        x=__gcd(x, qs[i]);
    for (LL i=1;i<=sqrt(x);i++)
        if (x%i==0)
            i*i==x ? ans++ : ans+=2;
    printf("%lld\n", ans);
}