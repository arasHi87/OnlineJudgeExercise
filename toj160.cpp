#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=110;
const int INF=0x3f3f3f3f;
int t, n, m, a, b, c, q;
int dis[maxN][maxN];
inline int min(int a, int b) { return a<b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        memset(dis, INF, sizeof dis);
        scanf("%d%d", &n, &m);
        for (int i=1;i<=n;i++)
            dis[i][i]=0;
        for (int i=1;i<=m;i++) {
            scanf("%d%d%d", &a, &b, &c);
            dis[a][b]=min(dis[a][b], c);
        }
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", dis[a][b]==INF ? -1 : dis[a][b]);
        }
    }
}