#include <cstdio>
#include <cstring>
#include <algorithm>
#define CLR memset
using namespace std;
const int maxN=100+10;
const int INF=0x3f3f3f3f;
struct Edge {
    int u, v, w, vis;
    bool operator < (const Edge &rhs) const {
        return w<rhs.w;
    }
} edge[maxN*4];
struct Vertex {
    int to, next;
} G[maxN];
int t, n, m, a, b, c, cnt, mst, smst;
int root[maxN], head[maxN], tail[maxN], mx[maxN][maxN];
inline void init() {
    mst=cnt=0, smst=INF;
    CLR(mx, 0, sizeof mx);
    for (int i=1;i<=n;i++)
        root[i]=i, head[i]=tail[i]=-1;
}
int find(int x) {
    return (root[x]==x?x:root[x]=find(root[x]));
}
inline void unite(int x, int y) {
    G[tail[y]].next=head[x];
    head[x]=head[y];
    tail[y]=tail[x];
    root[y]=x;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    for (int kase=1;kase<=t;kase++) {
        printf("Case #%d : ", kase);
        scanf("%d%d", &n, &m); init();
        for (int i=1;i<=m;i++)
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w), edge[i].vis=0;
        sort(edge+1, edge+1+m);
        for (int i=1;i<=n;i++) {
            G[i].to=i;
            G[i].next=head[i];
            head[i]=tail[i]=i;
        }
        for (int i=1;i<=m && cnt<=n-1;i++) {
            a=find(edge[i].u), b=find(edge[i].v);
            if (a!=b) {
                for (int j=head[a];~j;j=G[j].next)
                    for (int k=head[b];~k;k=G[k].next)
                        mx[G[j].to][G[k].to]=mx[G[k].to][G[j].to]=edge[i].w;
                unite(a, b);
                mst+=edge[i].w, edge[i].vis=1, cnt++;
            }
        }
        if (cnt<n-1) printf("No way\n");
        else {
            for (int i=1;i<=m;i++)
                if (!edge[i].vis)
                    smst=min(smst, mst+edge[i].w-mx[edge[i].u][edge[i].v]);
            if (smst==INF) printf("No second way\n");
            else printf("%d\n", smst);
        }
    }
}