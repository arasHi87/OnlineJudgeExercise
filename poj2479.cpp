#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=5e4+10;
int t, n, L, R, ans, qs[maxN];
inline int max(int a, int b) { return a>b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n), L=R=ans=0;
        for (int i=1;i<=n;i++) scanf("%d", qs+i);
        for (int i=1;i<=n;i++)
            L<=0 ? L=qs[i] : L+=qs[i];
    }
}