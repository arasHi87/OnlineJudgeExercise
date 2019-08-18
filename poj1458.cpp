#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
const int maxN=1e3+10;
string s1, s2;
char c1[maxN], c2[maxN];
int dp[maxN][maxN];
int max(int a, int b) { return a>b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%s%s", c1, c2)) {
        int n=strlen(c1), m=strlen(c2), k=max(n, m), ans=-1;
        s1=' '+string(c1), s2=' '+string(c2);
        for (int i=0;i<=k;i++) dp[k][0]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) {
                if (s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                ans=max(ans, dp[i][j]);
            }
        printf("%d\n", ans);
    }
}