#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

long long dp[105][105];
int path[105][105];
int mp[105][105];

inline void print(int a[][15], int m, int n) {
    printf("de:=========\n");
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++)
            printf("%d ", a[i][j]);
        puts("");
    }
    printf("de:=========\n");
}

int main() {
    int m, n;
    while (~scanf("%d%d", &m, &n)) {
        // memset(dp, __LONG_LONG_MAX__, sizeof dp);
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                scanf("%d", &mp[i][j]);
        // print(mp, m, n);
        long long ans=__LONG_LONG_MAX__;
        int ft=0;
        for (int j=n;j>=1;j--) {
            for (int i=1;i<=m;i++) {
                if (j==n) dp[i][j]=mp[i][j];
                else {
                    int row[3]={i-1, i, i+1};
                    if (i==1) row[0]=m;
                    if (i==m) row[2]=1;
                    sort(row, row+3);
                    dp[i][j]=__LONG_LONG_MAX__;
                    for (int k=0;k<3;k++) {
                        long long v=(long long)mp[i][j]+dp[row[k]][j+1];
                        if (v<dp[i][j]) {
                            dp[i][j]=v;
                            // printf("de:%lld\n", dp[i][j]);
                            path[i][j]=row[k];
                        }
                    }
                }
                if (j==1 && dp[i][j]<ans) {
                    ans=dp[i][j];
                    ft=i;
                }
            }
        }
        // print(path, m, n);
        printf("%d", ft);
        for (int i=1;i<n;i++) {
            printf(" %d", path[ft][i]);
            ft=path[ft][i];
        }
        printf("\n%lld\n", ans);
    }
}