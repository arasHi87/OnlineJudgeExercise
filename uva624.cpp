#include <iostream>
#include <cstring>
using namespace std;
const int maxN=1e5+5;

int vis[25][maxN], dp[maxN], val[maxN];

int main() {
    int n, t;
    while (~scanf("%d%d", &n, &t)) {
        memset(val, 0, sizeof val);
        memset(vis, 0, sizeof vis);
        memset(dp, 0, sizeof dp);
        for (int i=1;i<=t;i++) scanf("%d", val+i);
        for (int i=1;i<=t;i++) {
            for (int j=n;j>=val[i];j--) {
                if (dp[j]<dp[j-val[i]]+val[i]) {
                    dp[j]=dp[j-val[i]]+val[i];
                    vis[i][j]=1;
                }
            }
        }
        for (int i=t, j=n;i>=0;i--)
            if (vis[i][j])
                printf("%d ", val[i]), j-=val[i];
        printf("sum:%d\n", dp[n]);
    }
}