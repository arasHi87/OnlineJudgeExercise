#include <bits/stdc++.h>
using namespace std;
struct Node {
    // 綠0 白1 黑2 紅3 藍4
    int x, y, col, val, dir;
    bool operator < (const Node &rhs) const {
        return val>rhs.val;
    }
};
int n, m, sx, sy, tx, ty, idx=1;
int vis[30][30][5][5], mp[30][30];
int d[4][2]={-1, 0, 0, 1, 1, 0, 0, -1}; // 上0 右1 下2 左3
char ch[30];
priority_queue<Node> pq;
void bfs() {
    while (!pq.empty()) pq.pop();
    pq.push({sx, sy, 0, 0, 0});
    vis[sx][sy][0][0]=1;
    while (!pq.empty()) {
        Node q=pq.top(), tmp; pq.pop();
        int nx=q.x, ny=q.y, col=q.col, val=q.val, dir=q.dir;
        for (int i=0;i<4;i++) {
            int dx=nx+d[i][0], dy=ny+d[i][1];
            if (dx<1 || dx>n || dy<1 || dy>m || !mp[dx][dy]) continue;
            if (dir==i) tmp.x=dx, tmp.y=dy, tmp.col=(col+1)%5, tmp.val=val+1, tmp.dir=i;
            else {
                tmp.x=nx, tmp.y=ny, tmp.col=col, tmp.dir=i;
                tmp.val=val+(abs(dir-i)==2 ? 2 : 1);
            }
            if (!vis[tmp.x][tmp.y][tmp.dir][tmp.col]) {
                if (tmp.x==tx && tmp.y==ty && !tmp.col) {
                    printf("minimum time = %d sec\n", tmp.val);
                    return;
                }
                pq.push(tmp);
                vis[tmp.x][tmp.y][tmp.dir][tmp.col]=1;
            }
        }
    }
    printf("destination not reachable\n");
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && (n+m)) {
        if (idx!=1) puts("");
        printf("Case #%d\n", idx++);
        memset(vis, 0, sizeof vis);
        for (int i=1;i<=n;i++) {
            scanf("%s", ch+1);
            for (int j=1;j<=m;j++) {
                if (ch[j]=='S') sx=i, sy=j;
                if (ch[j]=='T') tx=i, ty=j;
                mp[i][j]=ch[j]!='#';
            }
        }
        bfs();
    }
}