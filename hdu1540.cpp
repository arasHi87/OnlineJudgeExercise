#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int maxN=5e4+10;
struct segment {
    int ls, rs, ms;
    segment(): ls(0), rs(0), ms(0) {};
} seg[maxN<<2];
int n, m, x;
char opt[5];
inline void pull(int root, int L, int R) {
    int mid=(L+R)>>1;
    seg[root].ls=seg[root<<1].ls;
    seg[root].rs=seg[root<<1|1].rs;
    if (seg[root<<1].ls==mid-L+1) seg[root].ls+=seg[root<<1|1].ls;
    if (seg[root<<1|1].rs==R-mid) seg[root].rs+=seg[root<<1].rs;
    seg[root].ms=max(max(seg[root<<1].ms, seg[root<<1|1].ms), seg[root<<1].rs+seg[root<<1|1].ls);
}
void build(int root, int L, int R) {
    seg[root].ls=seg[root].rs=seg[root].ms=R-L+1;
    if (L==R) return;
    int mid=(L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
}
void modify(int root, int L, int R, int pos, int d) {
    if (L==R) {
        seg[root].ls=seg[root].rs=seg[root].ms=d;
        return;
    }
    int mid=(L+R)>>1;
    if (pos<=mid) modify(root<<1, L, mid, pos, d);
    else modify(root<<1|1, mid+1, R, pos, d);
    pull(root, L, R);
}
int query(int root, int L, int R, int pos) {
    if (L==R || seg[root].ms==R-L+1 || seg[root].ms==0) return seg[root].ms;
    int mid=(L+R)>>1;
    if (pos<=mid) {
        if (pos>=mid-seg[root<<1].rs+1) return seg[root<<1].rs+seg[root<<1|1].ls;
        else return query(root<<1, L, mid, pos);
    } else {
        if (pos<=mid+seg[root<<1|1].ls) return seg[root<<1].rs+seg[root<<1|1].ls;
        else return query(root<<1|1, mid+1, R, pos);
    }
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m)) {
        build(1, 1, n);
        stack<int> stk;
        while (m--) {
            scanf("%s", opt);
            if (opt[0]=='D') {
                scanf("%d", &x);
                stk.push(x);
                modify(1, 1, n, x, 0);
            } else if (opt[0]=='Q') {
                scanf("%d", &x);
                printf("%d\n", query(1, 1, n, x));
            } else if (!stk.empty()) {
                x=stk.top(); stk.pop();
                modify(1, 1, n, x, 1);
            }
        }
    }
}