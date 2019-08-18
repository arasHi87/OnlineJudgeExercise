#include <cstdio>
#include <cstring>
using namespace std;
const int maxN=1e4+10;
int n, idx, isPrim[maxN], qs[maxN];
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    memset(isPrim, 1, sizeof isPrim);
    isPrim[0]=isPrim[1]=0;
    for (int i=2;i<=maxN;i++) {
        if (isPrim[i]) {
            for (int j=i+i;j<=maxN;j+=i)
                isPrim[j]=0;
        }
    }
    for (int i=1;i<=maxN;i++)
        if (isPrim[i]) qs[++idx]=i;
    while (~scanf("%d", &n) && n) {
        int L=1, R=1, sum=0, ans=0;
        while (L<=n) {
            while (sum<n) sum+=qs[R++];
            if (sum==n) ans++;
            sum-=qs[L++];
        }
        printf("%d\n", ans);
    }
}