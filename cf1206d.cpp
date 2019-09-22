#include <cstdio>
#include <cstring>
#define mem memset
using namespace std;
typedef long long LL;
const int maxN=120, maxM=1e5+10;
const LL INF=0x3f3f3f3f3f3f3f3f;
int n, idx;
LL ans=INF, x, G[maxN][maxN], dis[maxN][maxN], arr[maxM];
inline LL min(LL a, LL b) { return a<b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%lld", &x);
        if (x) arr[++idx]=x;
    }
    if (idx>maxN) return puts("3"), 0;
    mem(G, INF, sizeof INF);
    for (int i=1;i<=idx;i++)
        for (int j=i+1;j<=idx;j++)
            if (arr[i]&arr[j])
                G[i][j]=G[j][i]=1;
    for (int i=1;i<=idx;i++)
        for (int j=1;j<=idx;j++)
            dis[i][j]=G[i][j];
    for (int k=1;k<=idx;k++) {
        for (int i=1;i<k;i++)
            for (int j=i+1;j<k;j++)
                if (dis[i][j]!=INF && G[i][k]!=INF && G[j][k]!=INF)
                    ans=min(ans, dis[i][j]+G[i][k]+G[j][k]);
        for (int i=1;i<=idx;i++)
            for (int j=1;j<=idx;j++)
                if (dis[i][k]!=INF && dis[k][j]!=INF)
                    dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
    }
    if (ans==-1) puts("-1");
    else printf("%lld\n", ans);
}