#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN=100+10;
const int INF=0x3f3f3f3f;
int n, k, ans;
int vis[maxN], dis[maxN], G[maxN][maxN];
int prim(int st) {
    for (int i=0;i<=n;i++)
        vis[i]=0, dis[i]=G[st][i];
    dis[st]=0, vis[st]=1, ans=0;
    for (int i=1;i<=n-1;i++) {
        int x, mn=INF;
        for (int j=1;j<=n;j++)
            if (!vis[j] && dis[j]<mn)
                mn=dis[x=j];
        vis[x]=1, ans+=dis[x];
        for (int j=1;j<=n;j++)
            if (!vis[j] && dis[j]>G[x][j])
                dis[j]=G[x][j];
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                scanf("%d", &k);
                G[i][j]=k;
            }
        }
        printf("%d\n", prim(1));
    }
}