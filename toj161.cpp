#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e7+10;
const int INF=0x3f3f3f3f;
int t, n, m;
int qs[maxN];
int F(int x) {
    if (qs[x]!=INF) return qs[x];
    return (qs[x]=((F(x/2)+F(x/3)+F(x/4))*F(x/5))%m); 
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        memset(qs, INF, sizeof qs);
        scanf("%d%d%d%d", qs, qs+1, &m, &n);
        printf("%d\n", F(n));
    }
}