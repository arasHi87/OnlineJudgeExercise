#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=1e5+10;
int n, mx, qs[maxN];
bool chk(int x) {
    int sum=0;
    for (int i=0;i<n;i++)
        sum+=n-(lower_bound(qs+i+1, qs+n, qs[i]+x)-qs);
    return sum>mx;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        for (int i=0;i<n;i++)
            scanf("%d", qs+i);
        sort(qs, qs+n);
        int L=0, R=1e9+10, mid, ans;
        mx=n*(n-1)>>2;
        while (L<=R) {
            mid=(L+R)>>1;
            if (chk(mid)) ans=mid, L=mid+1;
            else R=mid-1;
        }
        printf("%d\n", ans);
    }
}