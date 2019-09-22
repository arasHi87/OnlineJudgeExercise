#include <string>
#include <iostream>
#include <algorithm>
#define IO ios::sync_with_stdio(false), cin.tie(0);
using namespace std;
const int maxN=4e3+10;
int n, m, k, tmp, gcd, dp[maxN][maxN];
string s, p;
inline int max(int a, int b) { return a>b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    IO;
    cin>>s>>p;
    n=s.length(), m=p.length(), k=max(n, m);
    s=' '+s, p=' '+p;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            dp[i][j]=(s[i]==p[j] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]));
            tmp=max(tmp, dp[i][j]);
        }
    }
    tmp<<=1;
    if (!tmp || !(n+m)) return printf("%d/%d\n", tmp, n+m), 0;
    gcd=__gcd(tmp, n+m);
    printf("%d/%d\n", tmp/gcd, (n+m)/gcd);
}