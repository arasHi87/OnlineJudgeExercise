#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=2e6+10;
int BLOCK_SIZE;
void Dbg() { puts(""); }
template<typename T, typename ...Args> void Dbg(T x, Args ...args) {
    printf("%d ", x);
    Dbg(args...);
}
template<typename T> inline void readI(T &x) {
    char c=getchar(); x=0;
    while (!isdigit(c)) c=getchar();
    while (isdigit(c)) x=x*10+c-'0', c=getchar();
}
template<typename T> inline void readC(T &x) {
    char c=getchar();
    while (c=='\n' || c==' ') c=getchar();
    x=c;
}
struct Query {
    int L, R, id, tm, bl, br;
    Query() {}
    Query(int _L, int _R, int _id, int _tm): L(_L), R(_R), id(_id), tm(_tm) {
        bl=L/BLOCK_SIZE;
        br=R/BLOCK_SIZE;
    }
    bool operator < (Query const &rhs) const {
        return bl==rhs.bl ? (br==rhs.br ? tm<rhs.tm : br<rhs.br) : bl<rhs.bl;
    }
} Q[maxN];
struct Node {
    int pos, pre, now;
} T[maxN];
int n, m, tmp, Qidx, Tidx;
int qs[maxN], now[maxN], num[maxN], ans[maxN];
char op;
inline void revise(int x, int d) { 
    num[x]+=d;
    if (d>0) tmp+=(num[x]==1);
    if (d<0) tmp-=(num[x]==0);
}
inline void update(int x, int d, int L, int R) {
    if (L<=x && x<=R) revise(d, 1), revise(qs[x], -1);
    qs[x]=d;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    readI(n), readI(m), BLOCK_SIZE=sqrt(n);
    for (int i=1;i<=n;i++) readI(qs[i]), now[i]=qs[i];
    for (int i=1, a, b;i<=m;i++) {
        readC(op), readI(a), readI(b);
        if (op=='Q') Q[++Qidx]=Query(a, b, Qidx, Tidx);
        if (op=='R') T[++Tidx]={a, now[a], b}, now[a]=b;
    }
    sort(Q+1, Q+1+Qidx);
    // for (int i=1;i<=Qidx;i++)
    //     Dbg(Q[i].L, Q[i].R, Q[i].id, Q[i].tm);
    for (int i=1, L=1, R=0, X=0;i<=Qidx;i++) {
        Query &q=Q[i];
        while (X<q.tm) update(T[X+1].pos, T[X+1].now, L, R), X++;
        while (X>q.tm) update(T[X].pos, T[X].pre, L, R), X--;
        while (L<q.L) revise(qs[L++], -1);
        while (L>q.L) revise(qs[--L],  1);
        while (R<q.R) revise(qs[++R],  1);
        while (R>q.R) revise(qs[R--], -1);
        ans[q.id]=tmp;
    }
    for (int i=1;i<=Qidx;i++)
        printf("%d\n", ans[i]);
}