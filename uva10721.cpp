#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxN=55;
const int MOD=998244353;

LL dp[maxN][maxN];

int main() {
    int N, K, M;
    while (~scanf("%d%d%d", &N, &K, &M)) {
        memset(dp, 0, sizeof dp);
        for (int i=1;i<=M;i++) dp[1][i]=1;
        for (int i=2;i<=K;i++)
            for (int j=i;j<=N;j++)
                for (int k=1;k<j && k<=M;k++)
                    dp[i][j]+=dp[i-1][j-k];
        printf("%lld\n", dp[K][N]);
    }
}