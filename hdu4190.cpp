#include <cmath>
#include <cstdio>
using namespace std;
const int maxN=5e5+10;
int n, m, qs[maxN];
bool chk(int x) {
    int sum=0;
    for (int i=1;i<=n;i++)
        sum+=ceil(qs[i]*1.0/x);
    return sum<=m;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m) && n!=-1 && m!=-1) {
        for (int i=1;i<=n;i++)
            scanf("%d", qs+i);
        int L=0, R=0x3f3f3f3f, mid;
        while (L<=R) {
            mid=(L+R)>>1;
            if (chk(mid)) R=mid-1;
            else L=mid+1;
        }
        printf("%d\n", L);
    }
}