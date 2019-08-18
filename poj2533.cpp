#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=1e3+10;
const int INF=0x3f3f3f3f;
int n, qs[maxN], dp[maxN];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        for (int i=1;i<=n;i++)
            scanf("%d", qs+i);
        memset(dp, INF, sizeof dp);
        for (int i=1;i<=n;i++)
            *lower_bound(dp, dp+n, qs[i])=qs[i];
        printf("%ld\n", lower_bound(dp, dp+n, INF)-dp);
    }
}