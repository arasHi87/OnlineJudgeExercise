#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e5+10;
int n, v;
int w[maxN], p[maxN], dp[maxN];
inline int max(int a, int b) { return a>b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &v, &n)) {
        memset(dp, 0, sizeof dp);
        for (int i=1;i<=n;i++)
            scanf("%d%d", w+i, p+i);
        for (int i=1;i<=n;i++)
            for (int j=w[i];j<=v;j++)
                dp[j]=max(dp[j], dp[j-w[i]]+p[i]);
        printf("%d\n", dp[v]);
    }
}