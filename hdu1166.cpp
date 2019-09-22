#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=5e4+10;
int t, n, a, b, bit[maxN];
char opt[5];
inline int lowbit(int x) { return x&(-x); }
inline void add(int pos, int x) {
    while (pos<=n) {
        bit[pos]+=x;
        pos+=lowbit(pos);
    }
}
inline int sum(int pos) {
    int res=0;
    while (pos) {
        res+=bit[pos];
        pos-=lowbit(pos);
    }
    return res;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    for (int kase=1;kase<=t;kase++) {
        printf("Case %d:\n", kase);
        memset(bit, 0, sizeof bit);
        scanf("%d", &n);
        for (int i=1;i<=n;i++) {
            scanf("%d", &a);
            add(i, a);
        }
        while(scanf("%s", opt) && opt[0]!='E') {
            scanf("%d%d", &a, &b);
            if (opt[0]=='Q') printf("%d\n", sum(b)-sum(a-1));
            else if (opt[0]=='A') add(a, b);
            else add(a, -b);
        }
    }
}