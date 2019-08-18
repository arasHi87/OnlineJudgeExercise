#include <cstdio>
#include <algorithm>
#define HIGH node[i].H-node[j].H
using namespace std;
const int maxN=1e3+10;
const int INF=0x3f3f3f3f;
struct Node {
    int L, R, H;
    bool operator < (const Node &rhs) const {
        return H>rhs.H;
    } 
} node[maxN];
int t, n, mx, ans, dp[maxN][2];
bool flag;
int min(int x, int y) { return x<y?x:y; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &n, &node[0].L, &node[0].H, &mx);
        node[0].R=node[0].L;
        for (int i=1;i<=n;i++)
            scanf("%d%d%d", &node[i].L, &node[i].R, &node[i].H);
        sort(node, node+n+1);
        dp[0][0]=dp[0][1]=0, ans=INF;
        for (int i=1;i<=n;i++)
            dp[i][0]=dp[i][1]=INF;
        for (int i=0;i<=n;i++) {
            flag=true;
            // left side
            for (int j=i+1;j<=n && node[i].H-node[j].H<=mx;j++) {
                if (node[i].L>=node[j].L && node[i].L<=node[j].R) {
                    dp[j][0]=min(dp[j][0], dp[i][0]+HIGH+(node[i].L-node[j].L));
                    dp[j][1]=min(dp[j][1], dp[i][0]+HIGH+(node[j].R-node[i].L));
                    flag=false;
                    break;
                }
            }
            if (flag && node[i].H<=mx)
                ans=min(ans, dp[i][0]+node[i].H);
            flag=true;
            // right side
            for (int j=i+1;j<=n && node[i].H-node[j].H<=mx;j++) {
                if (node[i].R>=node[j].L && node[i].R<=node[j].R) {
                    dp[j][0]=min(dp[j][0], dp[i][1]+HIGH+(node[i].R-node[j].L));
                    dp[j][1]=min(dp[j][1], dp[i][1]+HIGH+(node[j].R-node[i].R));
                    flag=false;
                    break;
                }
            }
            if (flag && node[i].H<=mx)
                ans=min(ans, dp[i][1]+node[i].H);
        }
        printf("%d\n", ans);
    }
}