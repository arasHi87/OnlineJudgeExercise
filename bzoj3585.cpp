#include <bits/stdc++.h>
using namespace std;
const int maxN=1e3+10;
const int INF=0x3f3f3f3f;
struct Node {
    int x, y, w;
    Node() {}
    Node(int _x, int _y, int _w): x(_x), y(_y), w(_w) {}
};
int n, m, k, tx, ty, ans=INF;
int mp[maxN][maxN], val[maxN][maxN], vis[maxN][maxN];
int d[4][2]={1, 0, 0, 1, -1, 0, 0, -1};
char ch[maxN];
queue<Node> q;
inline int min(int a, int b) { return a<b?a:b; }
void bfs(int sx, int sy) {
    q.push(Node{sx, sy, 0});
    vis[sx][sy]=1;
    while (!q.empty()) {
        Node tmp=q.front(); q.pop();
        int x=tmp.x, y=tmp.y, w=tmp.w;
        for (int i=0;i<4;i++) {
            int nx=x+d[i][0], ny=y+d[i][1];
            if (vis[nx][ny] || !mp[nx][ny] || nx<1 || nx>n || ny<1 || ny>m) continue;
            vis[nx][ny]=1;
            if (mp[nx][ny]==2) ans=min(ans, w+val[nx][ny]+1);
            q.push(Node{nx, ny, w+1});
        }
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1;i<=n;i++) {
        scanf("%s", ch+1);
        for (int j=1;j<=m;j++)
            mp[i][j]=(ch[j]=='.');
    }
    for (int i=1, x, y, z;i<=k;i++) {
        scanf("%d%d%d", &x, &y, &z);
        mp[x][y]=2, val[x][y]=z;
    }
    scanf("%d%d", &tx, &ty), bfs(tx, ty);
    printf("%d\n", (ans==INF ? -1 : ans));
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=m;j++)
    //         printf("%d ", de[i][j]);
    //     puts("");
    // }
}