#include <cstdio>
using namespace std;
const int maxN=1e5+10;
int t, n, qs[maxN], tmp[maxN], dp[maxN];
inline int max(int a, int b) { return a>b?a:b; }
inline int min(int a, int b) { return a<b?a:b; }
inline int manacher() {
    int mx=0, id=0, ans=0, idx=0;
    tmp[idx++]=-2, tmp[idx++]=-1;
    for (int i=1;i<=n;i++)
        tmp[idx++]=qs[i], tmp[idx++]=-1;
    for (int i=1;i<idx;i++) {
        dp[i]=(i<mx ? min(dp[(id<<1)-i], mx-i) : 1);
        while ((tmp[i-dp[i]]==tmp[i+dp[i]]) && tmp[i-dp[i]]<=tmp[i-dp[i]+2])
            dp[i]++;
        if (mx<i+dp[i]) mx=i+dp[i], id=i;
        ans=max(ans, dp[i]-1);
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=1;i<=n;i++)
            scanf("%d", qs+i);
        printf("%d\n", manacher());
    }
}