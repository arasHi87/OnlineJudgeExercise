#include <cstdio>
#include <cstring>
#include <algorithm>
#define CLR memset
using namespace std;
const int maxN=100+10;
struct Edge {
    int to, next;
} edge[maxN*maxN];
int n, k, cnt, idx, top, scc, a1, a2;
int in[maxN], out[maxN], head[maxN], dfn[maxN], low[maxN], stk[maxN], blo[maxN], Istk[maxN];
inline void init() {
    idx=cnt=top=scc=a1=a2=0;
    CLR(in, 0, sizeof in);
    CLR(blo, 0, sizeof blo);
    CLR(out, 0, sizeof out);
    CLR(stk, 0, sizeof stk);
    CLR(low, 0, sizeof low);
    CLR(dfn, 0, sizeof dfn);
    CLR(head, -1, sizeof head);
    CLR(Istk, 0, sizeof Istk);
}
inline void addedge(int u, int p) {
    edge[cnt].to=p;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u) {
    int v;
    low[u]=dfn[u]=++idx;
    Istk[u]=1;
    stk[top++]=u;
    for (int i=head[u];~i;i=edge[i].next) {
        v=edge[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u], low[v]);
        } else if (Istk[v]) low[u]=min(low[u], dfn[v]);
    }
    if (low[u]==dfn[u]) {
        scc++;
        do {
            v=stk[--top];
            blo[v]=scc;
            Istk[v]=0;
        } while(v!=u);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        init();
        for (int i=1;i<=n;i++)
            while (~scanf("%d", &k) && k)
                addedge(i, k);
        for (int i=1;i<=n;i++)
            if(!dfn[i])
                tarjan(i);
        for (int i=1;i<=n;i++) {
            for (int j=head[i];~j;j=edge[j].next) {
                int v=edge[j].to;
                if (blo[i]!=blo[v]) {
                    out[blo[i]]++;
                    in[blo[v]]++;
                }
            }
        }
        for (int i=1;i<=scc;i++) {
            if (!in[i]) a1++;
            if (!out[i]) a2++;
        }
        if (scc==1) printf("1\n0\n");
        else printf("%d\n%d\n", a1, max(a1, a2));
    }
}