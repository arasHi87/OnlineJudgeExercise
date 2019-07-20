#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
#define DE printf("Hi! I am the fucking debugger!\n");
using namespace std;
const int maxN=1e3+10;
const int maxM=4e4+10;
const int INF=0x3f3f3f3f;
struct Edge {
    int u, v, w;
} E[maxM];
int t, n, m;
int in[maxN], id[maxN], vis[maxN], pre[maxN];
int dmst(int root) {
    int ret=0, u, v, w, NV=n, NE=m, cnt;
    while (1) {
        for (int i=0;i<NV;i++) in[i]=INF;
        for (int i=0;i<NE;i++) {
            u=E[i].u, v=E[i].v, w=E[i].w;
            if (u!=v && w<in[v])
                in[v]=w, pre[v]=u;
        }
        for (int i=0;i<NV;i++)
            if (i!=root && in[i]==INF)
                return -1;
        mem(vis, -1, sizeof vis);
        mem(id, -1, sizeof id);
        in[root]=0, cnt=0;
        for (int i=0;i<NV;i++) {
            ret+=in[i], v=i;
            while (vis[v]!=i && id[v]==-1 && v!=root) {
                vis[v]=i;
                v=pre[v];
            }
            if (v!=root && id[v]==-1) {
                for (u=pre[v];u!=v;u=pre[u]) {
                    id[u]=cnt;
                }
                id[v]=cnt++;
            }
        }
        if (cnt==0) break;
        for (int i=0;i<NV;i++)
            if (id[i]==-1)
                id[i]=cnt++;
        for (int i=0;i<NE;i++) {
            v=E[i].v;
            E[i].u=id[E[i].u];
            E[i].v=id[E[i].v];
            if (E[i].u!=E[i].v) {
                E[i].w-=in[v];
            }
        }
        NV=cnt;
        root=id[root];
    }
    return ret;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    for (int kase=1;kase<=t;kase++) {
        printf("Case #%d: ", kase);
        scanf("%d%d", &n, &m);
        for (int i=0;i<m;i++)
            scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
        int ans=dmst(0);
        if (ans==-1) printf("Possums!\n");
        else printf("%d\n", ans);
    }
}