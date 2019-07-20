#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 500;
int L[maxn][maxn], R[maxn][maxn], dp[maxn][maxn], t[maxn], m1,m2, d1[maxn], d2[maxn], n, T;
int main()
{
    int ca = 1;
    while(~scanf("%d", &n), n)
    {
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        memset(t,0,sizeof(t));
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        scanf("%d", &T);
        for(int i = 2; i <= n; i++)
            scanf("%d", &t[i]);
        scanf("%d", &m1);
        for(int i = 0; i < m1; i++)
            scanf("%d", &d1[i]);
        scanf("%d", &m2);
        for(int i = 0; i < m2; i++)
            scanf("%d", &d2[i]);
        for(int i = 0; i < m1; i++)
        {
            int cur = d1[i];
            for(int j = 1; j <= n; j++)
            {
                cur += t[j];
                R[cur][j] = 1;
            }
        }
        for(int i = 0; i < m2; i++)
        {
            int cur = d2[i];
            for(int j = n; j >= 1; j--)
            {
                cur += t[j+1];
                L[cur][j] = 1;
            }
        }
        dp[T][n] = 0;
        for(int i = T - 1; i >= 0; i--)
        {
            for(int j = n; j >= 1; j--)
            {
                dp[i][j] = dp[i+1][j] + 1;
                if(R[i][j])
                    dp[i][j] = min(dp[i][j], dp[i+t[j+1]][j+1]);
                if(L[i][j])
                    dp[i][j] = min(dp[i][j], dp[i+t[j]][j-1]);
            }
        }
        printf("Case Number %d: ", ca++);
        if(dp[0][1] >= T) puts("impossible");
        else printf("%d\n", dp[0][1]);
    }
    return 0;
}