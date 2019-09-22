#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=5e3+10;
int n, m, A, B, C, dp[maxN][maxN];
char s1[maxN], s2[maxN];
inline int min(int a, int b) { return a<b?a:b; }
inline int abs(int a) { return a>0?a:-a; }
inline int roll(char a, char b) { return min(abs(a-b), 26-abs(a-b)); }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d%d%s%s", &A, &B, &C, s1, s2);
    n=strlen(s1), m=strlen(s2);
    for (int i=0;i<=n;i++) dp[i][0]=i*B;
    for (int i=0;i<=m;i++) dp[0][i]=i*A;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            dp[i][j]=min(dp[i][j-1]+A, min(dp[i-1][j]+B, C*roll(s1[i-1], s2[j-1])+dp[i-1][j-1]));
    printf("%d\n", dp[n][m]);
}
