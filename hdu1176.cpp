#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e5+10;
int n, t, x, mx, dp[maxN][15];
int max(int a, int b) { return a>b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        memset(dp, 0, sizeof dp), mx=0;
        for (int i=1;i<=n;i++)
            scanf("%d%d", &x, &t), dp[t][x]++, mx=max(mx, t);
        for (int i=mx-1;i>=0;i--)
            for (int j=0;j<=10;j++)
                if (j==0) dp[i][j]+=max(dp[i+1][j], dp[i+1][j+1]);
                else if (j==10) dp[i][j]+=max(dp[i+1][j], dp[i+1][j-1]);
                else dp[i][j]+=max(dp[i+1][j+1], max(dp[i+1][j], dp[i+1][j-1]));
        printf("%d\n", dp[0][5]);
    }
}