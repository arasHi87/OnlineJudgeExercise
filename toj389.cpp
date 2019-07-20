#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN=1e5+10;

int low[maxN],
    dfn[maxN],
    val[maxN],
    arr[maxN],
    tot=0;
vector<int> G[maxN];

void dfs(int x) {
    low[x]=dfn[x]=++tot;
    val[x]=arr[x];
    for (auto it:G[x]) {
        if (!dfn[it]) {
            dfs(it);
            low[x]=min(low[x], low[it]);
            if (low[it]>=dfn[x]) val[x]+=val[it];
        } else low[x]=min(low[x], dfn[it]);
    }
}

int main() {
    int n, m, x, y, mx=-0x3f3f3f3f, ans;
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;i++)
        scanf("%d", arr+i);
    for (int i=1;i<=m;i++)
        scanf("%d%d", &x, &y),
        G[x].push_back(y), G[y].push_back(x);
    dfs(0);
    for (int i=1;i<=n;i++)
        if (val[i]>mx)  mx=val[i], ans=i;
    printf("%d\n", ans);
}
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #define CLR memset
// using namespace std;
// const int maxN=1e5+10;
// struct Edge {
//     int to, next;
// } edge[maxN*40];
// int n, m, a, b, ans=-1, cnt, idx, top, bcc, tmp=0;
// int low[maxN], dfn[maxN], val[maxN], num[maxN], head[maxN];
// inline void addedge(int u, int v) {
//     edge[cnt].to=v;
//     edge[cnt].next=head[u];
//     head[u]=cnt++;
// }
// void tarjan(int u) {
//     dfn[u]=low[u]=++idx;
//     num[u]=val[u];
//     for (int i=head[u];~i;i=edge[i].next) {
//         int v=edge[i].to;
//         if (!dfn[v]) {
//             tarjan(v);
//             low[u]=min(low[u], low[v]);
//             if (dfn[u]<=low[v]) num[u]+=num[v];
//         } else low[u]=min(low[u], dfn[v]);
//     }
// }
// int main() {
//     #ifdef local
//         freopen("in", "r", stdin);
//     #endif
//     CLR(head, -1, sizeof head);
//     cnt=top=bcc=idx=0;
//     scanf("%d%d", &n, &m);
//     for (int i=1;i<=n;i++)
//         scanf("%d", val+i);
//     while (m--) {
//         scanf("%d%d", &a, &b);
//         addedge(a, b);
//         addedge(b, a);
//     }
//     tarjan(0);
//     for (int i=1;i<=n;i++)
//         if (num[i]>tmp)
//             tmp=num[i], ans=i;
//     printf("%d\n", ans);
// }
