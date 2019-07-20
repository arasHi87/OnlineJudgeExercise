#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxN=4e5+10;
const int MOD=998244353;

LL dp[105][105]={0};

int main() {
    int n ,m;
    for (int i=1;i<=100;i++)
        for (int j=1;j<=i;j++)
            if (i==j) dp[i][j]=1;
            else dp[i][j]=dp[i-1][j]*i/(i-j);
    while (scanf("%d%d", &n, &m)) {
        if (n==0 && m==0) return 0;
        printf("%d things taken %d at a time is %lld exactly.\n", n, m, dp[n][m]);
    }
}