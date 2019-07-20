#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
using namespace std;
const int maxN=1e3+10;
const int maxM=1e5+10;
const int INF=0x7f7f7f7f;
struct Edge {
    int u, v, w;
} E[maxM];
int pos;
int in[maxN], id[maxN], pre[maxN], vis[maxN];
int dmst(int root, int n, int m) {
    int ret=0, cnt=0, u, v, w;
    while (true) {
        for (int i=0;i<n;i++) in[i]=INF;
        for (int i=0;i<m;i++) {
            u=E[i].u, v=E[i].v, w=E[i].w;
            if (u!=v && w<in[v]) {
                in[v]=w, pre[v]=u;
                if (u==root) pos=i;
            }
        }
        for (int i=0;i<n;i++)
            if (i!=root && in[i]==INF)
                return -1;
        mem(vis, -1, sizeof vis);
        mem(id, -1, sizeof id);
        in[root]=0, cnt=0;
        for (int i=0;i<n;i++) {
            ret+=in[i], v=i;
            while (vis[v]!=i && id[v]==-1 && v!=root) {
                vis[v]=i;
                v=pre[v];
            }
            if (id[v]==-1 && v!=root) {
                for (u=pre[v];u!=v;u=pre[u]) {
                    id[u]=cnt;
                }
                id[v]=cnt++;
            }
        }
        if (cnt==0) break;
        for (int i=0;i<n;i++)
            if (id[i]==-1)
                id[i]=cnt++;
        for (int i=0;i<m;i++) {
            v=E[i].v;
            E[i].v=id[E[i].v];
            E[i].u=id[E[i].u];
            if (E[i].v!=E[i].u)
                E[i].w-=in[v];
        }
        n=cnt;
        root=id[root];
    }
    return ret;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        int sum=0;
        for (int i=0;i<m;i++)
            scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w),
            E[i].u+=1, E[i].v+=1, sum+=E[i].w;
        sum+=1, pos=0;
        for (int i=0;i<n;i++)
            E[m+i].u=0, E[m+i].v=i+1, E[m+i].w=sum;
        int ans=dmst(0, n+1, n+m);
        if (ans==-1 || ans>=sum<<1) printf("impossible\n");
        else printf("%d %d\n", ans-sum, pos-m);
        puts("");
    }
}