// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #define mem memset
// using namespace std;
// const int maxN=1e4+10;
// struct Edge {
//     int to, next;
// } edge[maxN<<1];
// int t, n, a, b, cnt, root;
// int in[maxN], dep[maxN], head[maxN], fa[maxN][30];
// inline void addedge(int u, int v) {
//     edge[cnt].to=v;
//     edge[cnt].next=head[u];
//     head[u]=cnt++;
// }
// void dfs(int u, int p) {
//     for (int i=head[u];~i;i=edge[i].next) {
//         int v=edge[i].to;
//         if (v==p) continue;
//         if (!dep[v])
//             dep[v]=dep[u]+1, fa[v][0]=u, dfs(v, u);
//     }
// }
// inline void init() {
//     for (int j=1;(1<<j)<=n;j++)
//         for (int i=1;i<=n;i++)
//             fa[i][j]=fa[fa[i][j-1]][j-1];
// }
// int LCA(int u, int v) {
//     if (dep[v]<dep[u]) swap(u, v);
//     int d=dep[v]-dep[u];
//     for (int i=0;(d>>i)!=0;i++)
//         if ((d>>i)&1) v=fa[v][i];
//     if (v==u) return v;
//     for (int i=20;i>=0;i--)
//         if (fa[u][i]!=fa[v][i])
//             u=fa[u][i], v=fa[v][i];
//     return fa[v][0];
// }
// int main() {
//     #ifdef local
//         freopen("in", "r", stdin);
//     #endif
//     scanf("%d", &t);
//     while (t--) {
//         scanf("%d", &n), cnt=0;
//         memset(head, -1, sizeof head);
//         memset(dep, 0, sizeof dep);
//         memset(in, 0, sizeof in);
//         for (int i=1;i<n;i++) {
//             scanf("%d%d", &a, &b);
//             addedge(a, b), in[b]++;
//         }
//         for (int i=1;i<n;i++)
//             if (!in[i]) root=i;
//         dep[root]=1, dfs(root, -1), init();
//         scanf("%d%d", &a, &b);
//         printf("%d\n", LCA(a, b));
//     }
// }
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem memset
using namespace std;
const int maxN=1e4+10;
struct Edge {
    int to, next, val;
} edge[maxN<<1];
int t, n, a, b, cnt, root;
int in[maxN], dep[maxN], head[maxN], fa[maxN][25];
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u, int p) {
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (v==p) continue;
        if (!dep[v]) {
            dep[v]=dep[u]+1;
            fa[v][0]=u, dfs(v, u);
        }
    }
}
inline void init() {
    for (int j=1;(1<<j)<=n;j++)
        for (int i=1;i<=n;i++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
}
inline int lca(int u, int v) {
    if (dep[u]>dep[v]) swap(u, v);
    int d=dep[v]-dep[u];
    for (int i=0;d>>i;i++)
        if ((d>>i)&1) v=fa[v][i];
    if (u==v) return v;
    for (int i=20;i>=0;i--)
        if (fa[u][i]!=fa[v][i])
            u=fa[u][i], v=fa[v][i];
    return fa[v][0];
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        mem(in, 0, sizeof in);
        mem(dep, 0, sizeof dep);
        mem(head, -1, sizeof head);
        scanf("%d", &n), cnt=0;
        for (int i=1;i<n;i++) {
            scanf("%d%d", &a, &b);
            addedge(a, b), in[b]++;
        }
        for (int i=1;i<n;i++)
            if (!in[i]) root=i;
        dep[root]=1, dfs(root, 0), init();
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
}