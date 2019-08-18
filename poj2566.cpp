#include <cstdio>
#include <cstring>
#include <algorithm>
#define DE(x, y, z, w) printf("DE: %d %d %d %d\n", x, y, z, w);
using namespace std;
const int maxN=1e5+10;
const int INF=0x3f3f3f3f;
struct Node {
    int idx, sum;
    bool operator < (const Node &rhs) const {
        return sum<rhs.sum;
    }
} P[maxN];
int n, m, x, qs[maxN];
int max(int a, int b) { return a>b?a:b; }
int min(int a, int b) { return a<b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && (n+m)) {
        P[0].sum=P[0].idx=0;
        for (int i=1;i<=n;i++)
            scanf("%d", &P[i].sum), P[i].sum+=P[i-1].sum, P[i].idx=i;
        sort(P, P+n+1);
        while (m--) {
            scanf("%d", &x);
            int L=0, R=1, ans=INF, ansL, ansR, tmp=INF;
            while (R<=n && L<=n) {
                int num=abs(P[R].sum-P[L].sum);
                if (abs(num-x)<tmp)
                    tmp=abs(num-x), ans=num, ansL=P[L].idx, ansR=P[R].idx;
                if (num<x) R++;
                else if (num>x) L++;
                else break;
                if (L==R) R++;
            }
            if (ansL>ansR) swap(ansL, ansR);
            printf("%d %d %d\n", ans, ansL+1, ansR);
        }
    }
}