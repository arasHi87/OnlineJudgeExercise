#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN=5e4+10;
int l, n, m, qs[maxN];
bool chk(int x) {
    int k=0, cnt=0;
    for (int i=1;i<=n+1;i++)
        if (qs[i]-qs[k]<x) cnt++;
        else k=i;
    return cnt<=m;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    scanf("%d%d%d", &l, &n, &m);
    for (int i=1;i<=n;i++)
        scanf("%d", qs+i);
    qs[n+1]=l;
    sort(qs+1, qs+2+n);
    int L=0, R=1e9+7, mid, ans;
    while (L<=R) {
        mid=(L+R)>>1;
        if (chk(mid)) ans=mid, L=mid+1;
        else R=mid-1;
    }
    printf("%d\n", ans);
}