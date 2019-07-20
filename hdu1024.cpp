#include <cstdio>
using namespace std;
const int maxN=1e6+10;
const int INF=0x3f3f3f3f;
int n, m, tmp;
int dp[maxN], qs[maxN], pre[maxN];
int max(int a, int b) {return a>b?a:b;}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &m, &n)) {
        for (int i=0;i<=n;i++)
            pre[i]=dp[i]=0;
        for (int i=1;i<=n;i++)
            scanf("%d", qs+i);
        for (int i=1;i<=m;i++) {
            tmp=-INF;
            for (int j=i;j<=n;j++) {
                dp[j]=max(dp[j-1], pre[j-1])+qs[j];
                pre[j-1]=tmp, tmp=max(tmp, dp[j]);
            }
        }
        printf("%d\n", tmp);
    }
}