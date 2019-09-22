#include <bits/stdc++.h>
using namespace std;
const int maxN=1e5+10;
struct segment {
    int tg, ptg;
    int mx, pmx;
} seg[maxN<<2];
struct Query {
    int L, R, id;
    bool operator < (const Query &rhs) const { return L<rhs.L; }
} Q[maxN];
int n, m, qs[maxN], last[maxN];
inline int max(int a, int b) { return a>b?a:b; }
inline void push_up(int rt) {
    seg[rt].mx=max(seg[rt<<1].mx, seg[rt<<1|1].mx);
    seg[rt].pmx=max(seg[rt<<1].pmx, seg[rt<<1|1].pmx);
}
inline void push_down(int rt) {
    if (seg[rt].tg || seg[rt].ptg) {
        seg[rt<<1].ptg=max(seg[rt<<1].ptg, seg[rt<<1].ptg+seg[rt<<1].tg);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", qs+i);
    scanf("%d", &m);
    for (int i=1;i<=m;i++)
        scanf("%d%d", Q[i].L, Q[i].R), Q[i].id=i;
}