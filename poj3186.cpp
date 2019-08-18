#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=2e3+10;
int n, ans=0, qs[maxN], dp[maxN][maxN];
int max(int a, int b) { return a>b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
        scanf("%d", qs+i);
    for (int i=0;i<=n;i++) {
        for (int j=0;j+i<=n;j++) {
            if (i==0 && j==0) dp[i][j]=0;
            else if (j==0) dp[i][j]=dp[i-1][j]+qs[i]*(i+j);
            else if (i==0) dp[i][j]=dp[i][j-1]+qs[n-j+1]*(i+j);
            else dp[i][j]=max(dp[i-1][j]+qs[i]*(i+j), dp[i][j]=dp[i][j-1]+qs[n-j+1]*(i+j));
            ans=max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
}

// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int maxN=2e3+10;
// int n, ans=0, qs[maxN], dp[maxN][maxN];
// int max(int a, int b) { return a>b?a:b; }
// int main() {
//     #ifdef local
//         freopen("in", "r", stdin);
//     #endif
//     scanf("%d", &n);
//     for (int i=1;i<=n;i++)
//         scanf("%d", qs+i), dp[i][i]=qs[i]*n;
//     for (int len=1;len<n;len++) // 區間長度
//         for (int i=1;i<n;i++) { // 枚舉起點
//             int j=len+i; // 終點
//             dp[i][j]=max(dp[i+1][j]+qs[i]*(n-len), dp[i][j-1]+qs[j]*(n-len));
//         }
//     printf("%d\n", dp[1][n]);
// }