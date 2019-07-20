#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e4+10;
const int INF=0x3f3f3f3f;
int t, n, e, f;
int dp[maxN], w[500+10], v[500+10];
int min(int a, int b) { return a<b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &e, &f, &n), f-=e;
        memset(dp, INF, sizeof dp), dp[0]=0;
        for (int i=1;i<=n;i++)
            scanf("%d%d", v+i, w+i);
        for (int i=1;i<=n;i++)
            for (int j=w[i];j<=f;j++)
                dp[j]=min(dp[j], dp[j-w[i]]+v[i]);
        if (dp[f]==INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[f]);
    }
}