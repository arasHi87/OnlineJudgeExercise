#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e5+10;
const int INF=0x3f3f3f3f;
int t, n, m, qs[maxN];
inline int min(int a, int b) { return a<b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i=1;i<=n;i++)
            scanf("%d", qs+i);
        int ans=INF, sum=0, L=0, R=1;
        while (true) {
            while (sum<m && R<=n) sum+=qs[R++];
            if (sum<m) break;
            ans=min(ans, R-L);
            sum-=qs[L++];
        }
        if (ans==INF) puts("0");
        else printf("%d\n", ans);
    }
}