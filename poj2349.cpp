#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define ft first
#define sd second
#define mp make_pair
using namespace std;
const int maxN=5e2+10;
const int INF=0x3f3f3f3f;
typedef double db;
int t, s, p, x, y, vis[maxN];
db ans[maxN], dis[maxN], G[maxN][maxN];
vector<pair<int, int>> v;
db prim(int st) {
    for (int i=0;i<=p;i++)
        vis[i]=0, dis[i]=G[st][i], ans[i]=0;
    vis[st]=1, dis[st]=0;
    for (int i=1;i<=p-1;i++) {
        int a; db mn=INF;
        for (int j=1;j<=p;j++)
            if (!vis[j] && dis[j]<mn)
                mn=dis[a=j];
        vis[a]=1, ans[i]=dis[a];
        for (int j=1;j<=p;j++)
            dis[j]=min(dis[j], G[a][j]);
    }
    sort(ans+1, ans+p);
    return ans[p-s];
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &s, &p);
        for (int i=1;i<=p;i++)
            for (int j=1;j<=p;j++)
                G[i][j]=INF;
        v.clear();
        for (int i=1;i<=p;i++) {
            scanf("%d%d", &x, &y);
            v.push_back(mp(x, y));
        }
        for (int i=0;i<(int)v.size();i++) {
            for (int j=i+1;j<(int)v.size();j++) {
                G[i+1][j+1]=G[j+1][i+1]=sqrt(pow((db)v[i].ft-(db)v[j].ft, 2)+pow((db)v[i].sd-(db)v[j].sd, 2));
            }
        }
        printf("%0.2f\n", prim(1));
    }
}