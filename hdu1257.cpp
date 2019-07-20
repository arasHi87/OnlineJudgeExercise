#include <cstdio>
using namespace std;
const int maxN=1e5+10;
const int INF=0x3f3f3ff3;
int n, x, dp[maxN];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        int res=0;
        for (int i=1;i<=n;i++) {
            scanf("%d", &x);
            int mn=INF, tmp, flag=0;
            for (int i=1;i<=res;i++)
                if (x<=dp[i] && mn>dp[i]-x)
                    mn=dp[i]-x, tmp=i, flag=1;
            if (flag) dp[tmp]=x;
            else res++, dp[res]=x;
        }
        printf("%d\n", res);
    }
}