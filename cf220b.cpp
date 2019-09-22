#include <bits/stdc++.h>
using namespace std;
const int maxN=1e5+10;
int BLOCK_SIZE;
void Dbg() { puts(""); }
template<typename T, typename ...Args> void Dbg(T x, Args ...args) {
    cout<<x<<' ';
    Dbg(args...);
}
template<typename T> inline void readInt(T &x) {
    char c=getchar(); x=0;
    while (!isdigit(c)) c=getchar();
    while (isdigit(c)) x=x*10+c-'0', c=getchar();
}
template<typename T, typename ...Args>
inline void readInt(T &x, Args &...args) { readInt(x), readInt(args...); }
struct Query {
    int L, R, id, bk;
    Query() {};
    Query(int _L, int _R, int _id): L(_L), R(_R), id(_id) {
        bk=L/BLOCK_SIZE;
    }
    bool operator < (Query const &rhs) const {
        return L==rhs.L ? R<rhs.R : L<rhs.L;
    }
} Q[maxN];
int n, m, tmp;
int qs[maxN], xs[maxN], num[maxN], ori[maxN], ans[maxN];
inline void revise(int x, int d) {
    if (num[qs[x]]==ori[x]) tmp--;
    num[qs[x]]+=d;
    if (num[qs[x]]==ori[x]) tmp++;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    readInt(n, m), BLOCK_SIZE=sqrt(n);
    for (int i=1;i<=n;i++)
        readInt(qs[i]), ori[i]=xs[i]=qs[i];
    sort(xs+1, xs+1+n);
    unique(xs+1, xs+1+n);
    for (int i=1;i<=n;i++)
        qs[i]=lower_bound(xs+1, xs+1+n, qs[i])-xs+1;
    for (int i=1, a, b;i<=m;i++) {
        readInt(a, b);
        Q[i]=Query(a, b, i);
    }
    // for (int i=1;i<=m;i++)
    //     printf("%d %d %d\n", Q[i].L, Q[i].R, Q[i].id);
    sort(Q+1, Q+1+m);
    for (int i=1, L=1, R=0;i<=m;i++) {
        Query &q=Q[i];
        while (L<q.L) revise(L++, -1);
        while (L>q.L) revise(--L,  1);
        while (R<q.R) revise(++R,  1);
        while (R>q.R) revise(R--, -1);
        ans[q.id]=tmp;
    }
    for (int i=1;i<=m;i++)
        printf("%d\n", ans[i]);
}