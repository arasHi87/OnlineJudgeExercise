#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxN=100+10;
const int INF=0x3f3f3f3f;
int t, n, cnt, vis[maxN];
double ans, G[maxN][maxN], dis[maxN], x[maxN], y[maxN];
int prim(int st) {
    for (int i=0;i<=n;i++)
        vis[i]=0, dis[i]=G[st][i];
    dis[st]=0, vis[st]=1, cnt=0, ans=0;
    for (int i=1;i<=n-1;i++) {
        int a=0; double mn=INF;
        for (int j=1;j<=n;j++)
            if (!vis[j] && dis[j]<mn)
                mn=dis[a=j];
        if (mn!=INF)
            vis[a]=1, ans+=dis[a]*100, cnt++;
        for (int j=1;j<=n;j++)
            if (!vis[j] && dis[j]>G[a][j])
                dis[j]=G[a][j];
    }
    for (int i=1;i<=n;i++)
        if(!vis[i])
            return 0;
    return 1;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                G[i][j]=INF;
        for (int i=1;i<=n;i++) {
            scanf("%lf%lf", x+i, y+i);
            for (int j=i-1;j>=1;j--) {
                double tmp=sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2));
                if (tmp>=10 && tmp<=1000)
                    G[i][j]=G[j][i]=tmp;
            }
        }
        if (prim(1)) printf("%.1lf\n", ans);
        else printf("oh!\n");
    }
}