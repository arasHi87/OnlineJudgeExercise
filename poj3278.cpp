#include <cstdio>
#include <queue>
#include <algorithm>
#define mp make_pair
#define ft first
#define sd second
using namespace std;
const int maxN=1e5+10;
typedef pair<int, int> pii;
int x, y, vis[maxN];
queue<pii> q;
void bfs() {
    q.push(mp(x, 0));
    while (!q.empty()) {
        int u=q.front().ft, t=q.front().sd; q.pop();
        if (u+1==y || u-1==y || u*2==y) {
            printf("%d\n", t+1);
            break;
        }
        if (u*2>0 && u*2<maxN && !vis[u*2]) q.push(mp(u*2, t+1)), vis[u*2]=1;
        if (u+1>0 && u+1<maxN && !vis[u+1]) q.push(mp(u+1, t+1)), vis[u+1]=1;
        if (u-1>0 && u-1<maxN && !vis[u-1]) q.push(mp(u-1, t+1)), vis[u-1]=1;
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d", &x, &y);
    if (x==y) printf("0\n");
    else bfs();
}