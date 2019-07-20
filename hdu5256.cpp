#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=1e5+10;
const int INF=0x3f3f3f3f;
int t, n, qs[maxN], re[maxN], dp[maxN];
int max(int a, int b) { return a>b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    for (int kase=1;kase<=t;kase++) {
        printf("Case #%d:\n", kase);
        scanf("%d", &n);
        memset(dp, INF, sizeof dp);
        for (int i=1;i<=n;i++)
            scanf("%d", qs+i), re[i]=qs[i]-i;
        int len=-1;
        for (int i=1;i<=n;i++) {
            int pos=upper_bound(dp, dp+n, re[i])-dp;
            dp[pos]=re[i], len=max(len, pos+1);
        }
        printf("%d\n", n-len);
    }
}