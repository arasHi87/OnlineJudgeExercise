#include <cstdio>
#define int long long
using namespace std;
const int maxN=1e5+10;
int n, k, wei[maxN], stk[maxN]={-1};
inline int max(int a, int b) { return a>b?a:b; }
signed main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%lld", &n) && n) {
        int top=0, ans=0;
        for (int i=1;i<=n+1;i++) {
            i==n+1 ? k=0 : scanf("%lld", &k);
            if (k>stk[top]) stk[++top]=k, wei[top]=1;
            else {
                int cnt=0;
                while (k<=stk[top])  {
                    ans=max(ans, (cnt+wei[top])*stk[top]);
                    cnt+=wei[top--];
                }
                stk[++top]=k, wei[top]=cnt+1;
            }
        }
        printf("%lld\n", ans);
    }
}