#include <cstdio>
using namespace std;
typedef long long LL;
const int maxN=1e5+10;
const LL INF=0x3f3f3f3f;
int n, k, qs[maxN];
bool chk(int x) {
    LL sum=0, tmp=0;
    for (int L=1, R=1;R<=n;R++) {
        sum+=qs[R];
        while (sum>=x && L<=R) {
            tmp+=n-R+1;
            sum-=qs[L++];
        }
    }
    return tmp>=k;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d", &n, &k);
    for (int i=1;i<=n;i++)
        scanf("%d", qs+i);
    LL L=0, R=INF, ans, mid;
    while (L<=R) {
        mid=(L+R)>>1;
        if (chk(mid)) ans=mid, L=mid+1;
        else R=mid-1;
    }
    printf("%lld\n", ans);
}