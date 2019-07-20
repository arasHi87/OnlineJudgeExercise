#include <iostream>
#include <cstring>
#include <queue>
#define CLR memset
using namespace std;
const int maxN=200+10;
struct Node {
    int x, y, v;
    Node(int a, int b, int c): x(a), y(b), v(c) {};
};
int n, m, ax, ay, bx, by, mn, xy[maxN][maxN];
int mp[maxN][maxN], vis[maxN][maxN], ans[maxN][maxN];
int d[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char opt;
queue<Node> q;
void bfs(int sx, int sy) {
    CLR(vis, 0, sizeof vis);
    while (!q.empty()) q.pop();
    q.push(Node(sx, sy, 0));
    vis[sx][sy]=1;
    // printf("%d %d %d\n", q.front().x, q.front().y, q.front().v);
    while (!q.empty()) {
        Node tmp=q.front(); q.pop();
        int nx=tmp.x, ny=tmp.y, nv=tmp.v+1;
        for (int i=0;i<4;i++) {
            printf("%d %d\n", nx, ny);
            nx+=d[i][0], ny+=d[i][1];
            if (nx<0 || ny<0 || nx>n || ny>m || vis[nx][ny] || !mp[nx][ny]) continue;
            vis[nx][ny]=1;
            // printf("(%d %d) %d\n", nx, ny, nv);
            if (xy[nx][ny]) ans[nx][ny]+=nv;
            q.push(Node(nx, ny, nv));
        }
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (cin>>n>>m) {
        CLR(xy, 0, sizeof xy);
        CLR(mp, 0, sizeof mp);
        CLR(ans, 0, sizeof ans);
        mn=0x3f3f3f3f;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cin>>opt;
                if (opt=='Y') ax=i, ay=j, mp[ax][ay]=1;
                else if (opt=='M') bx=i, by=j, mp[bx][by]=1;
                else if (opt=='@') xy[i][j]=1, mp[i][j]=1;
                else if (opt=='.') mp[i][j]=1;
            }
        }
        bfs(ax, ay);
        cout<<"-----"<<endl;
        bfs(bx, by);
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (!ans[i][j]) continue;
                mn=min(ans[i][j], mn);
            }
        }
        cout<<mn<<'\n';
    }
}