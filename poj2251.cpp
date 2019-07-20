#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxN=35;
struct Node {
    int x, y, z, w;
    // Node(): x(0), y(0), z(0) {};
    Node(int a, int b, int c, int d): x(a), y(b), z(c), w(d) {};
};
int L, R, C, sx, sy, sz, ex, ey, ez, ans;
int mp[maxN][maxN][maxN];
int vis[maxN][maxN][maxN];
int d[8][3]={{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
char opt;
queue<Node> q;
int bfs() {
    while(!q.empty()) q.pop();
    q.push(Node(sx, sy, sz, 0));
    vis[sx][sy][sz]=1;
    while (!q.empty()) {
        Node pt=q.front(); q.pop();
        for (int i=0;i<8;i++) {
            int x=pt.x+d[i][0], y=pt.y+d[i][1], z=pt.z+d[i][2], w=pt.w+1;
            if (x<1 || y<1 || z<1 || x>L || y>R || z>C || vis[x][y][z] || !mp[x][y][z]) continue;
            if (x==ex && y==ey && z==ez) return w;
            vis[x][y][z]=1;
            q.push(Node(x, y, z, w));
        }
    }
    return -1;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (cin>>L>>R>>C && L && R && C) {
        memset(mp, 0, sizeof mp);
        memset(vis, 0, sizeof vis);
        for (int i=1;i<=L;i++) {
            for (int j=1;j<=R;j++) {
                for (int k=1;k<=C;k++) {
                    cin>>opt;
                    if (opt=='S') sx=i, sy=j, sz=k, mp[i][j][k]=1;
                    else if (opt=='E') ex=i, ey=j, ez=k, mp[i][j][k]=1;
                    else mp[i][j][k]=(opt=='#'?0:1);
                }
            }
        }
        // printf("%d %d %d\n", sx, sy, sz);
        // printf("%d %d %d\n", ex, ey, ez);
        ans=bfs();
        if (ans==-1) cout<<"Trapped!"<<'\n';
        else cout<<"Escaped in "<<ans<<" minute(s)."<<'\n';
    }
}