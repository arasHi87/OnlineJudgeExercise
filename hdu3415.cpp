#include <cstdio>
#include <cstring>
#define mem memset
using namespace std;
const int maxN=2e5+10;
const int INF=0x3f3f3f3f;
int t, n, k;
int que[maxN], pre[maxN];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i=1;i<=n;i++)
            scanf("%d", pre+i), pre[i+n]=pre[i];
        for (int i=1;i<=n+k;i++)
            pre[i]+=pre[i-1];
        int L=0, R=-1, ans=-INF, ansL, ansR;
        for (int i=1;i<n+k;i++) {
            while (L<=R && que[L]<i-k) L++;
            while (L<=R && pre[que[R]]>=pre[i-1]) R--;
            que[++R]=i-1;
            if (pre[i]-pre[que[L]]>ans) {
                ans=pre[i]-pre[que[L]];
                ansL=que[L]+1, ansR=(i>n ? i%n : i);
            }
        }
        printf("%d %d %d\n", ans, ansL, ansR);
    }
}