#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN=1e5+10;
int n, k, t, qs[maxN];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i=1;i<=n;i++) 
            scanf("%d", qs+i);
        sort(qs+1, qs+1+n);
        int L=1, R=1; long long ans=0;
        for (L=1;L<=n;L++) {
            while (qs[R]-qs[L]<=k && R<=n) R++;
            ans+=(long long)(R-L-1);
            // printf("%d %d\n", L, R);
        }
        printf("%lld\n", ans);
    }
}