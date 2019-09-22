 #include <cstdio>
#include <cstring>
using namespace std;
const int maxN=5e4+10;
struct Edge {
    int to, next;
} edge[maxN<<1];
struct Data {
    int in, out, val;
} dat[maxN];
int n, m, a, b, cnt, idx=1, ans;
int bit[maxN<<1], head[maxN];
char opt[5];
inline void addedge(int u, int v) {
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
inline int lowbit(int x) { return x&(-x); }
inline void add(int i, int x) {
    while (i<=n*2) {
        bit[i]+=x;
        i+=lowbit(i);
    }
}
inline int sum(int i) {
    int res=0;
    while (i) {
        res+=bit[i];
        i-=lowbit(i);
    }
    return res;
}
void dfs(int u, int p) {
    dat[u].in=idx++;
    for (int i=head[u];~i;i=edge[i].next) {
        int v=edge[i].to;
        if (v==p) continue;
        dfs(v, u);
    }
    dat[u].out=idx++;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    memset(head, -1, sizeof head);
    scanf("%d%d", &n, &m);
    for (int i=1;i<n;i++) {
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    dfs(1, -1);
    for (int i=1;i<=n;i++) {
        scanf("%d", &dat[i].val);
        add(dat[i].in, dat[i].val);
        add(dat[i].out, -dat[i].val);
    }
    while (m--) {
        scanf("%s", opt);
        if (opt[0]=='C') {
            scanf("%d%d", &a, &b);
            int tmp=b-dat[a].val;
            dat[a].val=b;
            add(dat[a].in, tmp);
            add(dat[a].out, -tmp);
        } else {
            scanf("%d", &a);
            ans+=sum(dat[a].in);
        }
    }
    printf("%d\n", ans);
}