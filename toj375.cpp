#include <cstdio>
#include <cstring>
using namespace std;
int n, k;
int dp[1010][5010], qs[5010];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &k)) {
        memset(dp, 0, sizeof dp);
        for (int i=k;i>=1;i--)
            scanf("%d", qs+i);
        for (int i=1;i<=n+1;i++) {
            for (int j=i*3;j<=k+1;j++) {
                
            }
        }
    }
}