#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
using namespace std;
typedef double db;
const int maxN=100+10;
const int maxM=1e4+10;
const db INF=0x3f3f3f3f;
struct Node {
    db x, y;
} node[maxN];
int n, m, a, b, vis[maxN], pre[maxN], flag[maxN];
db ans, w[maxN][maxN];
inline void init() {
    mem(vis, 0, sizeof vis);
    mem(flag, 0, sizeof flag);
    fill(w[0], w[0]+maxN*maxN, INF);
    ans=0;
}
db dmst(int u) {
    while (true) {
        for (int i=1;i<=n;i++) {
            if (i!=u && !flag[i]) {
                w[i][i]=INF, pre[i]=i;
                for (int j=1;j<=n;j++)
                    if (!flag[j] && w[j][i]<w[pre[i]][i])
                        pre[i]=j;
                if (pre[i]==i) return -1;
            }
        }
        int i;
        for (i=1;i<=n;i++) {
            if (i!=u && !flag[i]) {
                int j=i, cnt=0;
                while (j!=u && pre[j]!=i && cnt<=n)
                    j=pre[j], cnt++;
                if (j==u || cnt>n) continue;
                break;
            }
        }
        if (i>n) {
            for (int i=1;i<=n;i++)
                if (i!=u && !flag[i])
                    ans+=w[pre[i]][i];
            return ans;
        }
        int j=i; mem(vis, 0, sizeof vis);
        do {
            ans+=w[pre[j]][j], j=pre[j], vis[j]=flag[j]=1;
        } while (j!=i);
        flag[i]=0;
        for (int k=1;k<=n;k++) if (vis[k]) {
            for (int j=1;j<=n;j++) if (!vis[j]) {
                if (w[i][j]>w[k][j]) w[i][j]=w[k][j];
                if (w[j][k]<INF && w[j][i]>w[j][k]-w[pre[k]][k])
                    w[j][i]=w[j][k]-w[pre[k]][k];
            }
        }
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m)) {
        init();
        for (int i=1;i<=n;i++)
            scanf("%lf%lf", &node[i].x, &node[i].y);
        for (int i=1;i<=m;i++) {
            scanf("%d%d", &a, &b);
            w[a][b]=sqrt(pow(node[a].x-node[b].x, 2)+pow(node[a].y-node[b].y, 2));
        }
        if (dmst(1)==-1) printf("poor snoopy\n");
        else printf("%.2f\n", ans);
    }
}