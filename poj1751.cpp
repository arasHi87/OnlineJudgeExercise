#include <cstdio>
#include <cmath>
#include <algorithm>
#define mp make_pair
#define ft first
#define sd second
using namespace std;
const int maxN=750+10;
const int INF=0x3f3f3f3f;
typedef double db;
int n, x, y, m, vis[maxN], pth[maxN];
double G[maxN][maxN], dis[maxN];
pair<int, int> stk[maxN];
void prim(int st) {
    for (int i=1;i<=n;i++)
        vis[i]=0, dis[i]=G[st][i], pth[i]=st;
    dis[st]=0, vis[st]=1;
    for (int i=1;i<=n-1;i++) {
        int a;
        double mn=INF;
        for (int j=1;j<=n;j++)
            if (!vis[j] && dis[j]<mn)
                mn=dis[a=j];
        vis[a]=1;
        if (G[pth[a]][a]) printf("%d %d\n", pth[a], a);
        for (int j=1;j<=n;j++)
            if (!vis[j] && dis[j]>G[a][j])
                dis[j]=G[a][j], pth[j]=a;
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                G[i][j]=INF;
        for (int i=1;i<=n;i++) {
            scanf("%d%d", &x, &y);
            stk[i]=mp(x, y);
        }
        for (int i=1;i<=n;i++) {
            for (int j=i+1;j<=n;j++) {
                G[i][j]=G[j][i]=sqrt(pow((db)stk[i].ft-(db)stk[j].ft, 2)+pow((db)stk[i].sd-(db)stk[j].sd, 2));
            }
        }
        scanf("%d", &m);
        for (int i=1;i<=m;i++) {
            scanf("%d%d", &x, &y);
            G[x][y]=G[y][x]=0;
        }
        prim(1);
    }
}