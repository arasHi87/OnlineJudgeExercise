#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;
const int maxN=100+10;
struct Edge {
    int to, next;
} edge[maxN*maxN];
int n, k, cnt, ans, tcnt, vis[maxN], head[maxN];
string line;
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u) {
    vis[u]=1;
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (!vis[v]) dfs(v);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        memset(vis, 0, sizeof vis);
        memset(head, -1, sizeof head);
        cnt=ans=tcnt=0;
        while (getline(cin, line) && line[0]!='0') {
            stringstream ss(line); int idx=0, u;
            while (ss>>k) {
                if (!idx) u=k, idx++;
                else {
                    addedge(u, k);
                    addedge(k, u);
                }
            }
        }
        for (int i=1;i<=n;i++) {
            memset(vis, 0, sizeof vis);
            vis[i]=1, tcnt=0;
            for (int j=1;j<=n;j++) {
                if (!vis[j]) {
                    tcnt++, dfs(j);
                }
            }
            if (tcnt>1) ans++;
        }
        printf("%d\n", ans);
    }
}