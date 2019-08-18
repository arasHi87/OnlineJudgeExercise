#include <cstdio>
#include <cassert>
#include <algorithm>
#define ass assert
using namespace std;
const int maxN=1e5+10;
const int INF=0x3f3f3f3f;
int n, ans=INF, qs[maxN];
inline int min(int a, int b) { return a<b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
        scanf("%d", qs+i);
    sort(qs+1, qs+1+n);
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            for (int k=j+1;k<=n;k++) {
                if (qs[i]+qs[j]>qs[k]) {
                    ans=min(ans, qs[i]+qs[j]+qs[k]);
                    if (n>100) return printf("%d\n", ans), 0;
                }
            }
        }
    }
    printf("%d\n", ans);
}