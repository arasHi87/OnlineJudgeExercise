#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxN=20;

LL dp[maxN][maxN], ans;
char s[maxN];
int n;

inline int change(char c) {
    if (isdigit(c)) return c-'0';
    if (isalpha(c)) return c-'A'+10;
}

inline void init() {
    if (s[1]=='?') {
        for (int i=1;i<=n;i++)
            dp[1][i]=1;
    } else {
        dp[1][change(s[1])]=1;
    }
}

void d() {
    for (int i=2;i<=n;i++) {
        if (s[i]=='?') {
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    if (abs(k-j)>1)
                        dp[i][j]+=dp[i-1][k];
        } else {
            int cur=change(s[i]);
            for (int k=1;k<=n;k++)
                if (abs(k-cur)>1)
                    dp[i][cur]+=dp[i-1][k];
        }
    }
}

inline void print() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++)
            printf("%lld ", dp[i][j]);
        puts("");
    }
}

int main() {
    while (scanf("%s", s+1)!=EOF) {
        memset(dp, 0, sizeof dp);
        n=strlen(s+1);
        init(), d();
        ans=0;
        for (int i=1;i<=n;i++)
            ans+=dp[n][i];
        printf("%lld\n", ans);
    }
}