#include <bits/stdc++.h>
#define find(x) (x/sqn)
using namespace std;
typedef long long LL;
const int maxN=5e4+10;
template <typename tp> inline void read(tp &x) {
    char c=getchar();
    x=0;
    while (!isdigit(c)) c=getchar();
    while (isdigit(c))  x=x*10+c-'0', c=getchar();
}
struct Node {
    LL L, R, idx, blk;
    bool operator < (const Node &rhs) const {
        return blk==rhs.blk ? R<rhs.R : L<rhs.L;
    }
} q[maxN];
LL n, m, sqn, len, tmp;
LL qs[maxN], col[maxN], ans[maxN][2];
inline LL __gcd(LL a, LL b) { while ((a%=b)&&(b%=a)); return a+b; }
inline void add(LL x) { tmp-=col[x]*col[x], col[x]++, tmp+=col[x]*col[x]; }
inline void del(LL x) { tmp-=col[x]*col[x], col[x]--, tmp+=col[x]*col[x]; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    read(n), read(m), sqn=sqrt(n);
    for (LL i=1;i<=n;i++) read(qs[i]);
    for (LL i=1, a, b;i<=m;i++)
        read(a), read(b), q[i]=Node{a, b, i, find(a)};
    sort(q+1, q+1+m);
    for (LL i=1, L=1, R=0;i<=m;i++) {
        while (R<q[i].R) add(qs[++R]);
        while (R>q[i].R) del(qs[R--]);
        while (L<q[i].L) del(qs[L++]);
        while (L>q[i].L) add(qs[--L]);
        LL mol=tmp-(q[i].R-q[i].L+1);
        LL den=(q[i].R-q[i].L+1)*((q[i].R-q[i].L));
        LL gcd=__gcd(mol, den);
        ans[q[i].idx][0]=mol/gcd, ans[q[i].idx][1]=den/gcd;
    }
    for (int i=1;i<=m;i++)
        printf("%lld/%lld\n", ans[i][0], ans[i][1]);
}