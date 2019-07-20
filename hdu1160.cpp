#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN=1e3+10;
const int INF=0x3f3f3f3f;
struct Node {
    int f, s, idx;
} qs[maxN];
int idx=1, len=0, pos;
int dp[maxN], re[maxN], pre[maxN];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &qs[idx].f, &qs[idx].s))
        qs[idx].idx=idx, idx++;
    sort(qs+1, qs+idx, [](Node lhs, Node rhs) {
        if (lhs.f==rhs.f) return lhs.s>rhs.s;
        return lhs.f<rhs.f;
    });
    for (int i=1;i<idx;i++) dp[i]=1;
    for (int i=1;i<idx;i++)
        for (int j=1;j<i;j++)
            if (qs[i].f>qs[j].f && qs[i].s<qs[j].s && dp[i]<dp[j]+1) {
                dp[i]=dp[j]+1, pre[i]=j;
                if (len<dp[i])
                    len=dp[i], pos=i;
            }
    printf("%d\n", len), idx=0;
    while (pos) {
        re[++idx]=pos;
        pos=pre[pos];
    }
    while(idx)
        printf("%d\n", qs[re[idx--]].idx);
}