#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxN=25;

double dp[maxN][maxN][maxN];
int p[maxN][maxN][maxN], n;

void output(int u, int v, int t) {
    if (t>=1) output(u, p[u][v][t], t-1), printf(" %d", v);
    else printf("%d", u);
}

bool sol() {
    for (int s=2;s<=n;s++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                for (int k=1;k<=n;k++) {
                    if (dp[i][j][s]<dp[i][k][s-1]*dp[k][j][1]) {
                        dp[i][j][s]=dp[i][k][s-1]*dp[k][j][1];
                        p[i][j][s]=k;
                    }
                }
                if (dp[i][i][s]>1.01) {
                    output(i, i, s);
                    puts("");
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    while (~scanf("%d", &n)) {
        memset(dp, 0, sizeof dp);
        memset(p, 0, sizeof p);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (i==j) dp[i][j][1]=1.0;
                else scanf("%lf", &dp[i][j][1]);
        if (!sol()) printf("no arbitrage sequence exists\n");
    }
}