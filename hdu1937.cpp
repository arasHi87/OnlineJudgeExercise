#include <cstdio>
#include <cstring>
#define mem(x) memset(x, 0, sizeof x);
#define DE_ARRAY(N, M, T) for (int i=1;i<=N;i++) { for (int j=1;j<=M;j++) { printf("%d ", T[i][j]); } puts(""); }
using namespace std;
const int maxN=3e2+10;
const int INF=0x3f3f3f3f;
char opt[maxN];
int R, C, K;
int mp[maxN][maxN], sum[maxN][maxN];
inline int min(int a, int b) { return a<b?a:b; }
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d%d", &R, &C, &K) && (R+C+K)) {
        for (int i=1;i<=R;i++) {
            scanf("%s", opt);
            for (int j=1;j<=C;j++) {
                mp[i][j]=(opt[j-1]=='.'?1:0);
                sum[i][j]=mp[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            }
        }
        // DE_ARRAY(R, C, mp);
        int ans=INF;
        for (int i=1;i<=R;i++) {
            for (int j=i;j<=R;j++) {
                for (int k=1, m=1;k<=C;k++) {
                    while (sum[j][m]-sum[j][k-1]-sum[i-1][m]+sum[i-1][k-1]<K && m<C) m++;
                    if (sum[j][m]-sum[j][k-1]-sum[i-1][m]+sum[i-1][k-1]>=K)
                        ans=min(ans, (j-i+1)*(m-k+1)); 
                }
            }
        }
        printf("%d\n", ans);
    }
}