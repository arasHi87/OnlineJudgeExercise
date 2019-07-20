#include <iostream>
#include <memory.h>
using namespace std;

int a[10005];
int dp[10005][105];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i=1;i<=n;i++) {
            scanf("%d", &a[i]);
            a[i]=abs(a[i])%k;
        }
        memset(dp, 0, sizeof dp);
        dp[0][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=0;j<k;j++)
                if (dp[i-1][j]) {
                    dp[i][abs(j+a[i])%k]=1;
                    dp[i][abs(j-a[i])%k]=1;
                }
        if (dp[n][0]) printf("Divisible\n");
        else printf("Not divisible\n");
    }
}