#include <iostream>
#include <memory.h>
#include <limits.h>
using namespace std;
typedef long long ll;
const int maxN=205;

ll max(ll a, ll b) {
    return a>b?a:b;
}

ll dp[maxN];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char s[maxN];
        scanf("%s", s);
        int n=strlen(s);
        memset(dp, 0, sizeof dp);
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=10 && j<=i;j++) {
                ll sum=0;
                for (int k=0;k<j;k++) {
                    sum=sum*10+s[i-j+k]-'0';
                    if (sum<=INT_MAX && sum>=0) dp[i]=max(dp[i], dp[i-j]+sum);
                    else break;
                }
            }
        }
        printf("%lld\n", dp[n]);
    }
}