#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
const int maxN=1e3+10;

struct node {
    int state;
    int x, y;
};

int dx[]={1, -1, 0, 0}, dy[]={0, 0, 1, -1};
int sx, sy;
int r, c;
int mp[maxN][maxN];
int vis[maxN][maxN][1<<4];
bool f=false;

inline void read() {
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            cin>>mp[i][j];
            if (mp[i][j]=='*') sx=i, sy=j;
        }
    }
}

void bfs() {
    node e;
    memset(vis, -1, sizeof vis);
    queue<node> q;
    e.x=sx, e.y=sy, e.state=0; q.push(e);
    while (!q.empty()) {
        e=q.front(); q.pop();
        int nx=e.x, ny=e.y, nstate=e.state; 
    }
}

int main() {
    cin>>r>>c;
    cin.get(); read();  bfs();
}