#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
const int maxN=1e4+10;

int w[maxN], p[maxN];
int dp[maxN];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i=1;i<=n;i++) scanf("%d%d", &p[i], &w[i]);
        memset(dp, 0, sizeof dp);
        for (int i=1;i<=n;i++)
            for (int j=30;j>=w[i];j--)
                dp[j]=max(dp[j], dp[j-w[i]]+p[i]);
        int m, ans=0;
        scanf("%d", &m);
        while (m--) {
            int wg;
            scanf("%d", &wg);
            ans+=dp[wg];
        }
        printf("%d\n", ans);
    }
}